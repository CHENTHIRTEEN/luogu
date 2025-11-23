#include <bits/stdc++.h>

using namespace std;

const double targetX = 233.0;
const double targetY = 666.0;

double calc(double r)
{
    double ratio = targetY / r;
    ratio = min(1.0, max(-1.0, ratio));
    double angle = asin(ratio);
    double horizontal1 = r;
    double arc = r * angle;
    double xAfterRotate = sqrt(max(0.0, r * r - targetY * targetY));
    double horizontal2 = targetX - xAfterRotate;
    return horizontal1 + arc + horizontal2;
}

double best = 1e100;

void dfs(double l, double r, int depth)
{
    if (depth >= 80 || (r - l) < 1e-12)
    {
        double mid = (l + r) * 0.5;
        best = min(best, calc(mid));
        return;
    }
    double m1 = l + (r - l) / 3.0;
    double m2 = r - (r - l) / 3.0;
    if (calc(m1) < calc(m2))
    {
        dfs(l, m2, depth + 1);
    }
    else
    {
        dfs(m1, r, depth + 1);
    }
}

int main()
{
    double rMin = targetY;
    double rMax = hypot(targetX, targetY);
    best = 1e100;
    dfs(rMin, rMax, 0);
    cout << llround(best) << endl;
    return 0;
}
