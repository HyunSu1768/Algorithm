#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n,m;
int board[101][101];
int check[101][101];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int cnt;
int cnt2;
int result;
int removeCheese(){
    cnt++;
    int cnt2=0;
    queue<pair<int,int>> Q;
    Q.push({0,0});
    check[0][0]=1;
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second; Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !check[nx][ny]){
                if(board[nx][ny]==1){
                    board[nx][ny]=0;
                    cnt2++;
                }
                else if(board[nx][ny]==0){
                    Q.push({nx,ny});
                }
                check[nx][ny]=1;
            }
        }
    }
    if(cnt2==0){
        cout << --cnt << "\n" << result;
        return 1;
    }else{
        result = cnt2;
        return false;
    }
    
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);  
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }
    while(1){
        if(removeCheese()) break;
        memset(check,0,sizeof(check));  
    }
    return 0;
}