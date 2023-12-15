#include <bits/stdc++.h>
using namespace std;
int a[1000004];
int ret[1000004];

int main() {
    stack<int> stk;
    int n; cin >> n;
    memset(ret, -1, sizeof(ret));
    for(int i=0;i<n;i++) {
        cin >> a[i];
        while(!stk.empty() && a[stk.top()] < a[i]) {
            ret[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }
    for(int i=0;i<n;i++){
        cout << ret[i] << " ";
    }
}