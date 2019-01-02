
/*
 时间：Created by mark on 2019/1/2.
 功能：实现一个循环队列，初始化，入队，出队，遍历，判空，判满功能
 目的：练习循环队列，基于数组实现
 运行环境：Xcode 8.3.2
 */

#include <stdio.h>
#include <stdbool.h>   //添加头文件支持bool类型
#include <mm_malloc.h>


//对列，只能在两端进行操操纵，rear尾增,front头删
typedef struct Queue{
    int* pBase;
    int front;
    int rear;
}Queue, *pQueue;

int init(pQueue pQ);
bool is_full(pQueue pQ, int len);
bool en_Queue(pQueue pQ, int len);
bool is_empty(pQueue pQ);
void traverse(pQueue pQ, int len);
bool out_queue(pQueue pQ, int* pVal, int len);


int main(void) {
   
    
    Queue q;
    int len = init(&q);
    
    int n;
    printf("要插入几个值：");
    scanf("%d", &n);
    if(n > len){
        printf("输入个数超过队大小！");
    }
    for(int i = 0; i < n; i++){
    
        en_Queue(&q, n);
    }
    
    traverse(&q, len);
    
    int val;
    out_queue(&q, &val, len);
    printf("出队的值是：%d\n", val);
    
    traverse(&q, n);
    
    return 0;
}


//初始化,返回队列大小
int init(pQueue pQ){

    int len;
    printf("输入要开辟多大空间的队列：");
    scanf("%d",&len);
    
    pQ->pBase = (int*)malloc(sizeof(int)*(len + 1));
    pQ->rear = 0;
    pQ->front = pQ->rear;
    
    return len;
}

//判满
bool is_full(pQueue pQ, int len){
    
    if((pQ->rear + 1) % (len+1) == pQ->front)
        return true;
    else
        return false;
}

//入队,参数是队指针，入队元素，队列长度
bool en_Queue(pQueue pQ, int len){

    if( is_full(pQ,len) ){
        printf("队满，入队失败\n");
        return false;
    }
    
    int val;
    printf("要入队的值是：");
    scanf("%d", &val);
    
    pQ->pBase[pQ->rear] = val;
    pQ->rear = (pQ->rear + 1) % (len+1);
    
    return true;
}

//判空
bool is_empty(pQueue pQ){

    if(pQ->front == pQ->rear)
        return true;
    else
        return false;
}


//从前到后遍历队列
void traverse(pQueue pQ, int len){

    
    if( is_empty(pQ) ){
        printf("队为空！\n");
        exit(-1);
    }
    
    int i = pQ->front;   //从头遍历到尾
    
    printf("队列从前到后是：");
    while(i != pQ->rear){
        
        printf("%d  ", pQ->pBase[i]);
        i = (i+1) % (len + 1);
    }
    printf("\n");
    
}

//出队
bool out_queue(pQueue pQ, int* pVal, int len){

    if( is_empty(pQ) ){
        printf("队空！");
        return false;
    }
    
    *pVal = pQ->pBase[pQ->front];
    pQ->front = (pQ->front + 1) % (len + 1);
    
    return true;
    
}




