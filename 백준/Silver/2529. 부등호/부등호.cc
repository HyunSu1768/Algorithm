#include <bits/stdc++.h>
using namespace std;

vector<char> signVec;
vector<int> numList;

int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++) {
        char oper; cin >> oper;
        signVec.push_back(oper);
    }

    for(int i=0;i<10;i++) {
        numList.push_back(i);
    }
    string maxResult = "-2100000000";
    string minResult = "9999999999";

    do
    {
        int flag = 0;
        string a = "";
        for(int i=0;i<n+1;i++) {
            a += to_string(numList[i]);
        }
        for(int i=0;i<n;i++) {
            int num1 = numList[i];
            int num2 = numList[i+1];
            
            if(signVec[i] == '>') {
                if(num1 < num2){
                    flag = 1;
                    break;
                }
            }
            if(signVec[i] == '<') {
                if(num1 > num2) {
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) continue;
        if(stoll(a) > stoll(maxResult)) {
            maxResult = a;
        }
        if(stoll(a) < stoll(minResult)) {
            minResult = a;
        }
        
    } while (next_permutation(numList.begin(), numList.end()));
    cout << maxResult << "\n" << minResult;
}