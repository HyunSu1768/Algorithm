#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n; string k; cin >> n >> k;
    string hour, min, sec;
    ll ret = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<60;j++){
            for(int k1=0;k1<60;k1++){
                hour = to_string(i);
                min = to_string(j);
                sec = to_string(k1);
                if(i<10) {
                    hour = "0" + to_string(i);
                }
                if(j<10) {
                    min = "0" + to_string(j);
                }
                if(k1<10) {
                    sec = "0" + to_string(k1);
                }
                if(hour.find(k) != string::npos || min.find(k) != string::npos || sec.find(k) != string::npos) {
                    // cout << hour << " " << min << ' ' << sec << "\n";
                    ret ++;
                }
            }
        }
    } 
    cout << ret;
}