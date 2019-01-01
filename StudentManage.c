/*
 时间：Created by mark on 2019/1/1.
 功能：输入学生信息，并按照成绩排序从小到大输出
 目的：练习C语言的函数，结构体，指针等
 运行环境：Xcode
 */

#include <stdio.h>

struct Student{
    int age;
    float score;
    char name[10];
};

//输入学生信息
void Input_info(struct Student* p, int len){
    
    for(int i = 0; i < len; i++){
        printf("请输入第%d个学生的信息\n",i+1);
        printf("age = ");
        scanf("%d", &p[i].age);
        
        printf("name= ");
        scanf("%s", p[i].name);   //name是数组名，本身已经是数组首元素的地址了，不用再加&符号
        
        printf("score = ");
        scanf("%f", &p[i].score);
    }
}

//输出学生信息
void Output_info(struct Student* p, int len){
    for(int i = 0; i < len; i++){
        printf("第%d个学生的信息:\n",i+1);
        printf("age = %d ; ", p[i].age);
        printf("name = %s;  ", p[i].name);
        printf("score = %f; ", p[i].score);
        printf("\n");
    }
}

//对结构体成绩变量进行冒泡排序
void Bubble_sort(struct Student* p, int len){

    for(int i = 0; i < len; i++){
        for(int j = i+1; j < len - 1 -i; j++){
            if(p[i].score > p[j+1].score){
                struct Student s = p[i];
                p[i] = p[j+1];
                p[j+1] = s;
                
            }
        }
    }
    
}

int main(void) {
   
    int len;
    struct Student* pStu;
    
    printf("please the number of student: ");
    scanf("%d", &len);
    pStu = (struct Student*)malloc(len * sizeof(struct Student));
    Input_info(pStu, len);
    Bubble_sort(pStu, len);
    Output_info(pStu, len);
    
    return 0;
}
