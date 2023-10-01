#include <bits/stdc++.h>
using namespace std;
vector<int> abj[10001];
int visitedDfs[100001];
int visitedBfs[100001];
void dfs(int k){
    cout << k << " ";
    visitedDfs[k] = 1;
    for(int i : abj[k]) {
        if(!visitedDfs[i]){
            dfs(i); 
        }
    }
    return;
}
void bfs(int k) {
    queue<int> Q;
    Q.push(k);
    visitedBfs[k] = 1;
    while(!Q.empty()) {
        int k = Q.front();
        Q.pop();
        cout << k << " ";
        for(int i : abj[k]) {
            if(!visitedBfs[i]) {
                visitedBfs[i] = 1;
                Q.push(i);
            }
        }
    }
}
int main(){
    int n,m,k; cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        abj[a].push_back(b);
        abj[b].push_back(a);
        sort(abj[a].begin(), abj[a].end());
        sort(abj[b].begin(), abj[b].end());
    }
    dfs(k);
    cout << "\n";   
    bfs(k);
}