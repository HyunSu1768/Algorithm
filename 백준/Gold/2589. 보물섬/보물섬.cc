#include <bits/stdc++.h>
using namespace std;
int n,m;
char graph[51][51];
int checked[51][51];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int bfs(int x, int y){
    int max = -1;
    memset(checked, 0, sizeof(checked));
    checked[x][y]=1;
    queue<pair<int,int>> Q;
    Q.push({x,y});
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx<0 || nx>n || ny<0 || ny>m) continue;
            if(graph[nx][ny] == 'L' && checked[nx][ny]==0){
                Q.push({nx,ny});
                checked[nx][ny] = checked[x][y]+1;
                if(checked[nx][ny] >max){
                    max = checked[nx][ny];
                }
            }
        }
    }
    return max;
}

int main(){
    int checkAll[51][51]={0};
    int result = -1;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string a; cin >> a;
        for(int j=0;j<m;j++){
            graph[i][j] = a[j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]=='L' && checkAll[i][j]==0){
                int max = bfs(i, j);
                if(result<max){
                    result = max;
                }
            }
        }
    }
    cout << result-1 << "\n";
    
}
