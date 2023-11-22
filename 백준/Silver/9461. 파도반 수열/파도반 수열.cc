#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[101] = {0,1,1};
int main(){
    int n; cin >> n;
    for(int i=3;i<=100;i++){
        arr[i] = arr[i-2] + arr[i-3];
    }
    for(int i=0;i<n;i++){
        int num; cin >> num;
        cout << arr[num] << "\n";
    }
}