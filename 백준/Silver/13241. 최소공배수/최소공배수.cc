#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcm(ll a, ll b) {
    ll r = a % b;
    if(r==0) {
        return b; 
    }
    a = b;
    b = r;
    return gcm(a,b);   
}

ll lcm(ll a, ll b) {
    return a*b/gcm(a,b);
}
int main(){
    ll n,m; cin >> n >> m;
    cout << lcm(n,m);
    return 0;
}