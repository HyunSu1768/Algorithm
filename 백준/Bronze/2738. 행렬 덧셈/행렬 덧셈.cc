#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
int arr2[101][101];
int main(){
    int n,m; cin >> n >> m;
    for(int i=0;i<n;i++){
            for(int k=0;k<m;k++){
                int a; cin >> a;
                arr[i][k] = a;
            }
        }
        for(int i=0;i<n;i++){
            for(int k=0;k<m;k++){
                int a; cin >> a;
                arr2[i][k] = a;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << arr[i][j] + arr2[i][j]<< " ";
            }
            cout << "\n";
        }
}