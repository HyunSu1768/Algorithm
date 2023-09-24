#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> vec;
    vector<int> vec_repl;
    int n; cin >> n;

    for(int i=0;i<n;i++){
        int a; cin >> a;
        vec.push_back(a);
        vec_repl.push_back(a);
    }
    sort(vec_repl.begin(), vec_repl.end());
    next_permutation(vec.begin(), vec.end());
    if(vec == vec_repl){
        cout << "-1";
        exit(0);
    }
    for(int a : vec){
        cout << a << " ";
    }
}