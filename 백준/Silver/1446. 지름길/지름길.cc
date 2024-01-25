#include <bits/stdc++.h>
using namespace std;
int n,m;
struct A
{
    int destination;
    int dist;
};
vector<A> vec[10004];
int result = 987654321;
int visited[10004];
void go(int x, int dist) {
    if(x == m) {
        result = min(result, dist);
        return;
    }
    if(x+1 > m) return;
    go(x+1, dist+1);
    if(!vec[x].empty()) {
        for(A info : vec[x]) {
            go(info.destination, dist + info.dist);
        }
    }
    return;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        int a,b,c; cin >> a >> b >> c;
        A info;
        info.destination = b;
        info.dist = c;
        vec[a].push_back(info);
    }
    visited[0] = 1;
    go(0,0);
    cout << result;
}