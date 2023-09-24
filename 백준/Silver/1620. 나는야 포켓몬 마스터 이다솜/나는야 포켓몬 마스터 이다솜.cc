#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    map<int, string> ma;
    map<string, int> ma2;
    for(int i=1;i<=n;i++){
        string a; cin >> a;
        ma[i] = a;
        ma2[a] = i;
    }
    for(int i=0;i<m;i++){
        string a; cin >> a;
        if(a[0] >= 'A' && a[0] <= 'Z'){
            cout << ma2.at(a) << "\n";
        }
        else {
            int result = stoi(a);
            cout << ma.at(result) << "\n";
        }
    }
}