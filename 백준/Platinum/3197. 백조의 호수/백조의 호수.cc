#include <bits/stdc++.h>
using namespace std;

int n,m;
char graph[1501][1501];
bool visited[1501][1501];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int,int>> waterQ, waterQN, swanQ, swanQN;
int swanFind;
pair<int,int> swanPos[2];

void swanBfs(){
    while (!swanQ.empty() && !swanFind)
    {
        int x = swanQ.front().first;
        int y = swanQ.front().second;
        swanQ.pop();
        for(int dir=0;dir<4;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx >=0 && ny >=0 && nx < n && ny < m) {
                if(!visited[nx][ny]) {
                    if(graph[nx][ny] == '.') {
                        swanQ.push({nx,ny});
                        visited[nx][ny] = true;
                    }
                    else if(graph[nx][ny] == 'X') {
                        swanQN.push({nx,ny});
                        visited[nx][ny] = true;
                    }
                    else if(graph[nx][ny] == 'L' && !(nx == swanPos[0].first && ny == swanPos[0].second)) {
                        visited[nx][ny] = true;
                        swanFind = 1;
                        break;
                    }
                }
            }
        }
    }
}

void waterBfs(){
    while(!waterQ.empty()) {
        int x = waterQ.front().first;
        int y = waterQ.front().second;
        waterQ.pop();
        for(int dir=0;dir<4;dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx>=0 && ny >=0 && nx < n && ny < m) {
                if(graph[nx][ny] == 'X') {
                    graph[nx][ny] = '.';
                    waterQN.push({nx,ny});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    
    
    int idx = 0;
    for(int i=0;i<n;i++){
        string a; cin >> a;
        for(int j=0;j<m;j++){
            graph[i][j] = a[j];
            if(graph[i][j] != 'X') {
                waterQ.push({i,j});
            }
            if(graph[i][j] == 'L') {
                swanPos[idx++] = {i,j};
            }
        }
    }

    int answer = 0;
    swanQ.push(swanPos[0]);
    visited[swanPos[0].first][swanPos[0].second] = true;
    while(!swanFind) {
        swanBfs();
        if(!swanFind) {
            waterBfs();
            answer++;
            waterQ = waterQN;
            swanQ = swanQN;
            while(!waterQN.empty()) waterQN.pop();
            while(!swanQN.empty()) swanQN.pop();
        }
    }
    cout << answer;
}