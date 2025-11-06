#include <bits/stdc++.h>
using namespace std;

int n;
int s[15], b[15];
int res = 1e9;

void dfs(int x, int ts, int tb) {
    if (x > n) {
        if (tb == 0) return;
        res = min(res, abs(ts - tb));
        return;
    }
    dfs(x + 1, ts, tb);
    dfs(x + 1, ts * s[x], tb + b[x]);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> b[i];
    }
    dfs(0, 1, 0);
    cout << res << endl;
    return 0;
}