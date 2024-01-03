#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> vec[20];
int n; 
int result = 0;
void go(int index, int _sum) {
    for(int i = index; i<n;i++) {
        int dist = vec[i].front().first;
        int benefit = vec[i].front().second;
        if(i+dist <= n) {
            result = max(result, _sum+benefit);
            go(i+dist, _sum+benefit);
        }
    }
    return;
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        int a,b; cin >> a >> b;
        vec[i].push_back({a,b});
    }

    go(0,0);
    cout << result ;
}