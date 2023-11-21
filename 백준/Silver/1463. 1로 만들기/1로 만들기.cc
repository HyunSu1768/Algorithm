#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> vec(n+1);
    vec[1] = 0;
    for(int i=2;i<=n;i++){
        vec[i] = vec[i-1] + 1;
        if(i%2==0) vec[i] = min(vec[i],vec[i/2]+1);
        if(i%3==0) vec[i] = min(vec[i],vec[i/3]+1);
    }
    cout << vec[n];
}