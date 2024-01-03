#include <bits/stdc++.h>
using namespace std;

vector<int> num_list;
vector<char> oper_list;

int result = -987654321;

int oper(char sign, int num1, int num2) {
    if(sign == '+') return num1 + num2;
    if(sign == '-') return num1 - num2;
    else return num1 * num2;
}

void go(int index, int _sum) {
    if(index == num_list.size()-1) {
        result = max(result, _sum);
        return;
    }

    go(index+1, oper(oper_list[index], _sum, num_list[index+1]));
    if(index+2 <= num_list.size()-1) {
        int temp = oper(oper_list[index+1], num_list[index+1], num_list[index+2]);
        go(index+2, oper(oper_list[index], _sum, temp));
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    string a; cin >> a;
    for(int i=0;i<n;i++) {
        if(a[i] >= '0' && a[i] <= '9') {
            num_list.push_back(a[i] - '0');
        }
        else {
            oper_list.push_back(a[i]);
        }
    }

    go(0, num_list[0]);
    cout << result;
    return 0;
}