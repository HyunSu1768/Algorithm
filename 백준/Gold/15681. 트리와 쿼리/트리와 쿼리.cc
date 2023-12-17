#include <bits/stdc++.h>
using namespace std;
vector<int> vec[100001];
int result[100001];
int visited[100001];
int dfs(int start) {
    result[start] = 1;
    for(int i : vec[start]) {
        if(visited[i]) continue;
        visited[i] = 1;
        result[start] += dfs(i);
    }
    return result[start];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,v;
    cin >> n >> m >> v;
    for(int i=0;i<n-1;i++) {
        int a,b; cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    visited[m] = 1;
    dfs(m);
    for(int i=0;i<v;i++) {
        int num; cin >> num;
        cout << result[num] << "\n";
    }
}