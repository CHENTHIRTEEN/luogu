#include <bits/stdc++.h>
#define maxN 410
using namespace std;

struct crood {
    int x; int y;
};
int res[maxN][maxN];
int n, m, sx, sy;
int x, y;
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
queue<crood> q;
int main() {
    cin >> n >> m >> sx >> sy;
    memset(res, -1, sizeof res);
    crood c = {sx, sy};
    q.push(c);
    res[sx][sy] = 0;
    while (!q.empty()) {
        crood u = q.front();
        int ux = u.x, uy = u.y;
        q.pop();
        for (int i = 0; i < 8; i++) {
            x = ux + dx[i], y = uy + dy[i];
            int d = res[ux][uy];
            if (x < 1 || x > n  || y < 1 || y > m || res[x][y] != -1) continue;
            res[x][y] = d + 1;
            crood c = {x, y};
            q.push(c);
        }
    }
    for (int i=1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}