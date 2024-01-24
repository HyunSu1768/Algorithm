#include <bits/stdc++.h>
using namespace std;
int n;

int number[12];
int visited[12];
vector<int> vec[12];
int result = 987654321;
void check(int num, int map) {
    visited[num] = 1;
    for(int i : vec[num]) {
        if((map & (1 << (num-1))) && (map & (1 << (i-1))) && !visited[i]) {
            visited[i] = 1;
            check(i, map);
        }
        if(!(map & (1 << (num-1))) && !(map & (1 << (i-1))) && !visited[i]) {
            visited[i] = 1;
            check(i, map);
        }
    }
}
int main(){
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> number[i];
    }

    for(int i=1;i<=n;i++) {
        int num; cin >> num;
        for(int j=0;j<num;j++) {
            int a; cin >> a;
            vec[i].push_back(a);
        }
    }

    for(int i=1;i<(1 << n)-1;i++) {
        memset(visited,0,sizeof(visited));
        int cnt = 0;
        for(int j=0;j<n;j++) {
            if(!visited[j+1]) {
                check(j+1,i);
                cnt++;
            }
        }
        if(cnt == 2) {
            int include = 0;
            int exclude = 0;
            for(int p=1;p<=n;p++) {
                if(i & (1 << (p-1))) {
                    include += number[p];
                }
                else {
                    exclude += number[p];
                }
            }
            result = min(result, abs(include-exclude));
        }
    }
    if(result == 987654321) {
        cout << "-1";
    }
    else 
    cout << result;
}