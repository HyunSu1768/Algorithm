#include <bits/stdc++.h>
using namespace std;
int n,m, visited[2][500003];
int main(){
    cin >> n >> m;
    queue<int> Q;
    Q.push(n);
    visited[0][n] = 1;
    if(n==m) {
        cout << "0";
        return 0;
    }
    int b=m;
    int turn = 1;
    int ok = 0;
    while(!Q.empty()) {
        b += turn;
        if(b > 500000) break;
        if(visited[turn%2][b]) {
            ok = 1;
            break;
        }
        int qsize = Q.size();
        for(int i=0;i<qsize;i++) {
            int x = Q.front();
            Q.pop();
            
            for(int nx : {x-1,x+1,x*2}) {
                if(nx < 0 || nx > 500000 || visited[turn%2][nx]) continue;
                visited[turn%2][nx] = 1;
                if(nx == b) {
                    ok = 1; break;
                }
                Q.push(nx);
            }
            if(ok) break;
        }
        if(ok) break;
        turn++;
    }
    if(ok) {
        cout << turn << "\n";
    }
    else {
        cout <<"-1";
    }
}