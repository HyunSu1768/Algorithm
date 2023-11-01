#include <bits/stdc++.h>
using namespace std;

int gcm(int n, int m) {
    while(1) {
        int r = n%m;
        if(r==0) {
            return m;
        }
        n = m;
        m = r;
    }
}

int lcm(int n,int m) {
    return n*m/gcm(n,m);
}
int main(){
    int n,m;cin >> n >> m;
    cout << gcm(n,m) << "\n";
    cout << lcm(n,m);
}