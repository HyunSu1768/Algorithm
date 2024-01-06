#include <bits/stdc++.h>
using namespace std;

int n,m;
int visited[100002];
int cases[100002];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    
    queue<int> Q;
    Q.push(n);
    visited[n] = 1;
    cases[n] = 1;
    while(!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for(int i : {x+1, x-1, x*2}) {
            if(i >=0 && i<=100000) {    
                if(!visited[i]) {
                    visited[i] = visited[x]+1;
                    cases[i] += cases[x];
                    Q.push(i);
                }
                else if(visited[i] == visited[x]+1){
                    cases[i] += cases[x];
                }
            }
        }
    }
    cout << visited[m]-1 << "\n" << cases[m];
}