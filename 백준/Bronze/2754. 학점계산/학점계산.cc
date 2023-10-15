#include <bits/stdc++.h>
using namespace std;

int main(){
    string a; cin >> a;
    float result = 0;
    for(char i : a) {
        switch (i)
        {
        case 'A':
            result += 4;
            break;
        case 'B':
            result += 3;
            break;
        case 'C':
            result += 2;
            break;
        case 'D':
            result += 1;
            break;
        case '-':
            result -= 0.3;
            break;
        case '+':
            result += 0.3;
            break;
        default:
            break;
        }
    }
    printf("%.1f", result);
}