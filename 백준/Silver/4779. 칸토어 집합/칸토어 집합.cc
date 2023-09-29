#include <bits/stdc++.h>
using namespace std;
string a;
void fun(int start, int end) {
    if(end - start == 1) return;
    int count = (end-start) / 3;
    for(int i=start + count; i< end - count;i++){
        a[i] = ' ';
    }
    fun(start, start+count);
    fun(end-count, end);
}

int main(){
    int n;
    while(cin >> n) {
        int size = pow(3,n);
        a.clear();
        a.append(size, '-');

        fun(0, size);
        cout << a << "\n";
    }
}