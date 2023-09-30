#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100001];
int parent[100001];
void find(int from, int pre){
    parent[from] = pre;

    for(int i=0;i<graph[from].size();i++){
        int next = graph[from][i];
        if(pre == next) continue;
        find(next, from);
    }
}

int main(){
    int n; cin >> n;
    for(int i=0;i<n-1;i++){
        int start, end; cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    find(1,0);
    for(int i=2;i<=n;i++){
        cout << parent[i] << "\n";
    }
}