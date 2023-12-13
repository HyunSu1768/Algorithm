#include <bits/stdc++.h>
using namespace std;
int n; 
vector<int> vec;

void deleteNodeF(int a) {
    if(vec[a]==-2) return;
    vec[a] = -2;
    for(int i=0;i<n;i++) {
        if(vec[i] == a) {
            deleteNodeF(i);
        }
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++) {
        int num; cin >> num;
        vec.push_back(num);
    }
    int deleteNode; cin >> deleteNode;
    deleteNodeF(deleteNode);
    int result = 0;
    for(int i=0;i<n;i++) {
        int flag = 0;
        if(vec[i] == -2) continue;
        for(int j=0;j<n;j++) {
            if(vec[j] != -2 && vec[j] == i) {
                flag = 1;
            }
        }
        if(!flag) {
            result ++;
        }
    }
    cout << result;
}