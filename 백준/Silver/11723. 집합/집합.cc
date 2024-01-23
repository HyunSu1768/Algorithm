#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    set<int> se;
    for(int i=0;i<n;i++) {
        string command; cin >> command;
        if(command == "add") {
            int num; cin >> num;
            se.insert(num);
        }
        if(command == "remove") {
            int num; cin >> num;
            se.erase(num);
        }
        if(command == "check") {
            int num; cin >> num;
            if(se.count(num)) cout << "1\n";
            else cout << "0\n";
        }
        if(command == "toggle") {
            int num; cin >> num;
            if(se.count(num)) {
                se.erase(num);
            }
            else {
                se.insert(num);
            }
        }
        if(command == "all") {
            se = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        }
        if(command == "empty") {
            se.clear();
        }
    }
}