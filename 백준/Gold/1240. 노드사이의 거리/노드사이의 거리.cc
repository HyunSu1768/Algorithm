#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> vec[1001];
int visited[1001];
int main() {
    int n,m; cin >> n >> m;
    for(int i=0;i<n-1;i++) {
        int a,b,c; cin >> a >> b >> c;
        vec[a].push_back({b,c});
        vec[b].push_back({a,c});
    }
    queue<pair<int,int>> Q;
    for(int i=0;i<m;i++) {
        int a,b; cin >> a >> b;
        Q.push({a,0});
        while(!Q.empty()) {
            int pos = Q.front().first;
            int dist = Q.front().second;
            Q.pop();
            if(pos == b) {
                cout << dist << "\n";
                break;
            }
            for(pair<int,int> p : vec[pos]) {
                if(!visited[p.first]) {
                    Q.push({p.first, dist + p.second});
                    visited[p.first] = 1;
                }
            }
        }
        memset(visited, 0, sizeof(visited));
        while(!Q.empty()) Q.pop();
    }
}