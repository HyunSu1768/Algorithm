#include <bits/stdc++.h>
using namespace std;
int n;
int ma,mb,mc,md;

int a[16],b[16],c[16],d[16], price[16];
int visited[16];
map<int,vector<vector<int>>> result;
int minValue = 9876;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n; 
    cin >> ma >> mb >> mc >> md;
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i] >> price[i];
    }
    vector<int> empty;
    int aa,bb,cc,dd,sum;
    for(int i=1 ;i < (1 << n);i++) {
        aa=bb=cc=dd=sum=0;
        vector<int> v;
        for(int j=0;j<n;j++) {
            if(i & (1<<j)) {
                v.push_back(j+1);
                aa += a[j];
                bb += b[j];
                cc += c[j];
                dd += d[j];
                sum += price[j];
            }
        }
        if(aa >= ma && bb >= mb && cc >= mc && dd >= md) {
            if(minValue >= sum) {
                minValue = sum;
                result[sum].push_back(v);
            }
        }
    }
    if(minValue == 9876) {
        cout << "-1";
        return 0;
    }
    sort(result[minValue].begin(), result[minValue].end());
    cout << minValue << "\n";
    for(int i : result[minValue][0]) {
        cout << i << " ";
    }
}