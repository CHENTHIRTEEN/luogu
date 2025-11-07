#include <bits/stdc++.h>
#define maxN 110
using namespace std;

char a[maxN][maxN];
int vis[maxN][maxN] = {0};
int n;
int id = 0;
string s = "yizhong";
int dis[8][2] = {{1, 0}, {1, 1}, {1, -1}, {0, 1}, {0, -1}, {-1, 0}, {-1, 1}, {-1, -1}};
void dfs(int dx, int dy, int x, int y, int k)
{
}
int main()
{
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
                for (int k = 0; k < 4; k++)
                {
                }
            }
        }
    }
    return 0;
}
