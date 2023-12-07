#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    while(n--) {
        int num; cin >> num;
        int count2=0,count5=0;
        for(int i=2;i<=num;i*=2) {
            count2 += num/i;
        }
        for(int i=5;i<=num;i*=5) {
            count5 += num/i;
        }
        cout << min(count2,count5) << "\n";
    }
}