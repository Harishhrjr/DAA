#include<stdio.h>
int main(){
int sum=0,n;
printf("Enter the value of n");
scanf("%d", &n);
for(int i=1;i<=n;i++){
sum=sum+(i*i*i);
}
printf("The sum of the n numbers are:%d\n", sum);


return 0;
}
