#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int result = 1;
        int n,m; cin >> n >> m;
        for(int i=0;i<m;i++){
            result = result * n % 10;
        }
        if(result%10==0){
            cout << "10\n";
        }
        else{
            cout << result%10 << "\n";
        }
    }
}