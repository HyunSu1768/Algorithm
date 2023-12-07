#include <bits/stdc++.h>
using namespace std;

#define prev hyunsu

string s,prev;
int A,B,resultA,resultB;

string print(int num) {
    string a = "00" + to_string(num/60);
    string b = "00" + to_string(num%60);
    return (a.substr(a.size()-2,2) + ":"+b.substr(b.size()-2, 2));
}

int changeToInt(string s) {
    return atoi(s.substr(0,2).c_str()) * 60 + atoi(s.substr(3,2).c_str()); 
}

void go(int &sum, string time) {
    sum += changeToInt(time) - changeToInt(prev);
}

int main() {
    int n; cin >> n;
    
    for(int i=0;i<n;i++){
        int team; 
        cin >> team >> s;
        if(A>B) go(resultA, s);
        if(B>A) go(resultB, s);
        team == 1? A++ : B++;
        prev = s;
    }
    if(A>B) go(resultA, "48:00");
    if(B>A) go(resultB, "48:00");
    cout << print(resultA) << "\n";
    cout << print(resultB) << "\n";

}