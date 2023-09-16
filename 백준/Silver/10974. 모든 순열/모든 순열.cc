#include <bits/stdc++.h>
using namespace std;

int main(){

    int a;
    cin >> a;
    vector<int> vec;
    for(int i=1; i<=a;i++){
        vec.push_back(i);
    }
    do {
        for(int i : vec) {
            cout << i << " ";
        }
        cout << "\n";
    } while(next_permutation(vec.begin(), vec.end()));

}