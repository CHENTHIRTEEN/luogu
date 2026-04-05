#include <bits/stdc++.h>
#define maxN 100010
using namespace std;

int n, m;
vector<int> p[maxN];
queue<int> q;
bool v[maxN];
bool vis[maxN];
void dfs(int x)
{
    cout << x << " ";
    for (int i = 0, sz = p[x].size(); i < sz; i++)
    {
        if (!vis[p[x][i]])
        {
            vis[p[x][i]] = true;
            dfs(p[x][i]);
        }
    }
    
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        p[x].push_back(y);
    }
    vis[1] = true;
    dfs(1);
    cout << endl;
    v[1] = true;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (int i = 0, sz = p[x].size(); i < sz; i++)
        {
            if(!v[p[x][i]]){
                v[p[x][i]] = true;
                q.push(p[x][i]);
            }
        }
        
    }
    return 0;
}
