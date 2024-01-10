#include <bits/stdc++.h>
using namespace std;
char board[1000][1000];
int checkS[1000][1000];
int checkF[1000][1000];
queue<pair<int,int>> Qs;
queue<pair<int,int>> Qf;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main(){
    int t; cin>>t;
    while(t--){
        Qs = queue<pair<int,int>>();
        Qf = queue<pair<int,int>>();
        memset(checkF,-1,sizeof(checkF));
        memset(checkS,-1,sizeof(checkS));
        int n,m; cin >> m >> n;
        for(int i=0;i<n;i++){
            string a; cin >> a;
            for(int j=0;j<m;j++){
                board[i][j]=a[j];
                if(board[i][j]=='@'){
                    Qs.push({i,j});
                    checkS[i][j]=0;
                }
                if(board[i][j]=='*'){
                    Qf.push({i,j});
                    checkF[i][j]=0;
                }
            }
        }
        // 불 BFS 먼저
        while(!Qf.empty()){
            int x = Qf.front().first;
            int y = Qf.front().second; Qf.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=n || ny>=m || ny<0 || nx < 0) continue;
                if(board[nx][ny]=='#' || checkF[nx][ny]>=0) continue;
                Qf.push({nx,ny}); 
                checkF[nx][ny]=checkF[x][y]+1;
                }
        }
        int flag=0;
        while(!Qs.empty()){
            int x = Qs.front().first;
            int y = Qs.front().second; Qs.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=n || ny>=m || nx<0 || ny<0){
                cout << checkS[x][y]+1 << "\n";
                flag=1;
                }
                if(flag) break;
                if(checkS[nx][ny]>=0 || board[nx][ny]!='.') continue;
                if(checkF[nx][ny]!=-1 && checkS[x][y]+1 >=checkF[nx][ny]) continue;
                Qs.push({nx,ny});
                checkS[nx][ny]=checkS[x][y]+1;
                }
        }
        if(!flag) cout << "IMPOSSIBLE\n";
    }
}