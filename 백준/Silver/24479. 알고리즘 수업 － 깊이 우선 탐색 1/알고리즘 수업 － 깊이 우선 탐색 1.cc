#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int result[100001];
int visited[100001];
int a,b;
int counter = 1;
void dfs(int num){
    result[num] = counter;
    visited[num] = 1;
    counter++;
    for(int i : adj[num]) {
        if(!visited[i]) dfs(i);
    }
}
int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n,m,k; cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(k);
    for(int i=1;i<=n;i++){
        cout << result[i] << "\n";
    }
}