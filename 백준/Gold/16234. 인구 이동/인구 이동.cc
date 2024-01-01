#include <bits/stdc++.h>
using namespace std;
int n,l,r;
int graph[51][51];
int visited[51][51];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<pair<int,int>> vec;
int sum = 0;
void dfs(int x, int y) {
    for(int dir=0;dir<4;dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx >=0 && ny >=0 && nx < n && ny < n) {
            if(visited[nx][ny]) continue;
            int distance = abs(graph[x][y] - graph[nx][ny]);
            if(l <= distance && distance <= r) {
                vec.push_back({nx,ny});
                sum += graph[nx][ny];
                visited[nx][ny] = 1;
                dfs(nx,ny);
            }
        }
    }
}
int main() {
    cin >> n >> l >> r;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> graph[i][j];
        }
    }
    int cnt = 0;
    while(1) {
        int flag = 0;
        memset(visited,0, sizeof(visited));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]) {
                    vec.clear();
                    vec.push_back({i,j});
                    visited[i][j] = 1;
                    sum = graph[i][j];
                    dfs(i,j);
                    if(vec.size() == 1)continue;
                    for(pair<int,int> v : vec) {
                        graph[v.first][v.second] = sum / vec.size();
                        flag = 1;
                    }
                }
            }
        }
        if(!flag) {
            break;
        }
        cnt++;
    }
    cout << cnt;
}