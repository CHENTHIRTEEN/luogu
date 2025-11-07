#include <bits/stdc++.h>
#define maxN 110
using namespace std;

char a[maxN][maxN];
int vis[maxN][maxN] = {0};
int n;
int id = 0;
string s = "yizhong";
int route[7][2];
int dis[8][2] = {{1, 0}, {1, 1}, {1, -1}, {0, 1}, {0, -1}, {-1, 0}, {-1, 1}, {-1, -1}};
void dfs(int dx, int dy, int x, int y, int k)
{
    // cout << a[x][y] << " " << s[k - 1] << endl;
    if (k > 7)
    {
        for (int i = 0; i < 7; i++)
        {
            // cout << "x=" << route[k - 1][0] << endl;
            // cout << "y=" << route[k - 1][1] << endl;
            vis[route[i][0]][route[i][1]] = 1;
        }
        memset(route, 0, sizeof route);
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         cout << vis[i][j];
        //     }
        //     cout << endl;
        // }

        return;
    }
    if (s[k - 1] == a[x][y])
    {
        route[k - 1][0] = x;
        route[k - 1][1] = y;
        // cout << route[k - 1][0] << endl;
        // cout << route[k - 1][1] << endl;
        int nx = x + dx, ny = y + dy;
        dfs(dx, dy, nx, ny, k + 1);
    }
    else
    {
        return;
    }

    // vis[x][y] = 1;
}
int main()
{
    memset(route, 0, sizeof route);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 'y')
            {
                for (int k = 0; k < 8; k++)
                {
                    if (a[i + dis[k][0]][j + dis[k][1]] == 'i')
                    {
                        dfs(dis[k][0], dis[k][1], i, j, 1);
                        continue;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (vis[i][j] == 1)
            {
                cout << a[i][j];
            }
            else
            {
                cout << '*';
            }
        }
        cout << endl;
    }
    return 0;
}
