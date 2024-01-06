#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> num_list;
vector<char> oper_list;

int oper(char ch, int num1, int num2) {
    if(ch == '+') return num1 + num2;
    if(ch == '-') return num1 - num2;
    else return num1 * num2;
}

int result = -987654321;

void go(int index, int _sum) {
    if(index == num_list.size() - 1) {
        result = max(result, _sum);
        return;
    }
    go(index+1, oper(oper_list[index], _sum, num_list[index+1]));
    if(index+2 <= num_list.size() - 1) {
        int temp = oper(oper_list[index+1], num_list[index+1], num_list[index+2]);
        go(index+2, oper(oper_list[index], _sum, temp));
    }
    return;
}

int main(){
    cin >> n;
    string a; cin >> a;
    for(int i=0;i<n;i++) {
        if(a[i] >= '0' && a[i] <= '9') {
            num_list.push_back(a[i]-'0');
        }
        else {
            oper_list.push_back(a[i]);
        }
    }

    go(0, num_list[0]);

    cout << result;
}