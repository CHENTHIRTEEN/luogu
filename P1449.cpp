#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;
struct Node {
    int l, r;
} t[MAXN];
int n;
void build(){
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i].l >> t[i].r;
    }
}
int dfs(int x){
    if (!x)
        return 0;
    return max(dfs(t[x].l), dfs(t[x].r)) + 1;
}
int main()
{
    cin >> n;
    build();
    int res = dfs(1);
    cout << res << endl;
    return 0;
}
