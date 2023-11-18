#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<pair<int,int>> vec(n);
    for(int i=0;i<n;i++){
        cin >> vec[i].first;
        vec[i].second=i;
    }
    sort(vec.begin(),vec.end());
    int result=-1;
    for(int i=0;i<n;i++){
        if(vec[i].second-i > result){
            result = vec[i].second-i;
        }
    }
    cout << result+1;
}