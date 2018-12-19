//
//  main.c
//  DataStruct_code
//
//  Created by mark on 2018/12/19.
//  Copyright © 2018年 mark. All rights reserved.
//

#include<stdio.h>
#include <stdbool.h>   //添加头文件支持bool类型
#include<malloc.h>
#include<stdlib.h>     //use the exit() function


struct Array{
    int* pBase;     //the first element pointer of array
    int len;        //the length of array
    int cnt;        //the current valid element
};

void init_arr(struct Array* pArr, int length);
bool append_arr(struct Array* pArr, int val);

//insert_arr
//delete_arr
void show_arr(struct Array* pArr);
bool is_empty(struct Array* pArr);
bool is_full(struct Array* pArr);
//sort_arr
//inversion_arr

int main(void){
    
    struct Array arr;
    init_arr(&arr, 6);
    append_arr(&arr, 1);
    append_arr(&arr, 2);
    append_arr(&arr, 3);
    
    show_arr(&arr);
    
    return 0;
}

void init_arr(struct Array* pArr, int length){
    
    pArr->pBase = (int *)malloc(sizeof(int)*length);
    if(NULL == pArr->pBase){
        printf("initional error!\n");
        exit(-1);
    }
    else{
        pArr->len = length;
        pArr->cnt = 0;
    }
}

bool is_empty(struct Array* pArr){
    if(pArr->cnt == 0)
        return true;
    else
        return false;
}

bool is_full(struct Array* pArr){
    if( pArr->len == pArr->cnt)
        return true;
    else
        return false;
}

void show_arr(struct Array* pArr){
    if( is_empty(pArr) )
        printf("the array is empty");
    
    for(int i = 0;i < pArr->cnt;i++)
        printf("%d ", pArr->pBase[i]);
    
    printf("\n");
}

bool append_arr(struct Array* pArr, int val){
    if( is_full(pArr) )
        printf("the array is full");
    
    pArr->pBase[pArr->cnt] = val;
    pArr->cnt++;
    
    return true;
}
