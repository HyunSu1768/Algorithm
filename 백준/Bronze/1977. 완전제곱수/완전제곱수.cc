#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin >> n >> m;
    int result = 0;
    int min = 100000;
    for(int i=n;i<=m;i++) {
        for(int j=1;j<=i;j++) {
            if(j*j == i) {
                if(i < min) {
                    min = i;
                }
                result += i;
            }
        }
    }
    if(result) {
        cout << result << "\n" << min;
    }
    else {
        cout << "-1";
    }
}