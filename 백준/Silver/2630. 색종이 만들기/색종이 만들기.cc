#include <bits/stdc++.h>
using namespace std;

int graph[200][200];
int blueCnt;
int whiteCnt;

void fun(int startX, int startY, int size) {
    
    int cnt = 0;
    for(int i=startX;i<startX+size;i++) {
        for(int j=startY;j<startY+size;j++) {
            if(graph[i][j] == 1) cnt ++;
        }
    }
    // printf("[%d][%d][%d][%d]\n", startX,startY,size, cnt);
    if(cnt == size*size || cnt == 0) {
        if(graph[startX][startY] == 1) blueCnt++;
        else whiteCnt++;
    }
    else {
        fun(startX, startY, size/2);
        fun(startX + (size/2), startY, size/2);
        fun(startX, startY + (size/2), size/2);
        fun(startX + (size/2), startY + (size/2), size/2);
    }
}

int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> graph[i][j];
        }
    }
    fun(0,0,n);
    cout << whiteCnt << "\n" << blueCnt;
}