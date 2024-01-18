#include <bits/stdc++.h>
using namespace std;
int n,m,k;
char graph[6][6];
int visited[6][6];
int result;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void go(int x, int y, int dist) {
    if(x == 0 && y == m-1) {
        if(dist == k) {
            result++;
            return;
        }
    }

    for(int dir=0;dir<4;dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || graph[nx][ny] == 'T') continue;
        visited[nx][ny] = 1;
        go(nx,ny,dist+1);
        visited[nx][ny] = 0;
    }

}
int main(){
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        string a; cin >> a;
        for(int j=0;j<m;j++){
            graph[i][j] = a[j];
        }
    }
    visited[n-1][0] = 1;
    go(n-1,0,1);
    cout << result;
}