#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int total=0;
    for(int i=0;i<9;i++){
        int n; cin >> n;
        total += n;
    }
    cout << n-total;
}