#include <bits/stdc++.h>

using namespace std;

int n[35];
int k;
int ex[20];
string s;
int main()
{
    memset(ex, 0, sizeof(ex));
    cin >> s >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
    }

    for (int i = 0; i < s.size(); i++)
        n[i + 1] = s[i] - '0';
    return 0;
}
