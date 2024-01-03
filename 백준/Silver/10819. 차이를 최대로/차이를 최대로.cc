#include <bits/stdc++.h>
using namespace std;

int arr[10];

int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int result = 0;
    sort(arr, arr+n);
    do
    {
        int total = 0;
        for(int i=0;i<n-1;i++) {
            total = total+(abs(arr[i] - arr[i+1]));
        }
        result = max(result, total);
    } while (next_permutation(arr, arr+n));
    cout << result;
}