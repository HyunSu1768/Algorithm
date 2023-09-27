#include <bits/stdc++.h>
using namespace std;
int cnt[1000];
int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    string a; cin >> a;
    int flag = 0;
    char mid;
    string ret = "";
    for(int i : a) cnt[i]++;
    for(int i = 'Z'; i>='A'; i--){
        if(cnt[i] & 1){
            flag ++;
            mid = char(i);
            cnt[i]--;
        }
        if(flag == 2) break;
        for(int j=0;j<cnt[i];j+=2){
            ret = char(i) + ret;
            ret += char(i);
        }
    }
    if(mid){
        ret.insert(ret.begin() + ret.size()/2,mid);
    }
    if(flag == 2){
        cout << "I'm Sorry Hansoo";
    }
    else {cout << ret;}
}