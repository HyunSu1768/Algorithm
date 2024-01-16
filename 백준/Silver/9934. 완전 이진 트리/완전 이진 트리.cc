#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> vec;
vector<int> result[12];

void go(int x,int y,int level) {
    if(x>y) return;
    if(x==y) {
        result[level].push_back(vec[x]);
        return;
    }
    int mid = (x+y)/2;
    result[level].push_back(vec[mid]);
    go(x,mid-1,level+1);
    go(mid+1,y,level+1);
    return;
} 
int main(){
    cin >> n;
    for(int i=0;i<pow(2,n)-1;i++) {
        int num; cin >> num;
        vec.push_back(num);
    }
    go(0,pow(2,n)-1,0);
    for(int i=0;i<n;i++) {
        for(int j : result[i]) {
            cout << j <<" ";
        }  
        cout <<"\n";
    }
}