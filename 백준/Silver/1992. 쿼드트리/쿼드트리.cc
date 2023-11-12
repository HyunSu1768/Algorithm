#include <bits/stdc++.h>
using namespace std;

int graph[65][65];

void go(int size, int startX, int startY) {
    int flag = 0;
    for(int i = startX; i<startX+size;i++){
        for(int j=startY; j<startY+size;j++){
            if(graph[i][j] == 1) flag += 1;
        }
    }
    if(flag == size*size) {
        cout << "1";
    }
    else if(flag) {
        size /= 2;
        cout << "(";
        go(size, startX, startY);
        go(size, startX, startY+size);
        go(size, startX+size, startY);
        go(size, startX+size, startY+size);
        cout << ")";
    }
    else {
        cout << "0";
    }
}

int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++){
        string a; cin >> a;
        for(int j=0;j<n;j++){
            graph[i][j] = a[j]-'0';
        }
    }
    go(n, 0,0);
}