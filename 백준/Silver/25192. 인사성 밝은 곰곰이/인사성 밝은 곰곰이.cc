#include <bits/stdc++.h>
using namespace std;
int main(){
    set<string> s;
    int t; cin >> t;
    int result=0;
    while(t--){
        string a; cin >> a;
        if(a=="ENTER"){
            result+=s.size();
            s.clear();
        }
        else{
            s.insert(a);
        }
    }
    result += s.size();
    cout << result;
}