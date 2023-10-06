#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    deque<pair<int,int>> deq;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        deq.push_back({a,i+1});
    }
    while(true) {
        cout << deq.front().second << " ";
        int num = deq.front().first;
        deq.pop_front();
        if(deq.empty()) break;
        if(num > 0) {
            for(int i=0;i<num-1;i++){
                deq.push_back(deq.front());
                deq.pop_front();
            }
        }
        else {
            for(int i=num;i<0;i++){
                deq.push_front(deq.back());
                deq.pop_back();
            }
        }
    }
    
}