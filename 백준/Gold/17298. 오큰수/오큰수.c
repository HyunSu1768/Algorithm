#include <stdio.h>
int stack[1000001];
int top=-1;
void push(int x){
    stack[++top]=x;
}
void pop(){
    stack[top--]=0;
}
int main(){
    int t; scanf("%d",&t);
    int arr[1000001];
    for(int i=0;i<t;i++){
        int num;
        scanf("%d",&num);
        arr[i]=num;
        while(1){
            if(top==-1){
                push(i);
                break;
            }
            int idx=stack[top];
            if(num>arr[idx]){
                arr[idx]=num;
                pop();
            }
            else{
                push(i);
                break;
            }
        }
    }
    while(top!=-1){
        int idx = stack[top];
        arr[idx] = -1;
        pop();
    }
    for(int i=0;i<t;i++){
        printf("%d ",arr[i]);
    }
}