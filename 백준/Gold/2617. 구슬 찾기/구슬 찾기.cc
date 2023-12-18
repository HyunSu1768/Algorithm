#include <bits/stdc++.h>
using namespace std;
vector<int> lightVec[101];
vector<int> heavyVec[101];
bool visited[101];

int lightDfs(int start) {
    int cnt = 0;
    for(int i : lightVec[start]) {
        if(visited[i]) continue;
        visited[i] = true;
        cnt += lightDfs(i) + 1;
    }  
    return cnt;
}

int heavyDfs(int start) {
    int cnt = 0;
    for(int i : heavyVec[start]) {
        if(visited[i]) continue;
        visited[i] = true;
        cnt += heavyDfs(i) + 1;
    }  
    return cnt;
}

int main(){
    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++) {
        int a,b; cin >> a >> b;
        lightVec[b].push_back(a);
        heavyVec[a].push_back(b);
    }
    int answer = 0;
    for(int i=1;i<=n;i++) {
        fill(visited,visited+n+1,false);
        if(lightDfs(i) >= (n+1)/2) answer++;
        fill(visited,visited+n+1,false);
        if(heavyDfs(i) >= (n+1)/2) answer++;
    }
    cout << answer;
}
