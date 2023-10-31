#include <bits/stdc++.h>
using namespace std;

int first[45001];
int second[45001];
int gcd(int a,int b) {
    while(1) {
        int r = a%b;
        if(r==0) {
            return b;
        }
        a = b;
        b = r;
    }
}
int lcm(int a, int b) {
    return a*b/gcd(a,b);
}
int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        cout << lcm(a,b) << "\n";
    }
}
