#include <bits/stdc++.h>
using namespace std;
int n,m;

queue<pair<int,int>> JunanQ;
queue<pair<int,int>> HumanQ;

int visited[302][302];
char graph[302][302];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int flag;

void bfs(){
    while(!JunanQ.empty()) {
        int x = JunanQ.front().first;
        int y = JunanQ.front().second;
        JunanQ.pop();
        for(int dir=0;dir<4;dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || ny < 0 || nx > n || ny > m || visited[nx][ny]) continue;
            if(graph[nx][ny] == '0') {
                JunanQ.push({nx,ny});
                visited[nx][ny] = 1;
            }
            if(graph[nx][ny] == '1') {
                HumanQ.push({nx,ny});
            }
            if(graph[nx][ny] == '#') {
                flag = 1;
            }
        }
    }
}
int a,b,c,d;
void test(){
    memset(visited,0,sizeof(visited));
    JunanQ.push({a-1,b-1});
    bfs();
    while(!HumanQ.empty()) {
        pair<int,int> node = HumanQ.front();
        HumanQ.pop();
        graph[node.first][node.second] = '0';
    }
}

int main(){
    cin >> n >> m;

    cin >> a >> b >> c >> d;

    for(int i=0;i<n;i++) {
        string a; cin >> a;
        for(int j=0;j<m;j++) {
            graph[i][j] = a[j];
        }
    }

    int result = 0;

    while(!flag) {
        result ++;
        test();
    }
    cout << result;
}