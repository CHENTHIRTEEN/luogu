#include <bits/stdc++.h>

using namespace std;

int n;
int a[11], vis[11] = {0};
void dfs(int x)
{
    if (x > n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << setw(5) << a[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] != 1)
        {
            vis[i] = 1;
            a[x] = i;
            dfs(x + 1);
            vis[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    dfs(1);
    return 0;
}
