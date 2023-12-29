#include <bits/stdc++.h>
using namespace std;
int num[1001];
int DP[1001];
int main() {
    int n; cin >> n;
    for(int i=0;i<n;i++) {
        cin >> num[i];
    }
    int answer = 0;
    for(int i=0;i<n;i++) {
        DP[i] = 1;
        for(int j=i-1;j>=0;j--) {
            if(num[j] < num[i]) {
                DP[i] = max(DP[i], DP[j]+1);
            }
        }
        answer = max(answer, DP[i]);
    }
    cout << answer;
}