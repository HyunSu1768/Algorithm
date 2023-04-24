#include <bits/stdc++.h>
using namespace std;
int board[1001][1001];
int check[1001][1001];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int main(){
    queue<pair<int,int>> Q;
    int n,m; cin >> n >> m;
    for(int i=0;i<n;i++){
        string a; cin >> a;
        for(int j=0;j<m;j++){
            board[i][j] = a[j]-'0';
        }   
    }

    for(int i=0;i<1;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==0 && !check[i][j]){
                Q.push({i,j});
                check[i][j]=1;
                while(!Q.empty()){
                    int x = Q.front().first;
                    int y = Q.front().second; Q.pop();
                    if(x==n-1){
                        cout << "YES";
                        return 0;
                    }
                    // cout << x << " " << y << "\n";
                    for(int dir=0;dir<4;dir++){
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if(nx >=0 && nx<n && ny>=0 && ny<m){
                            if(!check[nx][ny] && board[nx][ny]==0){
                                Q.push({nx,ny});
                                check[nx][ny]=1;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "NO";
}