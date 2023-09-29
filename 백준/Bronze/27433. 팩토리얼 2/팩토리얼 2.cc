#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll factory(ll n) {
    if(n==1) return n;
    if(n==0) return 1;
    return n * factory(n-1);
}

int main(){
    ll n; cin >> n;
    cout << factory(n);
}