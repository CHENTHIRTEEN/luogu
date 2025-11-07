#include <bits/stdc++.h>
#define maxN 110
using namespace std;

int n, m;
char a[maxN][maxN];
int vis[maxN][maxN];
int res = 0;
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {-1, 0, 1, 1, -1, -1, 0, 1};

void dfs(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || vis[x][y] == 1 || a[x][y] == '.')
        return;
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++)
    {
        dfs(x + dx[i], y + dy[i]);
    }
}
int main()
{
    memset(vis, 0, sizeof vis);
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
            if (a[i][j] != '.' && vis[i][j] == 0)
            {
                dfs(i, j);
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}
