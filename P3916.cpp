#include <bits/stdc++.h>
#define maxN 10010
using namespace std;

vector<int> p[maxN];
int n, m;
int vis[maxN];
void dfs(int x, int t)
{
    vis[x] = 1;
    for (int i = 1, sz = p[x].size(); i <= sz; i++)
    {
        if(!vis[p[x][i]])
        {
            dfs(p[x][i], );
        }
    }
    
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        p[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
    {
        vis[maxN] = {0};
    }

    return 0;
}
