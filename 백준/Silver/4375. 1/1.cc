#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    while(scanf("%d",&n) != EOF) {
        int cnt = 1, ret = 1;
        while(1) {
            if(cnt % n == 0 ){
                cout << ret << "\n";
                break;
            }
            else {
                cnt = cnt * 10 +1;
                cnt %= n;
                ret ++;
            }
        }
    }
}