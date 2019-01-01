
/*
 时间：Created by mark on 2019/1/1.
 功能：实现一个栈，初始化，入栈，出栈，遍历，判空，清空功能
 目的：练习 栈，指针
 运行环境：Xcode 8.3.2
 */

#include <stdio.h>
#include <stdbool.h>   //添加头文件支持bool类型
#include <mm_malloc.h>

typedef struct Node{
    int data;
    struct Node* pNext;
}NODE, *pNODE;

typedef struct Stack{
    pNODE pTop;
    pNODE pBottom;
}STACK, *pSTACK;


void init(pSTACK ps);
void push(pSTACK ps);
void traverse(pSTACK ps);
bool is_empty(pSTACK ps);
bool pop(pSTACK ps, int *pVal);
void Clear(pSTACK ps);

int main(void) {
   
    STACK s;
    init(&s);
    
    int n;
    printf("要想入栈几个元素：");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        push(&s);
    }
    traverse(&s);
    
    printf("要出栈几个元素：");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int val;
        if( pop(&s, &val) )
            printf("第%d个出栈元素是：%d\n", i+1, val);
        else
            printf("栈为空，出栈失败！\n");
    }
    
    Clear(&s);
    if( is_empty(&s) ){
        printf("栈已空\n");
    }
    
    return 0;
}

//初始化栈，pTop指向栈顶，第一个有效元素；pBottom指向栈底，无效节点
void init(pSTACK ps){

    ps->pTop = (pNODE)malloc(sizeof(NODE));
    (*ps).pBottom = ps->pTop;           //栈底指向一个无效的数据，有利于后序操作
    ps->pTop->pNext = NULL;             //栈顶指向第一个有效节点
}

//入栈，pTop指向顶部第一个有效元素
void push(pSTACK ps){
    
    pNODE pNew = (pNODE)malloc(sizeof(NODE));
    
    int val;
    printf("输入要入栈的值：");
    scanf("%d", &val);
    
    pNew->data = val;
    pNew->pNext = ps->pTop;
    ps->pTop = pNew;
    
    return;
}

//遍历栈，按照输入从后到先输出
void traverse(pSTACK ps){

    pNODE p = ps->pTop;
    
    printf("栈是：");
    while(p != ps->pBottom ){
        printf("%d  ", p->data);
        p = p->pNext;
    }
    printf("\n");
    
    return;
}

bool is_empty(pSTACK ps){

    if( ps->pTop == ps->pBottom )
        return true;
    else
        return false;
}


//出栈
bool pop(pSTACK ps, int *pVal){

    if( is_empty(ps) )
        return false;
    
    pNODE p = ps->pTop;
    *pVal = p->data;
    ps->pTop = p->pNext;
    
    free(p);
    p = NULL;
    return true;
    
}

//清空栈
void Clear(pSTACK ps){
    
    if( is_empty(ps) )
        return;
    
    pNODE p = ps->pTop;
    pNODE q = NULL;        //暂存节点，便于free
    
    while( p != ps->pBottom ){   //释放所有节点的内存，注意不要内存泄漏
        q = p->pNext;
        free(p);
        p = q;
    }
    
    ps->pTop = ps->pBottom;
}







