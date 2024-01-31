#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int result = 0;
    for(int i=0;i<7;i++) {
        if(n & (1 << i)) result++;
    }
    cout << result;
}