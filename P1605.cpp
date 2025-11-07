#include <bits/stdc++.h>

using namespace std;

int n, m, t;
int sx, sy, fx, fy;
int a[15][15];
int vis[15][15];
int res = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void dfs(int x, int y)
{
    if (x == fx && y == fy && vis[x][y] == 0)
    {
        res++;
        return;
    }
    if (x < 1 || x > n || y < 1 || y > m || vis[x][y] == 1)
        return;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        dfs(x + dx[i], y + dy[i]);
    }
    vis[x][y] = 0;
}
int main()
{
    memset(vis, 0, sizeof vis);
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    for (int i = 0; i < t; i++)
    {
        int tx, ty;
        cin >> tx >> ty;
        vis[tx][ty] = 1;
    }
    dfs(sx, sy);
    cout << res << endl;
    return 0;
}
