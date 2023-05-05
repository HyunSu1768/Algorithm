#include <bits/stdc++.h>
using namespace std;
int main(){

    long long S; cin >> S;
    long long sum = 1;
    long long num = 0;
    int cnt=0;
    while(1){
        num = num + sum;
        cnt++;
        if(num>S){
            cnt--;
            break;
        }
        sum++;
    }
    
    cout << cnt;
}