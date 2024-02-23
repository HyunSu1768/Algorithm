#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL);
    register int N, A, B, C, ans = 0;
    cin >> N >> A >> B >> C;
    N > A ? ans += A : ans += N;
    N > B ? ans += B : ans += N;
    N > C ? ans += C : ans += N;
    cout << ans;
    return 0;
}