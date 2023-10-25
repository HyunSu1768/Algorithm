#include <bits/stdc++.h>
using namespace std;

struct info {
    int x;
    int y;
    int bridge;
};

int n;
int labelCount=0;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int graph[101][101];

int visited[101][101];

void giveLabel(){
    queue<pair<int,int>> Q;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==1 && !visited[i][j]) {
                labelCount++;
                Q.push({i,j});
                while(!Q.empty()) {
                    int x= Q.front().first;
                    int y = Q.front().second;
                    graph[x][y] = labelCount;
                    Q.pop();
                    for(int dir=0;dir<4;dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if(nx>=0 && ny >=0 && nx < n && ny < n) {
                            if(graph[nx][ny]==1 && !visited[nx][ny]) {
                                visited[nx][ny] = 1;
                                Q.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }
    }
    memset(visited, 0, sizeof(visited));
}

int makeBridge(int num){
    queue<info> Q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==num) {
                visited[i][j] = 1;
                Q.push({i,j,0});
            }
        }
    }

    while(!Q.empty()) {
        int x = Q.front().x;
        int y = Q.front().y;
        int bridge = Q.front().bridge;
        Q.pop();

        for(int dir=0;dir<4;dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx >=0 && ny >=0 && nx < n && ny < n) {
                if(graph[nx][ny] && num != graph[nx][ny]) {
                    return bridge;
                }
                if(!graph[nx][ny] && !visited[nx][ny]) {
                    Q.push({nx,ny,bridge+1});
                    visited[nx][ny] = 1;
                }
            }
        }
    }
    return 10000;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> graph[i][j];
        }
    }
    giveLabel();
    int answer = 10000;
    for(int i=1;i<=labelCount;i++) {
        answer = min(answer, makeBridge(i));
        memset(visited, 0, sizeof(visited));
    }
    cout << answer;

}