#include <bits/stdc++.h>
using namespace std;
int arr[140];
int main(){
    int n; cin >> n;
    string base;
    for(int i=0;i<n;i++){
        
        if(i==0) cin >> base;
        else {
            string a; cin >> a;
            for(int j=0;j<a.size();j++){
                if(base[j] != a[j]) {
                    base[j] = '?';
                }
            }
        }
    }
    cout << base;
}