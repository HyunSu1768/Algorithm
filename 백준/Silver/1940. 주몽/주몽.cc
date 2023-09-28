#include <bits/stdc++.h>
using namespace std;
int arr[1500000];
int arr2[1500000];
int main(){
    int n; cin >> n;
    int hap; cin >> hap;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        arr[num]++;
        arr2[i] = num;
    }
    int result = 0;
    for(int i=0;i<n;i++){
        if(hap-arr2[i] > 0 && arr[hap-arr2[i]] && hap-arr2[i] != arr2[i]) {
            result ++;
            arr[hap-arr2[i]]--;
            arr[arr2[i]]--;
        }
    }
    cout << result;
}