#include <bits/stdc++.h>
using namespace std;
int n,m;
int graph[52][52];

int dy[] = {-1,0,1,0};
int dx[] = {0,-1,0,1};
int visited[52][52];
int maxCnt[100];
// 1 : 서
// 2 : 북
// 4 : 동
// 8 : 남
// 6 : 북 동 
int dfs(int x, int y, int id) {
    int cnt = 1;
    for(int dir=0;dir<4;dir++) {
        if(!(graph[x][y] & (1 << dir))) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || ny < 0 || nx > m || ny > n) continue;
            if(visited[nx][ny]) continue;
            visited[nx][ny] = id;
            cnt += dfs(nx,ny,id);
        }
    }
    return cnt;
}

int main(){
    cin >> n >> m ;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin >> graph[i][j];
        }
    }
    int result1 = 0;
    int result2 = 0;
    int result3 = 0;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(!visited[i][j]) {
                result1 ++;
                visited[i][j] = result1;
                int mx = dfs(i,j, result1);
                result2 = max(mx, result2);
                maxCnt[result1] = mx;
            }
        }
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(i+1 < m) {
                if(visited[i][j] != visited[i+1][j]) {
                    result3 = max(maxCnt[visited[i][j]]+maxCnt[visited[i+1][j]], result3);
                }
            }
            if(j+1 < n) {
                if(visited[i][j] != visited[i][j+1]) {
                    result3 = max(maxCnt[visited[i][j]]+maxCnt[visited[i][j+1]], result3);
                }
            }
        }
    }
    cout << result1 << "\n" << result2 << "\n" << result3;
}