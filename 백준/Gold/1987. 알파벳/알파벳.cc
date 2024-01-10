#include <bits/stdc++.h>
using namespace std;

int n,m;
char graph[22][22];
int visited[22][22];
int alpha[1000];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int result;
void dfs(int x, int y, int dist) {
    
    result = max(result, dist);
    for(int dir=0;dir<4;dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny]) continue;
        if(alpha[graph[nx][ny]]) continue;
        visited[nx][ny] = 1;
        alpha[graph[nx][ny]] = 1;
        dfs(nx,ny,dist+1);
        visited[nx][ny] = 0;
        alpha[graph[nx][ny]] = 0;
    }
    return;
}

int main(){
    cin >> n >> m;
    
    for(int i=0;i<n;i++) {
        string a; cin >> a;
        for(int j=0;j<m;j++) {
            graph[i][j] = a[j];
        }
    }
    visited[0][0] = 1;
    alpha[graph[0][0]] = 1;
    dfs(0,0,1);
    cout << result;
}