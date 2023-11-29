#include <bits/stdc++.h>
using namespace std;

int main(){
    while(1) {
        string a; cin >> a;
        if(a == "end") break;

        bool moeum = false;
        int moeumCount = 0;
        int jaeumCount = 0;
        int count = 0;
        int flag = 0;
        for(int i=0;i<a.size();i++) {
            if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){ 
                moeum = true;
                jaeumCount = 0;
                moeumCount++;
            }
            else {
                jaeumCount++;
                moeumCount = 0;
            }

            if(a[i] == a[i-1]) {
                if(a[i] != 'e' && a[i] != 'o') {
                    count ++;
                }
            }
            if(count > 0 || moeumCount > 2 || jaeumCount > 2) {
                cout << "<" << a << "> is not acceptable.\n";
                flag = 1;
                break;;
            }
        }
        if(moeum && !flag) {
            cout << "<" << a << "> is acceptable.\n";
        }
        else if(!flag){
            cout << "<" << a << "> is not acceptable.\n";
        }
        
    }
}