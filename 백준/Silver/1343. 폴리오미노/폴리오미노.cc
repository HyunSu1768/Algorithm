#include <bits/stdc++.h>
using namespace std;

int main() {
    string a; cin >> a;
    while(a.find("XXXX") != string::npos) {
        a.replace(a.find("XXXX"), 4, "AAAA");
    }
    while(a.find("XX") != string::npos) {
        a.replace(a.find("XX"), 2, "BB");
    }
    for(char i : a) {
        if(i == 'X') {
            cout << "-1";
            exit(0);
        }
    }
    cout << a;
}