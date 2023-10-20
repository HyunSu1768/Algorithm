#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++){   
        int t; cin >> t;
        string result;
        long long max = -1;
        for(int j=0;j<t;j++){
        string a,b; cin >> a >> b;
        int value = stoi(a);
        if(value > max) {
            max = value;
            result = b;
        }
        }
        cout << result << "\n";
    }
}