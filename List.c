
/*
 时间：Created by mark on 2019/1/1.
 功能：实现一个链表，创建，遍历，判空，求长度，排序，插入，删除功能
 目的：练习链表，指针
 运行环境：Xcode 8.3.2
 */

#include <stdio.h>
#include <stdbool.h>   //添加头文件支持bool类型
#include <mm_malloc.h>

typedef struct Node{
    int data;
    struct Node* pNext;
}*pNODE, NODE;    //pNODE等价于struct Node*; Node等价于struct Node;


pNODE create_list(void);
void traverse_list(pNODE pHead);
bool is_empty(pNODE pHead);
int length_list(pNODE pHead);
bool insert_list(pNODE pHead);
bool delete_list(pNODE pHead, int * pVal);
void sort_list(pNODE pHead);

int main(void) {
   
    pNODE pHead = create_list();
    traverse_list(pHead);
    printf("链表的长度是: %d\n", length_list(pHead));
    
    if( insert_list(pHead) )
        traverse_list(pHead);
    else
        printf("插入失败！\n");
    
    int val;
    if( delete_list(pHead, &val) )
        printf("删除成功，删除的元素是：%d\n", val);
    else
        printf("删除失败！\n");
    traverse_list(pHead);
    
    sort_list( pHead );
    traverse_list(pHead);
    
    return 0;
}




//创建链表，返回头节点pHead
pNODE create_list(void){

    int len; //有效链表长度
    int val; //节点数据
    
    pNODE pHead = (pNODE)malloc(sizeof(NODE));   //开辟一个头结点
    if( pHead == NULL){
        printf("分配失败,程序结束！\n");
        exit(-1);
    }
    
    pNODE pTail = pHead;    //创建一个尾节点用来代替头结点pHead随着新建节点移动，最后返回pHead即可
    pTail->pNext = NULL;
    
    printf("请输入要创建的节点个数 len = ");
    scanf("%d", &len);

    for(int i = 0; i < len; i++){
    
        printf("请输入要创建的第%d个节点的值：", i+1);
        scanf("%d", &val);
        pNODE pNew = (pNODE)malloc(sizeof(NODE));
        if( pNew == NULL ){
            printf("分配失败，请重新输入！");
            exit(-1);
        }
        
        pNew->data = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }
    
    return pHead;
}

//遍历链表
void traverse_list(pNODE pHead){
    
    pNODE p = pHead->pNext;
    
    printf("\n");
    printf("链表节点是：");
    while(p != NULL){
        printf("%d  ", p->data);
        p = p->pNext;
    }
    printf("\n");
    
    return;
}

//链表判空
bool is_empty(pNODE pHead){

    if(pHead == NULL)
        return true;
    else
        return false;
}

//返回链表的长度
int length_list(pNODE pHead){
    
    int len = 0;
    pNODE p = pHead->pNext;
    while(p != NULL){
        p = p->pNext;
        len++;
    }
    return len;
}

//在链表pos节点位置前插入插入val值节点，pos从1开始,返回插入成功还是失败
bool insert_list(pNODE pHead){

    int pos, val;
    printf("要插入的位置是：");
    scanf("%d", &pos);
    printf("要插入的值是：");
    scanf("%d", &val);
    
    pNODE p = pHead;
    int i = 0;
    while(p != NULL && i < pos - 1){   //找到pos前面一个节点
        p = p->pNext;
        i++;
    }
    if(i > pos - 1 || p == NULL)
        return false;
    
    pNODE pNew = (pNODE)malloc(sizeof(NODE));
    if(pNew == NULL){
        printf("内存分配失败，程序退出！");
        exit(-1);
    }
    pNew->data = val;
    pNew->pNext = p->pNext;
    p->pNext = pNew;
    
    return true;
}

//在链表删除第pos个节点，并返回该节点的值
bool delete_list(pNODE pHead, int * pVal){
    
    int pos, i = 0;
    printf("要删除的位置是：");
    scanf("%d", &pos);
    
    pNODE p = pHead;
    while(p != NULL && i < pos - 1 ){    //找到pos前面一个节点，赋值给p
        p = p->pNext;
        i++;
    }
    if( i > pos - 1 || p == NULL)
        return false;
    
    *pVal = p->pNext->data;
    p->pNext = p->pNext->pNext;
    
    pNODE pDel = p->pNext;       //pDel指向待删除的节点,释放删除节点的内存
    free(pDel);
    pDel = NULL;
    
    return true;
}


//冒泡排序
void sort_list(pNODE pHead){
    
    //int len = length_list(pHead);
    pNODE p,q;
    
    for(p = pHead->pNext; p != NULL; p = p->pNext){
        for(q = p->pNext; q != NULL; q = q->pNext){
            
            if( p->data > q->data ){
            
                int tem = p->data;
                p->data = q->data;
                q->data = tem;
            }
        }
    }
}





