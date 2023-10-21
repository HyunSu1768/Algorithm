#include <bits/stdc++.h>
using namespace std;

struct point {
    int x;
    int y;
};

point home;

point festival;

point store[100];

int visited[1000];

int n; 

int bfs(int x, int y) {
    queue<pair<int,int>> Q;
    Q.push({x,y});
    while(!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        if(abs(festival.x - x) + abs(festival.y - y) <= 1000) {
            return 1;
        }
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            if(abs(store[i].x - x) + abs(store[i].y - y) <= 1000) {
                visited[i] = 1;
                Q.push({store[i].x, store[i].y});
            }
        }
    }
    return false;
}

int main(){
    int t; cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        cin >> home.x >> home.y;
        for(int k=0;k<n;k++){
            cin >> store[k].x >> store[k].y;
        }
        cin >> festival.x >> festival.y;
        int result = bfs(home.x, home.y);
        if(result) {
            cout << "happy\n";
        }
        else {
            cout << "sad\n";
        }
        memset(visited, 0, sizeof(visited));
    }


}