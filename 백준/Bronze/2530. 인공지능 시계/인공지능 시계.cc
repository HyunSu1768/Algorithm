#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,m,s; cin >> h >> m >> s;
    int num; cin >> num;

    s += num;   

    m += s/60;
    s%=60;

    h += m/60;
    m %= 60;

    h %= 24;

    cout << h << " " << m << " " << s;
}