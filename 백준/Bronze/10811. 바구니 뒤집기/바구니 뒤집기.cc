#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++){
       v.push_back(i);
    }
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        reverse(v.begin()+a-1,v.begin()+b);
    }
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
}