#include <bits/stdc++.h>
using namespace std;
int main(){
    stack<char> Stk;
    int n; cin >> n;
    int cnt=0;
    while(n--){
        string line; cin >> line;
        while(!Stk.empty()) Stk.pop();
        for(int i=0;i<line.length();i++){
            if(Stk.empty()){
                Stk.push(line[i]);
            }
            else if(!Stk.empty()){
                if(Stk.top()==line[i]){
                    Stk.pop();
                }
                else{
                    Stk.push(line[i]);
                }
            }
        }
        if(Stk.empty()){
            cnt++;
        }
    }
    cout << cnt;
}