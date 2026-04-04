#include <bits/stdc++.h>
#define maxN 1010
using namespace std;

int n, m, x, y, res = 0;
int fa[maxN];
int find(int c)
{
    if(fa[c] == c)
        return c;
    return fa[c] = find(fa[c]);
}
void join(int a, int b)
{
    int f1 = find(a), f2 = find(b);
    if(f1 != f2) 
    {
        fa[f1] = f2;
        res--;
    }
}
int main()
{
    while (1)
    {
        cin >> n;
        res = n;
        if (n == 0)
            break;
        cin >> m;
        if (m == 0)
        {
            cout << n - 1 << endl;
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> x >> y;
            join(x, y);
        }
        cout << res - 1 << endl;

    }
    return 0;
}
