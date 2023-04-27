#include <stdio.h>
int main()
{
    int h,m,t;
    scanf("%d %d %d",&h,&m,&t);
    printf("%d %d",(h+(m+t)/60)%24,(m+t)%60);
}