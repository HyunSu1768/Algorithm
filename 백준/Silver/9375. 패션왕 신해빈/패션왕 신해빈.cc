#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    while(n--) {
        int result = 1;
        int a; cin >> a; 
        map<string, int> ma;
        for(int i=0;i<a;i++){
            string element, kind;
            cin >> element >> kind;
            ma[kind]++;
        }
        for(auto& i : ma) {
            result *= i.second+1;
        }
        cout << result - 1 << "\n";
    }
}