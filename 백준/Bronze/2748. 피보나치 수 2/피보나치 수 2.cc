#include <bits/stdc++.h>
using namespace std;

long long arr[91] = {0,1};
int main(){
    for(int i=2;i<=90;i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    int n; cin >> n;
    cout << arr[n];
}