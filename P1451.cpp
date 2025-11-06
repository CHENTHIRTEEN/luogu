#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[105][105] = {0};
int vis[105][105] = {0};
int res = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void dfs(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || vis[x][y] == 1 || a[x][y] == 0)
        return;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int sx = x + dx[i];
        int sy = y + dy[i];
        dfs(sx, sy);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] != 0 && vis[i][j] == 0)
            {
                res++;
                dfs(i, j);
            }
        }
    }
    cout << res << endl;
    return 0;
}
