#include <bits/stdc++.h>
using namespace std;
int main(){
    map<int,int> m1;
    map<int,int> m2;
    int ntot=0,mtot=0;
    int n,m; cin >> n >> m;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        m1.insert({a,1});
    }
    for(int i=0;i<m;i++){
        int a; cin >> a;
        m2.insert({a,1});
    }
    for(auto it = m1.begin(); it!=m1.end();it++){
        if(m2.find(it->first)->second == 1){
            n--;
        }
    }
    for(auto it = m2.begin(); it!=m2.end();it++){
        if(m1.find(it->first)->second == 1){
            m--;
        }
    }
    cout << n+m;
}