#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> vec;
    vector<int> vec_repl;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        vec.push_back(num);
        vec_repl.push_back(num);
    }
    sort(vec_repl.begin(), vec_repl.end());
    reverse(vec_repl.begin(), vec_repl.end());
    prev_permutation(vec.begin(), vec.end());
    if(vec_repl == vec) cout << "-1";
    else for(int a : vec) cout << a << " ";
    
}