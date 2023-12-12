#include <bits/stdc++.h>
using namespace std;

int rankF(char i) {
    if(i == '(' || i ==')') return 0;
    if(i == '+' || i == '-') return 1;
    if(i == '*' || i == '/') return 2;
    else return -1;
} 

int main(){
    string a; cin >> a;
    stack<char> stk;
    char c; 
    for(char i : a) {
        if(i == '+' || i =='-' || i == '*' || i =='/') {
            while(!stk.empty() && rankF(stk.top()) >= rankF(i)) {
                cout << stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        else if(i == '(') {
            stk.push(i);
        }
        else if(i == ')') {
            c = stk.top(); stk.pop();
            while(c != '(') {
                cout << c;
                c = stk.top();
                stk.pop();
            }
        }
        else {
            cout << i;
        }
    }
    while(!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
}