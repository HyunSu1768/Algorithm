#include <bits/stdc++.h>
using namespace std;

vector<char> tree[1000];
char visited[1000];
char direction[1000];

void forward(char node) {
    cout << node;
    for(char i : tree[node]) {
        if(!visited[i]) {
            visited[i] = 1;
            forward(i);
        }
    }
}

void inorder(char node) {
    if(!visited[node]) {
        if(tree[node].size() == 1) {
            if(direction[tree[node][0]] == 0 ) {
                inorder(tree[node][0]);
                visited[node] = 1;
                cout << node ;
            }
            else {
                visited[node] = 1;
                cout << node ;
                inorder(tree[node][0]);
            }
            
        }
        else if(tree[node].size() == 2) {
            inorder(tree[node][0]);
            visited[node] = 1;
            cout << node;
            
            inorder(tree[node][1]);
        }
        else {
            visited[node] = 1;
            cout << node;
        }
    }
}

void postorder(char node) {
    if(!visited[node]) {
        if(tree[node].size() == 1) {
            postorder(tree[node][0]);
        }
        else if(tree[node].size() == 2) {
            postorder(tree[node][0]);
            postorder(tree[node][1]);
        }
        visited[node] = 1;
        cout << node;
    }
}

int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++) {
        char a,b,c; cin >> a >> b >> c;
        if(b != '.') {
            tree[a].push_back(b);
            direction[b] = 0;
        }
        if(c != '.') {
            tree[a].push_back(c);
            direction[c] = 1;
        }
    }
    forward('A');
    memset(visited, false, sizeof(visited));
    cout << "\n";
    inorder('A');
    memset(visited, false, sizeof(visited));
    cout << "\n";
    postorder('A');
}