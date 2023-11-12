#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int result = 0;
    int appleCount; cin >> appleCount;
    int l,r;
    l = 1;
    for(int i=0;i<appleCount;i++){
        int num; cin >> num;
        r = l + m - 1;
        if(num >= l && num <= r) continue;
        if(r < num) {
            result += num - r;
            l += num-r;
        } else {
            result += l-num;
            l = num;
        }
    }
    cout << result;
}