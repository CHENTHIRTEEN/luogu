#include <bits/stdc++.h>
#define maxN 1010
using namespace std;

int n, m, x, y, res = 0;
int fa[maxN];
int find(int c)
{
    cerr << "find(" << c << ")" << endl;
    if (c < 1 || c >= maxN)
    {
        cerr << "ERROR: c=" << c << " out of range!" << endl;
    }
    if (fa[c] == c)
        return c;
    return fa[c] = find(c);
}
void join(int a, int b)
{
    cerr << "join(" << a << "," << b << ")" << endl;
    int f1 = find(a), f2 = find(b);
    if (f1 != f2)
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
        cerr << "Read n=" << n << endl;
        res = n;
        if (n == 0)
            break;
        cin >> m;
        cerr << "Read m=" << m << endl;
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
            cerr << "Read edge " << x << " " << y << endl;
            join(x, y);
        }
        cout << res - 1 << endl;
    }
    return 0;
}
