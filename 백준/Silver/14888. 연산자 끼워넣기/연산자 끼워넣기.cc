#include <bits/stdc++.h>
using namespace std;

vector<int> num_list;
vector<char> oper_list;

int oper(char oper, int num1, int num2) {
    if(oper == '+') return num1+num2;
    if(oper == '-') return num1-num2;
    if(oper == '*') return num1*num2;
    else return num1/num2;
}

int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++) {
        int num; cin >> num;
        num_list.push_back(num);
    }

    for(int i=0;i<4;i++) {
        int cnt; cin >> cnt;
        switch (i)
        {
        case 0:
        for(int j=0;j<cnt;j++) {
            oper_list.push_back('+');
        }
            break;
        case 1:
        for(int j=0;j<cnt;j++) {
            oper_list.push_back('-');
        }
            break;
        case 2:
        for(int j=0;j<cnt;j++) {
            oper_list.push_back('*');
        }
            break;
        case 3:
        for(int j=0;j<cnt;j++) {
            oper_list.push_back('/');
        }
            break;
        }
    }
    sort(oper_list.begin(), oper_list.end());
    int resultMax=-1234567890;
    int resultMin=1234567890;
    do
    {
        int total = num_list[0];
        for(int i=1;i<num_list.size();i++) {
            total = oper(oper_list[i-1], total, num_list[i]);
        }
        resultMax = max(resultMax, total);
        resultMin = min(resultMin, total);
    } while (next_permutation(oper_list.begin(), oper_list.end()));
    cout << resultMax << "\n" << resultMin;
}