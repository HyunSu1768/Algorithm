#include <bits/stdc++.h>
using namespace std;
vector<int> vec[1000];
int result = 0;
int visited[1000];

int main() {
    
    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    visited[1] = 1;
    queue<pair<int,int>> Q;
    Q.push({1,0});
    while(!Q.empty()) {
        int x = Q.front().first;
        int level = Q.front().second;
        Q.pop();
        for(int i : vec[x]) {
            if(!visited[i] && level+1 <= 2) {
                visited[i]=1;
                result++;
                Q.push({i,level+1});
            }
        }
    }
    cout << result;
}