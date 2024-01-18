#include <bits/stdc++.h>
using namespace std;

int visited[2][500002];

int main(){
    int n,m; cin >> n >> m;
    queue<int> Q;
    Q.push(n);
    if(n==m) {
        cout << "0"; return 0;
    }
    int turn = 1;
    int ok = 0;
    while(!Q.empty()) {
        m += turn;
        if(m > 500000) break;
        if(visited[turn%2][m]) {
            ok = 1;
            break;
        }
        int qsize = Q.size();
        for(int i=0;i<qsize;i++) {
            int x = Q.front(); Q.pop();
            for(int nx : {x-1,x+1,x*2}) {
                if(nx < 0 || nx > 500000 || visited[turn%2][nx]) continue;
                visited[turn%2][nx] = 1;
                if(nx == m) {
                    ok = 1;
                    break;
                }
                if(ok) break;
                Q.push(nx);
            }
        }
        if(ok) break;
        turn++;
    }
    if(ok) {
        cout << turn;
    }
    else cout << "-1";
}