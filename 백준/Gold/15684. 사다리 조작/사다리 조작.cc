#include <bits/stdc++.h>
using namespace std;
int n,m,h;
int visited[32][32];
int check(){
    for(int i=1;i<=n;i++) {
        int start = i;
        for(int j=1;j<=h;j++) {
            if(visited[j][start]) {
                start++;
            }
            else if(visited[j][start-1]) {
                start--;
            }
        }
        if(i != start) return 0;
    }
    return 1;
}
int result = 4;
void go(int x, int size) {
    if(size > 3) {
        return;
    }
    if(check()) {
        result = min(result,size);
        return;
    }
    for(int i = x;i<=h;i++) {
        for(int j=1;j<=n;j++) {
            if(visited[i][j] || visited[i][j-1] || visited[i][j+1]) continue;

            visited[i][j] = 1;
            go(i,size+1);
            visited[i][j] = 0;
        }
    }
    return;
}
int main(){
    cin >> n >> m >> h;
    for(int i=0;i<m;i++) {
        int a,b; cin >> a >> b;
        visited[a][b] = 1;
    }
    go(1,0);
    result == 4 ? cout << "-1" : cout << result;
    
}