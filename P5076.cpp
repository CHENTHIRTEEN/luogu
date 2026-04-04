#include <bits/stdc++.h>
#define  maxN 100010
using namespace std;

int n, root, cnt, opt, x;
struct Node
{
    int left, right, size, value, num;
    Node(int l, int r, int s, int v)
    : left(l), right(r), size(s), value(v), num(1) {}
    Node(){}
}t[maxN];

inline void update(int root) {
    t[root].size = t[t[root].left].size + t[t[root].right].size + t[root].num;
}
int main()
{
    
    return 0;
}
