#include <bits/stdc++.h>
using namespace std;

int main(){
    string a; cin >> a;
    string a_reversed (a.rbegin(), a.rend());
    cout << (a==a_reversed);
}