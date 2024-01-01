#include <iostream>
#include <queue>
#include <string>
using namespace std;
char graph[1001][1001];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
queue<pair<int,int>> JQ;
queue<pair<int,int>> FQ;
int visitJ[1001][1001];
int visitF[1001][1001];
int visitedJ[1001][1001];
int visitedF[1001][1001];
int main(){
    int n,m; cin >> n >> m;
    for(int i=0;i<n;i++){
        string a; cin >> a;
        for(int j=0;j<m;j++){
            graph[i][j]=a[j];
            visitF[i][j]=1001;
            if(graph[i][j]=='J'){
                JQ.push({i,j});
                visitJ[i][j]=0;
                visitedJ[i][j]=1;
            }
            if(graph[i][j]=='F'){
                FQ.push({i,j});
                visitF[i][j]=0;
                visitedF[i][j]=1;
            }
        }
    }
    while(!FQ.empty()){
        int x = FQ.front().first;
        int y = FQ.front().second;
        FQ.pop();
        for(int dir=0;dir<4;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx>=0 && nx<n && ny>=0 && ny<m && graph[nx][ny]!='#' && visitedF[nx][ny]==0){
                if(visitF[nx][ny]>visitF[x][y]+1){
                    FQ.push({nx,ny});
                    visitF[nx][ny]=visitF[x][y]+1;
                    visitedF[nx][ny]=1;
                }
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << visitF[i][j] << " " ;
    //     }
    //     cout << "\n";
    // }
    while(!JQ.empty()){
        int x = JQ.front().first;
        int y = JQ.front().second;
        JQ.pop();
        for(int dir=0;dir<4;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx>=n || ny>=m || nx<0 || ny<0){
                cout << visitJ[x][y]+1;
                return 0;
            }
            if(nx>=0 && nx<n && ny>=0 && ny<m && graph[nx][ny]!='#' && visitedJ[nx][ny]==0){
                if(visitJ[x][y]+1 <visitF[nx][ny]){
                    JQ.push({nx,ny});
                    visitedJ[nx][ny]=1;
                    visitJ[nx][ny]=visitJ[x][y]+1;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}