#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int hap=0;
        float avg = 0;
        for(int i=0;i<n;i++){
            int num; cin >> num;
            float hak; cin >> hak;
            hap += num;
            avg += num*hak;
        }
        printf("%d %.1f\n", hap, avg/hap);
    }
}