#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int arr[1000001];
int main(){
    int n; cin >> n;
    map<int,int> ma;
    for(int i = 0;i<n;i++){
        int a; cin >> a;
        vec.push_back(a);
        arr[i] = a;
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    int cnt = 0 ;
    for(int i : vec) {
        ma[i] = cnt;
        cnt ++;
    }
    for(int i=0;i<n;i++){
        cout << ma[arr[i]] << " ";
    }
}