#include <bits/stdc++.h>
using namespace std;

int n, m;
char graph[52][52];
int visited[52][52], dp[52][52];

void dfs(int x, int y) {
    if (dp[x][y]) return;
    dp[x][y] = visited[x][y] = 1;

    int num = graph[x][y] - '0';
    for(pair<int,int> i : {make_pair(x+num, y), make_pair(x, y+num), make_pair(x, y-num), make_pair(x-num, y)}) {
        int nx = i.second;
        int ny = i.first;
        if(graph[ny][nx] == 'H' || nx < 0 || ny < 0 || nx >= m || ny >= n) {
            continue;
        }
        if(visited[ny][nx]) {
            cout << "-1";
            exit(0);
        }
        dfs(ny,nx);
        dp[x][y] = max(dp[x][y], dp[ny][nx] + 1);
    }
    visited[x][y] = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        string a; cin >> a;
        for(int j=0;j<m;j++) {
            graph[i][j] = a[j];
        }
    }
    dfs(0,0);
    cout << dp[0][0];
}
