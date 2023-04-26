#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    while(n--){
        int answer=0;
        int num; cin >> num;
        string a = bitset<100>(num).to_string();
        for(int i=a.size()-1;i>=0;i--){
            if(a[i]=='1'){
                cout << answer << " ";
            }
            answer++;
        }
        cout << "\n";
    }
    
}