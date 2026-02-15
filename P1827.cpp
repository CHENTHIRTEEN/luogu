#include <bits/stdc++.h>
#define maxN 31
using namespace std;

string a, b;
void build(int l1, int r1, int l2, int r2)
{
    if(l1 > r1 || l2 > r2)
        return;
    for (int i = l2; i <= r2; i++)
    {
        if(b[i] == a[l1]){
            build(l1 + 1, l1 + i - l2, l2, i - 1);
            build(l1 + i - l2 + 1, r1, i + 1, r2);
            cout << a[l1];
        }
    }
}

int main()
{
    cin >> a >> b;
    build(0, a.size() - 1, 0, b.size() - 1);
    return 0;
}
