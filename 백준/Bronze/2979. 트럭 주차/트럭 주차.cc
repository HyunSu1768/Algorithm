#include <bits/stdc++.h>
using namespace std;
int timeA[100];
int main(){
    int sum = 0;
    int a,b,c;
    cin >> a >> b >> c;
    for(int i=0;i<3;i++){
        int k,j;
        cin >> k >> j;
        for(int p=k;p<j;p++){
            timeA[p]++;
        }
    }
    for(int i=0;i<100;i++){
        switch (timeA[i])
        {
        case 1:
        sum += timeA[i] * a;
            break;
        case 2:
        sum += timeA[i] * b;
            break;
        case 3:
        sum += timeA[i] * c;
            break;
        default:
            break;
        }
        
    }
    cout << sum;
}