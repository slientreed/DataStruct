#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>


struct Array{
    int* pBase;     //the first element pointer of array
    int len;        //the length of array
    int cnt;        //the current valid element
};


void init_arr(struct Array* pArr, int length);
bool append_arr(struct Array* pArr, int val);
bool insert_arr(struct Array* pArr, int pos, int val);
bool delete_arr(struct Array* pArr, int pos, int* pval);  //return the value of delete element
void show_arr(struct Array* pArr);
bool is_empty(struct Array* pArr);
bool is_full(struct Array* pArr);
void sort_arr(struct Array* pArr);
void inversion_arr(struct Array* pArr);

int main(void){
    
    struct Array arr;
    init_arr(&arr, 6);
    append_arr(&arr, 3);
    append_arr(&arr, 2);
    append_arr(&arr, 1);
    show_arr(&arr);
    printf("\n");

    int pos,val;
    printf("the insert pos is: ");
    scanf("%d",&pos);
    printf("input the number to insert: ");
    scanf("%d", &val);
    insert_arr(&arr, pos, val);
    printf("the array after insert is: ");
    show_arr(&arr);
    printf("\n");

    
    printf("the delete pos is: ");
    scanf("%d",&pos);
    delete_arr(&arr, pos, &val);
    printf("the delete value is: %d\n",val);
    printf("the array after delete is: ");
    show_arr(&arr);
    printf("\n");
    
    sort_arr(&arr);
    printf("the sort arr is :");
    show_arr(&arr);
    printf("\n");
    
    inversion_arr(&arr);
    printf("the inversion arr is :");
    show_arr(&arr);
    printf("\n");
    
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
        printf("append error! the array is full");
    
    pArr->pBase[pArr->cnt] = val;
    pArr->cnt++;
    
    return true;
}

bool insert_arr(struct Array* pArr, int pos, int val){
    
    if( is_full(pArr) ){
        printf("insert error! the array is full!\n");
        return false;
    }
    
    if(pos < 1 || pos > pArr->cnt + 1){
        printf("insert error! the insert position is error\n");
        return false;
    }
    
    for(int i = pArr->cnt - 1; i >= pos-1; i--){    //move the element after the insert position
        pArr->pBase[i+1] = pArr->pBase[i];
    }
    pArr->pBase[pos-1] = val;
    pArr->cnt++;
    
    return true;
}

bool delete_arr(struct Array* pArr, int pos, int* pval){
    
    if( is_empty(pArr) ){
        printf("delete error! the array is empty!\n");
        return false;
    }
    
    if( pos < 1 || pos > pArr->cnt){
        printf("delete error! the delete pos is error\n");
        return false;
    }
    
    *pval = pArr->pBase[pos-1];
    for(int i = pos-1; i < pArr->cnt; i++){
        pArr->pBase[i] = pArr->pBase[i+1];
    }
    pArr->cnt--;
    
    return true;
}


void sort_arr(struct Array* pArr){

    int i,j,k;
    for(i = 0; i < pArr->cnt; i++){
        for(j = i+1; j < pArr->cnt; j++){
            
            if( pArr->pBase[i] > pArr->pBase[j] ){      //BubbleSort Ascending order
                k = pArr->pBase[i];
                pArr->pBase[i] = pArr->pBase[j];
                pArr->pBase[j] = k;
            }
        }
    }
}

void inversion_arr(struct Array* pArr){     //use double pointer

    int head = 0;
    int tail = pArr->cnt - 1;
    int val;
    
    while(head < tail){
        val = pArr->pBase[tail];
        pArr->pBase[tail] = pArr->pBase[head];
        pArr->pBase[head] = val;
        head++;
        tail--;
    }
    
    return;
}


