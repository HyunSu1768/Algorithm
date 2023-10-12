#include <bits/stdc++.h>
using namespace std;

int main(){
    while(1) {
        int result = 0;
        string a;
        getline(cin, a);
        if(a == "#") break;
        for(int i : a) {
            if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
                result++;
            }
            if(i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U') {
                result++;
            }
        }
        cout << result << "\n";
    }
}