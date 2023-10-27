#include <bits/stdc++.h>
using namespace std;

int main(){
    while(1) {
        int num; cin >> num;
        int count=0;
        vector<int> vec;
        if(num==-1) break;
        for(int i=1;i<num;i++) {
            if(num%i==0) {
                vec.push_back(i);
                count += i;
            }
        }
        if(count==num) {
            cout << num << " = ";
            for(int i = 0;i<vec.size();i++){
                cout << vec[i];
                if(i !=vec.size()-1) {
                    cout << " + ";
                }
            }
        }
        else{
            cout << num << " is NOT perfect.";
        }
        cout << "\n";
        vec.clear();
    }
}