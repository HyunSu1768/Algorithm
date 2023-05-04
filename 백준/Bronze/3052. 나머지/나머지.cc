#include <stdio.h>
int arr[42];
int main(){
    int sum,b=0;
    for(int i=0;i<10;i++){
        scanf("%d",&sum);
        arr[sum%42]=1;
    } 
    for(int i=0;i<42;i++){
        b+=arr[i];
    }
    printf("%d",b);
}