#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    while(n--) {
        int errorflag=0;
        int reverseCount = 0;
        deque<int> vec;
        string pattern; cin >> pattern;
        int arrSize; cin >> arrSize;
        string arr; cin >> arr;
        string b = ""; 
        for(char a : arr){
            if(a >= '0' && a <= '9'){
                b += a;
            }
            if(a == ',' || a ==']' && arrSize){
                vec.push_back(stoi(b));
                b = "";
            }
        }
        for(char a : pattern) {
            if(a == 'R') reverseCount++;
            if(a == 'D') {
                if(!vec.empty()){
                    if(reverseCount & 1){
                        vec.pop_back();
                    }
                    else {
                        vec.erase(vec.begin());
                    }
                }
                else {
                    errorflag=1;
                }
                
            }
        }
        if(errorflag) {
            cout << "error\n";
            continue;
        }
        else if(reverseCount & 1){
            reverse(vec.begin(), vec.end());
        }
        cout << "[";
        if(vec.empty()) cout << "]\n";
        while(!vec.empty()) {
            cout << vec[0];
            vec.erase(vec.begin());
            if(vec.empty()){
                cout << "]\n";
            } else {
                cout << ",";
            }
        }
    }
}