#include <bits/stdc++.h>
using namespace std;

int visited[203][203];
int graph[203][203];

int dx[] = {-2,-2,0,0,2,2};
int dy[] = {-1,1,-2,2,-1,1};

int main() {
    int n; cin >> n;
    int a,b,c,d; cin >> a >> b >> c >> d;

    queue<pair<int,int>> Q;
    Q.push({a,b});
    while(!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        if(x == c && y == d) {
            cout << visited[x][y];
            exit(0);
        }
        Q.pop();
        for(int dir=0;dir<6;dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx >=0 && nx <n && ny>=0 && ny < n) {
                if(!visited[nx][ny]) {
                    visited[nx][ny] = visited[x][y] + 1;
                    Q.push({nx,ny});
                }
            }
        }
    }
    cout << "-1";
}