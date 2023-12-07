#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m; cin >> n >> m;
    map<string, vector<string>> ma;
    for(int i=0;i<n;i++){
        string team; cin >> team;
        int num; cin >> num;
        for(int j=0;j<num;j++){
            string member; cin >> member;
            ma[team].push_back(member);
        }
    }
    for(int i=0;i<m;i++) {
        int b;
        string a; cin >> a >> b;
        if(b==0) {
            vector<string> result = ma[a];
            sort(result.begin(), result.end());
            for(string p : result) {
                cout << p << "\n";
            }
        }
        else if(b==1) {
            for(auto i = ma.begin(); i != ma.end();i++){
                if(find(i->second.begin(), i->second.end(), a) != i->second.end()) {
                    cout << i->first << "\n";
                    break;
                }
            }
        }
    }
}