#include <bits/stdc++.h>
using namespace std;
int arr[2000000];
int main(){
    int result = -100000;
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    for(int i=1;i<=n;i++){
        int a; cin >> a;
        arr[i] = arr[i-1] + a; 
    }
    for(int i=k;i<=n;i++){
        result = max(result, arr[i]-arr[i-k]);
    }
    cout << result;
}