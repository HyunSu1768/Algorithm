#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    map<string, int> ma;
    ma["ChongChong"] = 1;
    for(int i=0;i<n;i++){
        string a,b; cin >> a >> b;
        if(ma.find(a) == ma.end()) { // 없다면 
            ma[a] = 0;
        } else {
            if(ma[a] == 1) {
                ma[b] = 1;
            }
        }
        if(ma.find(b) == ma.end()) { // 없다면 
            ma[b] = 0;
        } else {
            if(ma[b] == 1) {
                ma[a] = 1;
            }
        }
    }
    int result = 0;
    for(auto i : ma) {
        if(i.second == 1) {
            result++;
        }
    }
    cout << result;
}