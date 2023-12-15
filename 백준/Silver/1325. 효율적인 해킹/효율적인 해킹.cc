#include <bits/stdc++.h>
using namespace std;
vector<int> vec[10004];
int result[10004];
int visited[10004];

int dfs(int here) {
    int ret = 1;
    for(int i : vec[here]) {
        if(visited[i]) continue;
        visited[i] = 1;
        ret += dfs(i);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m; cin >>n >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        vec[b].push_back(a);
    }
    int mx = -1;
    for(int i=1;i<=n;i++) {
        memset(visited, 0, sizeof(visited));
        visited[i] = 1;
        result[i] = dfs(i);
        mx = max(result[i], mx);
    }
    for(int i=1;i<=n;i++) {
        if(result[i] == mx) {
            cout << i << " ";
        }
    }
}