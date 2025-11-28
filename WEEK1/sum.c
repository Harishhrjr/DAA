#include<stdio.h>

void sumofdigits(int n){
int sum=0;
for(int i=1;i<n;i++){
sum+=i;
}
printf("The sum of the n numbers are:%d\n", sum);
}

int main(){
sumofdigits(10);
return 0;
}
   
