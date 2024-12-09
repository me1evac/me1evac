#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int lim = 100;
ll n, cnt = 0;
vector<ll> q, d1, d2;

void solve(int i) {
    if (i > n) {
        cnt++;
        return;
    }
    for (int j = 1; j <= n; ++j) {
        if (q[j] == 0 && d1[i - j + n] == 0 && d2[i + j - 1] == 0) {
            q[j] = d1[i - j + n] = d2[i + j - 1] = 1; 
            solve(i + 1);
            q[j] = d1[i - j + n] = d2[i + j - 1] = 0;
        }
    }
}

int main() {
    cin >> n;
    //Dat cac gtri trong vector ve 0
    q.assign(lim, 0);d1.assign(lim*2, 0);d2.assign(lim*2, 0);
    solve(1);
    cout << cnt << "\n";
    return 0;
}
