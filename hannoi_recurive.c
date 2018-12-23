#include<stdio.h>

void hannoi(int n, int* pSum, char from, char buff, char to){

  
  if(n == 1){
    printf("move %d disk from %c to %c\n", n, from, to);
    (*pSum)++;
  }
  else{
    hannoi(n-1, pSum, from, to, buff);
    printf("move %d disk from %c to %c\n", n, from, to);
    hannoi(n-1, pSum, buff, from, to);
    (*pSum)++;
  }
}

int main(){

    int n;
    int sum = 0;
    printf("please input the number to move:");
    scanf("%d",&n);

    hannoi(n, &sum, 'A', 'B', 'C');  //move disk from A to C by using B;
    
    printf("the disk we need to move are:%d\n", sum);

    return 0;

}
