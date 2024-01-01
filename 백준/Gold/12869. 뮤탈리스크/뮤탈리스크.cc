#include <bits/stdc++.h>
using namespace std;
int damage[6][3] = {
    {9,3,1},
    {9,1,3},
    {3,9,1},
    {3,1,9},
    {1,3,9},
    {1,9,3}
};
int visited[65][65][65];
struct A {
    int x,y,z;
};
queue<A> Q;
int input[3];

int main() {
    int n; cin >> n;
    for(int i=0;i<n;i++){
        cin >> input[i];
    }
    Q.push({input[0],input[1],input[2]});
    visited[input[0]][input[1]][input[2]] = 1;
    while(!Q.empty()) {
        int x = Q.front().x;
        int y = Q.front().y;
        int z = Q.front().z;
        Q.pop();
        if(x==0 && y ==0 && z==0) {
            cout << visited[x][y][z] - 1;
            return 0;
        }
        for(int dir=0;dir<6;dir++) {
            int nx = max(0, x - damage[dir][0]);
            int ny = max(0, y - damage[dir][1]);
            int nz = max(0, z - damage[dir][2]);
            if(visited[nx][ny][nz]) continue;
            Q.push({nx,ny,nz});
            visited[nx][ny][nz] = visited[x][y][z]+1;
        }
    }
}