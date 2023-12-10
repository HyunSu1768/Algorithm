#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int cnt = 0;
    for(int i = 666; cnt != n;i++){
        if(to_string(i).find("666") != string::npos) {
            cnt++;
        }
        if(cnt == n) {
            cout << i;
        }
    }
}