#include <bits/stdc++.h>
using namespace std;
int n;

int graph[11][11];
int visited[11][11];

int result = 987654321;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int check(int x,int y) {
    if(visited[x][y]) return 0;
    for(int dir=0;dir<4;dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) {
            return 0;
        }
    }
    return 1;
}

int setFlower(int x,int y) {
    int price = graph[x][y];
    visited[x][y] = 1;
    for(int dir=0;dir<4;dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        price += graph[nx][ny];
        visited[nx][ny] = 1;
    }
    return price;
}

void eraseFlower(int x, int y) {
    visited[x][y] = 0;
    for(int dir=0;dir<4;dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        visited[nx][ny] = 0;
    }
}

void go(int price, int cnt) {
    if(cnt == 3) {
        result = min(result, price);
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(check(i,j)) {
                go(price + setFlower(i,j), cnt + 1);
                eraseFlower(i,j);
            }
        }
    }
}

int main(){
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> graph[i][j];
        }
    }
    go(0,0);
    
    cout << result;
}