#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    int a=0,b=0;

    for(int i=0;i<n;i++){
        int num; cin >> num;
        if(num) a++;
        else b++;
    }
    string result = (a > b) ? "Junhee is cute!" : "Junhee is not cute!";
    cout << result;
}