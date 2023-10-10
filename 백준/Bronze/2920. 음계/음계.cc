#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> asc {1,2,3,4,5,6,7,8};
    vector<int> des {8,7,6,5,4,3,2,1};
    vector<int> result;
    for(int i=1;i<=8;i++){
        int a; cin >> a;
        result.push_back(a);
    }
    if(result == asc) {
        cout << "ascending";
    }
    else if(result == des) {
        cout << "descending";
    }
    else {
        cout << "mixed";
    }
}