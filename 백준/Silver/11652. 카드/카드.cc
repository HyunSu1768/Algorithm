#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool compare(pair<ll,ll> i, pair<ll,ll> j){
    if(i.first == j.first) {
        return i.second < j.second;
    }
    else {
        return i.first > j.first;
    }
}

int main(){
    int n; cin >> n;
    map<ll,ll> ma;
    for(int i=0;i<n;i++) {
        ll num; cin >> num;
        ma[num]++;
    }
    vector<pair<ll,ll>> vec;
    for(auto i : ma) {
        vec.push_back({i.second,i.first});
    }
    sort(vec.begin(), vec.end(), compare);
    cout << vec.front().second;
}