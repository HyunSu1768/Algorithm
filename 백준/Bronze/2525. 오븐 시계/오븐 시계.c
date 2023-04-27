#include <stdio.h>
int main(){
    int h,m; scanf("%d %d",&h,&m);
    int n; scanf("%d",&n);
    printf("%d %d",((h+(m+n)/60)%24),(m+n)%60);
}