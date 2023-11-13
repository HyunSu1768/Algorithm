#include <bits/stdc++.h>
using namespace std;
map<int,int> countA;
bool compare(pair<int,int> i, pair<int,int> j){
    if(i.first == j.first) {
        return countA[i.second] < countA[j.second];
    }
    else {
        return i.first > j.first;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m; cin >> n >> m;
    map<int,int> ma;
    for(int i=0;i<n;i++) {
        int num; cin >> num;
        ma[num]++;
        if(countA[num] == 0) {
            countA[num] = i+1;
        }
    }
    vector<pair<int,int>> vec;
    for(auto it : ma) {
        vec.push_back({it.second, it.first});
    }
    sort(vec.begin(), vec.end(), compare);
    for(auto i : vec) {
        for(int j=0;j<i.first;j++){
            cout << i.second << " ";
        }
    }
    
}