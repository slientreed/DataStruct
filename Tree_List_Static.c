
/*
 时间：Created by mark on 2019/1/4.
 功能：实现一个静态链式二叉树，功能简单实现二叉树的创建，先中后三种遍历；（后序要改进，动态创建）
 目的：练习树的创建和遍历，加深对树的认识，理解
 运行环境：Xcode 8.3.2
 */

#include <stdio.h>
#include <stdbool.h>   //添加头文件支持bool类型
#include <mm_malloc.h>

typedef struct BTNode{
    
    char data;
    struct BTNode* pLchild;
    struct BTNode* pRchild;
}T, *pT;

struct BTNode* CreateBTree(void);
void PreTraverseBTree(struct BTNode * pT);
void InTraverseBTree(struct BTNode * pT);
void PostTraverseBTree(struct BTNode * pT);

int main(void) {
   
    pT pTree = CreateBTree();
    
    printf("树的先序遍历是：");
    PreTraverseBTree(pTree);
    printf("\n");
    
    printf("树的中序遍历是：");
    InTraverseBTree(pTree);
    printf("\n");
    
    printf("树的后序遍历是：");
    PostTraverseBTree(pTree);
    printf("\n");
    
    
    return 0;
}


//静态手动创建树节点
struct BTNode* CreateBTree(void){

    pT pA = (pT)malloc(sizeof(T));
    pT pB = (pT)malloc(sizeof(T));
    pT pC = (pT)malloc(sizeof(T));
    pT pD = (pT)malloc(sizeof(T));
    pT pE = (pT)malloc(sizeof(T));
    pT pF = (pT)malloc(sizeof(T));
    
    
    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';
    pF->data = 'F';
    
    pA->pLchild = pB;
    pA->pRchild = pC;
    pB->pLchild = pD;
    pB->pRchild = NULL;
    pC->pLchild = NULL;
    pC->pRchild = pE;
    pD->pLchild = NULL;
    pD->pRchild = pF;
    pE->pLchild = pE->pRchild = NULL;
    pF->pLchild = pF->pRchild = NULL;
    
    return pA;   //返回root节点
    
}

//先序遍历
void PreTraverseBTree(struct BTNode * pT){

    if (pT != NULL){
        printf("%c ", pT->data);
        
        if( pT->pLchild != NULL)
            PreTraverseBTree(pT->pLchild);
        
        if( pT->pRchild != NULL )
            PreTraverseBTree(pT->pRchild);
    }
}

//中序遍历
void InTraverseBTree(struct BTNode * pT){

    if (pT != NULL){
        
        if( pT->pLchild != NULL)
            InTraverseBTree(pT->pLchild);
        
        printf("%c ", pT->data);
        
        if( pT->pRchild != NULL )
            InTraverseBTree(pT->pRchild);
    }

}

//后序遍历
void PostTraverseBTree(struct BTNode * pT){
    
    if (pT != NULL){
        
        if( pT->pLchild != NULL)
            PostTraverseBTree(pT->pLchild);
        
        if( pT->pRchild != NULL )
            PostTraverseBTree(pT->pRchild);
        
        printf("%c ", pT->data);
    }
    
}

