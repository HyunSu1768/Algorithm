#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll arr[81];
ll Count[81];
int main(){
    int n; cin >> n;
    arr[1] = 4;
    Count[1] = 1;
    for(int i=2;i<=n;i++){
        Count[i] = Count[i-1] + Count[i-2];
        arr[i] = arr[i-1] + Count[i]*2;
    }
    cout << arr[n];
}