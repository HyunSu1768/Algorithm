#include <bits/stdc++.h>
using namespace std;

bool comp(string a, string b) {
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main(){
    int n; cin >> n;
    vector<string> vec;
    for(int i=0;i<n;i++){
        string a = "";
        string input; cin >> input;
        for(char i : input) {
            if(i >= '0' && i <= '9') {
                a += i;
            }   
            else if(i >= 'a' && i <= 'z'){
                if(a != "") {
                    while(1) {
                        if(a.front() == '0' && a.size()) {
                            a.erase(a.begin());
                        }
                        else {
                            break;
                        }
                    }
                    if(a.size() == 0) {
                        a = "0";
                    }
                    vec.push_back(a);
                    a = "";
                }
            }
        }
        if(a != "") {
            while(1) {
                if(a.front() == '0' && a.size()) {
                    a.erase(a.begin());
                }
                else {
                    break;
                }
            }
            if(a.size() == 0) {
                a = "0";
            }
            vec.push_back(a);
            a = "";
        }
    }
    sort(vec.begin(), vec.end(), comp);
    for(string i : vec) {
        cout << i << "\n";
    }
}