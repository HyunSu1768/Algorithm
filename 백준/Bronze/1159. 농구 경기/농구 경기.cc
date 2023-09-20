#include <bits/stdc++.h>
using namespace std;
int cnt[151];
int main(){
    vector<int> result;
    int n; cin >> n;
    for(int i=0;i<n;i++){
        string a; cin >> a;
        cnt[a[0]-'a']++;
    }
    for(int i=0;i<150;i++){
        if(cnt[i]>=5){
            result.push_back(i);
        }
    }
    sort(result.begin(), result.end());
    if(result.empty()){
        cout << "PREDAJA";
        exit(0);
    }
    for(int i : result){
        char a = i+'a';
        cout << a;
    }
    
}