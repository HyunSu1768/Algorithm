#include <bits/stdc++.h>
using namespace std;
int n,m;
int board[8][8];
int tmpboard[8][8];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int c;
void copy(int (*a)[8],int (*b)[8]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j]=b[i][j];
        }
    }
}
void bfs(){
    queue<pair<int,int>> Q;
    int spread[8][8];
    copy(spread,tmpboard);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(spread[i][j]==2){
                Q.push({i,j});
            }
        }
    }
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(spread[nx][ny]==0){
                    spread[nx][ny]=2;
                    Q.push({nx,ny});
                }
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(spread[i][j]==0){
                cnt++;
            }
        }
    }
    c = max(c,cnt);

}
void wall(int cnt){
    if(cnt==3){
        bfs();
        return;
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(tmpboard[i][j]==0){
                    tmpboard[i][j]=1;
                    wall(cnt+1);
                    tmpboard[i][j]=0;
                }
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==0){
                copy(tmpboard,board);
                tmpboard[i][j]=1;
                wall(1);
                tmpboard[i][j]=0;
            }
        }
    }
    cout << c;
}
