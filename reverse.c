#include<stdio.h>
int main(){
    int x,rev=0,rem;
    printf("enter the value of x");
    scanf("%d",&x);
    for(;x!=0;x =x/10){
        rem=x%10;
        rev=rev*10+rem;
    }
    printf("reversed number=%d",rev);
    return 0;
}

    