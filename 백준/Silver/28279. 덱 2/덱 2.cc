#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    deque<int> deq;
    for(int i=0;i<n;i++) {
        int a; cin >> a;
        if(a==1) {
            int num; cin >> num;
            deq.push_front(num);
        }
        if(a==2) {
            int num; cin >> num;
            deq.push_back(num);
        }
        if(a==3) {
            if(deq.empty()) cout << "-1\n";
            else {
                cout << deq.front() << "\n";
                deq.pop_front();
            }
        }
        if(a==4) {
           if(deq.empty()) cout << "-1\n";
            else {
                cout << deq.back() << "\n";
                deq.pop_back();
            } 
        }
        if(a==5) {
            cout << deq.size() << "\n";
        }
        if(a==6) {
            cout << deq.empty() << "\n";
        }
        if(a==7) {
            if(deq.empty()) cout << "-1\n";
            else {
                cout << deq.front() << "\n";
            }
        }
        if(a==8) {
            if(deq.empty()) cout << "-1\n";
            else {
                cout << deq.back() << "\n";
            }
        }
    }
}