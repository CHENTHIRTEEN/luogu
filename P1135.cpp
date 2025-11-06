#include <bits/stdc++.h>
#define maxN 210
using namespace std;

int N, A, B;
int k[maxN], vis[maxN] = {0};
int dx[] = {1, -1};
struct node {
    int floor, d;
};
int main() {
    // memset(res, -1, sizeof res);
    cin >> N >> A >> B;
    for (int i = 1; i <= N; i++) cin >> k[i];
    queue<node> q;
    node c;
    c.floor = A, c.d = 0;
    q.push(c);
    vis[A] = 1;
    node now;
    while (!q.empty()) {
        now = q.front();
        q.pop();
        if (now.floor == B) {
            break;
        }
        for (auto x : dx) {
            int dist = x * k[now.floor] + now.floor;
            if (dist >= 1 && dist <= N && !vis[dist]) {
                q.push((node){dist, now.d + 1});
                vis[dist] = 1;
            }
        }
    }
    if (now.floor == B)
        cout << now.d << endl;
    else
        cout << -1 << endl;
    return 0;
}