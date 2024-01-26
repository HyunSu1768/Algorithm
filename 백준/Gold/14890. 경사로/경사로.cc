#include <bits/stdc++.h>
using namespace std;
int n,l;
int map1[102][102];
int map2[102][102];
int result = 0;
void solve(int graph[102][102]){
    for(int i=0;i<n;i++) {
        int cnt = 1;
        int j;
        for(j=0;j<n-1;j++) {
            if(graph[i][j] == graph[i][j+1]) cnt++;
            else if(graph[i][j] + 1 == graph[i][j+1] && cnt >= l) cnt = 1;
            else if(graph[i][j] - 1 == graph[i][j+1] && cnt >= 0) cnt = -l + 1;
            else break;
        }
        if(j == n-1 && cnt >= 0) {
            result ++;
        }
    }
    return;
}
int main(){
    cin >> n >> l;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int num; cin >> num;
            map1[i][j] = num;
            map2[j][i] = num;
        }
    }
    solve(map1);
    solve(map2);
    cout << result;
}