#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string pattern; cin >> pattern;
    int pos = pattern.find("*");
    string pre = pattern.substr(0, pos);
    string sub = pattern.substr(pos+1);
    for(int i=0;i<n;i++){
        string a; cin >> a;
        if(pre.size() + sub.size() > a.size()) {
            cout << "NE" <<"\n";
            continue;
        } else {
            if(a.substr(0,pre.size()) == pre && a.substr(a.size() - sub.size()) == sub){
                cout << "DA" <<"\n";
            }
            else {
                cout << "NE" <<"\n";
            }
        }
    }
    
}
