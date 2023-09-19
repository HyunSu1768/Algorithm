#include <bits/stdc++.h>
using namespace std;

int a[100001], arr[100001];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m; 
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        arr[i] = arr[i-1] + a[i];
    }
    for(int i=0;i<m;i++){
        int k,j;
        cin >> k >> j;
        cout << arr[j] - arr[k-1] << "\n";
    }
}