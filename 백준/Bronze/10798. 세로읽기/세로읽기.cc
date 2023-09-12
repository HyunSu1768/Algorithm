#include <bits/stdc++.h>
using namespace std;

int main(){
    int cnt=0;
    string a;
    char arr[16][16] = {0,};
    for(int i=0;i<5;i++){
        cin >> a;
        for(int j=0;j<a.size();j++){
            arr[i][j] = a[j];
        }
        if(cnt<a.size()){
            cnt = a.size();
        }
    }
    
    for(int i=0;i<cnt;i++){
        for(int j=0;j<5;j++){
            if(arr[j][i]>=48){
                cout << arr[j][i];
            }
        }
    }
}