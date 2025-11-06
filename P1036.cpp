#include <bits/stdc++.h>
using namespace std;
bool isPrim(int x) {
    if (x == 1) return false;
    if (x == 2) return true;
    for (int i = 2; i <= static_cast<int>(sqrt(x)); i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int n, k;
int nums[30];
int f[30];
int res = 0;
void dfs(int x, int sum, int l) {
    if (x == k) {
        if (isPrim(sum)) res ++;
        return ;
    }
    for (int i = l; i < n; i++) {
        dfs(x + 1, sum + nums[i], i + 1);
    }
}
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> nums[i];
    memset(f, 0, sizeof f);
    dfs(0, 0, 0);
    cout << res << endl;
    return 0;
}