#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m; cin >> n >> m;
    queue<pair<ll,string>> Q;
    map<ll,ll> ma;
    if(n == m) {
        cout << "0";
        exit(0);
    }
    Q.push({n,""});
    while(!Q.empty()) {
        ll num = Q.front().first;
        string answer = Q.front().second;
        if(num == m) {
            cout << answer;
            return 0;
        }
        Q.pop();
        if(!ma[num*num]){
            Q.push({num * num, answer+"*"});
            ma[num*num] = 1;
        }
        if(!ma[num*2]) {
            Q.push({num + num, answer+"+"});
            ma[num*2] = 1;
        }
        if(!ma[num/num]) {
            Q.push({num / num, answer+"/"});
            ma[num/num] = 1;
        }
        
    }
    cout << "-1";
}