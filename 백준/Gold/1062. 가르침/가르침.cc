#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> words;
int visited[1000];
int result;

void go(int index, int num, char start) {
    if(index == m) {
        int cnt = 0;
        for(int i : words) {
            if((num & i) == i) {
                cnt ++;
            }
        }
        result = max(result, cnt);
        return;
    }
    for(char i = start; i <= 'z';i++) {
        if(visited[i]) continue;
        visited[i] = 1;
        go(index+1, (num | (1 << (i-'a'))), i);
        visited[i] = 0;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        string a; cin >> a;
        unsigned int num = 0;
        for(int j=0;j<a.size();j++) {
            num |= (1 << (a[j]-'a'));
        }
        words.push_back(num);
    }
    go(0,0,'a');
    cout << result;
}