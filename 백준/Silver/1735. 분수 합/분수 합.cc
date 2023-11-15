#include <bits/stdc++.h>
using namespace std;

int gcm(int a, int b) {
    int r = a % b;
    if(r==0) {
        return b;
    }
    a = b;
    b = r;
    return gcm(a,b);
}

int main() {
    int n,m;
    int a,b;
    cin >> n >> m >> a >> b;
    int max = n*b + a*m;
    int down = m*b;
    int min = gcm(max, down);
    max = max/min;
    down = down/min;
    cout << max << " " << down; 
}