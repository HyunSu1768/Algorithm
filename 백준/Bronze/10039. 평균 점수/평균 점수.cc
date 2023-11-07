#include <bits/stdc++.h>
using namespace std;

int main(){
    int total=0;
    for(int i=0;i<5;i++){
        int num; cin >> num;
        if(num < 40) num = 40;
        total+=num;
    }
    cout << total/5;
}