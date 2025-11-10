#include <bits/stdc++.h>

using namespace std;

char a[310][310];
int vis[310][310];
int n, m;
int res = 1e9, sx = 0, sy = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
struct cow
{
    int x, y; // 奶牛的坐标
    int t;    // 当前的移动次数
};
queue<cow> q;
int main()
{
    memset(vis, 0, sizeof vis);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '@')
            {
                sx = i;
                sy = j;
            }
        }
    }
    q.push((cow){sx, sy, 0});
    while (!q.empty())
    {
        int nx, ny, nt;
        cow nc;
        nc = q.front();
        nx = nc.x, ny = nc.y, nt = nc.t;
        // cout << nx << ny << nt << endl;
        q.pop();
        if (a[nx][ny] == '#' || nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny] == 1)
        {
            continue;
        }
        vis[nx][ny] = 1;
        // cout << nx << ny << nt << endl;
        // cout << "a[nx][ny]=" << a[nx][ny] << endl;
        if (a[nx][ny] == '=')
        {
            res = min(res, nt);
            break;
        }
        bool found;
        // 处理传送门
        if (a[nx][ny] >= 'A' && a[nx][ny] <= 'Z')
        {
            char tra = a[nx][ny];
            found = false;
            for (int i = 1; i <= n && !found; i++)
            {
                for (int j = 1; j <= m && !found; j++)
                {
                    if ((i != nx || j != ny) && a[i][j] == tra)
                    {
                        nx = i;
                        ny = j;
                        found = true;
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (!found)
            {
                vis[nx][ny] = 1;
            }
            q.push((cow){nx + dx[i], ny + dy[i], nt + 1});
        }
    }
    cout << res << endl;
    return 0;
}
