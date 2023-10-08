#include <bits/stdc++.h>
using namespace std;
vector<int> vec[1001];
int startP, endP;
int visited[1001];
void dfs(int num, int pre) {
    visited[num] = 1;
    if(num == endP) {
        cout << pre;
        exit(0);
    }
    for(int i : vec[num]) {
        if(!visited[i]) {
            dfs(i, pre+1);
        }
    }
}
int main(){
    int n; cin >> n;
    cin >> startP >> endP;
    int t; cin >> t;
    for(int i=0;i<t;i++){
        int a,b; cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs(startP, 0);
    cout << "-1";
}