#include <bits/stdc++.h>
using namespace std;
int arr[101];
int main(){
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++){
        arr[i]=0;
    }
    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        for(int j=a;j<=b;j++){
            arr[j]=c;
        }
    }
    for(int i=1;i<=n;i++){
        cout << arr[i] << " ";
    }
}