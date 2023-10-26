#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        int a=0,b=0,c=0,d=0;

        a += num / 25;
        num = num % 25;

        b += num / 10;
        num = num % 10;

        c += num / 5;
        num = num % 5;

        d += num / 1;
        num = num % 1;
        cout << a << " " << b << " " << c << " " << d << "\n";
    }
}