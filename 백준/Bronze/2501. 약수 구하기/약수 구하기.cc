#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin >> n >> m;
    int count = 0;
    for(int i=1;i<=n;i++) {
        if(n%i==0) {
            count++;
        }
        if(count==m) {
            cout << i ;
            exit(0);
        }
    }
    cout << "0";
}