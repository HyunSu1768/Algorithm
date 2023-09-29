#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,c;

ll go(ll a, ll b) {
    if(b==1) return a%c;
    ll ret = go(a, b/2);
    ret = (ret * ret) % c;
    if(b % 2) ret = (ret*a) % c;
    return ret;
}
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> c;
    cout << go(n,m);
}