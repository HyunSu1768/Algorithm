#include <bits/stdc++.h>
using namespace std;

int n;

int result;

vector<pair<int,int>> vec[100001];
int visited[100001];
int maxNode;

void go(int node, int dist) {
    if(result < dist) {
        result = max(result, dist);
        maxNode = node;
    }
    
    for(pair<int,int> i : vec[node]) {
        if(!visited[i.first]) {
            visited[i.first] = 1;
            go(i.first, dist + i.second);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++) {
        int node; cin >> node;
        int a,b;
        while(1) {
            cin >> a;
            if(a == -1) break;
            cin >> b;
            vec[node].push_back({a,b}); 
        }
    }
    visited[1] = 1;
    go(1,0);
    memset(visited,0,sizeof(visited));
    visited[maxNode] = 1;
    go(maxNode, 0);
    
    cout << result;
}