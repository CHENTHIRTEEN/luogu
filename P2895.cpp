#include <bits/stdc++.h>
#define maxN 310
#define MIN(x, y, t) if (x >= 0 && y >= 0) death[x][y] = min(death[x][y], t)
using namespace std;

struct node {
    int x, y;
};
queue<node> q;
int ans[maxN][maxN], death[maxN][maxN];// 记录被陨石砸中的时间
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int main() {
    int m, Ans = 100000;
    memset(ans, -1, sizeof ans);
    memset(death, 0x7f, sizeof death);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        MIN(x, y, t);
        for (int k = 0; k < 4; ++k) {
            MIN(x + dx[k], y + dy[k], t);
        }
    }
    q.push((node){0, 0});
    ans[0][0] = 0;
    while (!q.empty()) {
        node u = q.front();
        int ux = u.x, uy = u.y;
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int x = ux + dx[k], y = uy + dy[k];
            if (x < 0 || y < 0 || ans[x][y] != -1 || ans[ux][uy] + 1 >= death[x][y])
                continue;
            ans[x][y] = ans[ux][uy] + 1;
            q.push((node) {x, y});
        }
    }
    for (int i = 0; i <= 305; ++i) {
        for (int j = 0; j <= 305; ++j) {
            if (death[i][j] > 1000 && ans[i][j] != -1)
                Ans = min(Ans, ans[i][j]);
        }
    }
    if (Ans == 100000) puts("-1");
    else cout << Ans << endl;
    return 0;
}