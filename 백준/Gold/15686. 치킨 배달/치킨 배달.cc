#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> chickenList;
vector<pair<int,int>> chicken, _home;
int visited[51][51];
void go(int index, vector<int> v) {
    if(v.size() == m) {
        chickenList.push_back(v);
        return;
    }
    for(int i = index+1; i < chicken.size(); i++) {
        v.push_back(i);
        go(i, v);
        v.pop_back();
    }
    return;
}
int main() {
    cin >> n >> m;
    int cnt = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int num; cin >> num;
            if(num ==1)_home.push_back({i,j});
            if(num ==2) chicken.push_back({i,j});
        }
    }
    vector<int> empty;
    go(-1,empty);
    int result = 987654321;
    for(vector<int> chik : chickenList) {
        int ret = 0;
        for(pair<int,int> home : _home) {
            int _min = 987654321;
            for(int ch : chik) {
                int dist = abs(home.first - chicken[ch].first) + abs(home.second - chicken[ch].second);
                _min = min(_min, dist);
            }
            ret += _min;
        }
        result = min(result, ret);
    }
    cout << result;
}