#include <bits/stdc++.h>

using namespace std;

// 全局变量定义
double a[21][2];    // 存储每块奶酪的坐标，a[i][0]是横坐标，a[i][1]是纵坐标
double dis[21][21]; // 距离矩阵，dis[i][j]表示第i块奶酪到第j块奶酪的距离（0表示起点）
int n;              // 奶酪的数量
double res = 1e9;   // 记录最短路径长度，初始化为一个很大的数
int cnt = 0;        // 计数器（当前代码中未使用）
int vis[21] = {0};  // 访问标记数组，vis[i]=1表示第i块奶酪已被访问

/**
 * 计算两点之间的欧几里得距离
 * @param x1, y1 第一个点的坐标
 * @param x2, y2 第二个点的坐标
 * @return 两点之间的距离
 */
double f(double x1, double x2, double y1, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

/**
 * 深度优先搜索，遍历所有可能的吃奶酪顺序，找到最短路径
 * @param x 当前是第几步（已经吃了几块奶酪）
 * @param t 当前已经走过的总距离
 * @param k 当前所在的位置（0表示起点，1~n表示第几块奶酪）
 */
void dfs(int x, double t, int k)
{
    // 剪枝：如果当前距离已经大于等于已知的最短距离，直接返回
    if (t >= res)
        return;

    // 递归终止条件：所有奶酪都吃完了
    if (x > n)
    {
        res = min(res, t); // 更新最短距离
        return;
    }

    // 尝试吃每一块还没吃过的奶酪
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i]) // 如果第i块奶酪还没被吃
        {
            vis[i] = 1;                   // 标记为已访问
            dfs(x + 1, t + dis[k][i], i); // 递归：从位置k移动到位置i，距离增加dis[k][i]
            vis[i] = 0;                   // 回溯：取消标记，尝试其他路径
        }
    }
}

int main()
{
    // 读入奶酪数量
    cin >> n;

    // 读入每块奶酪的坐标
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i][0] >> a[i][1];
    }

    // 预处理：计算任意两点之间的距离
    // i=0表示起点(0,0)，i=1~n表示第i块奶酪
    for (int i = 0; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            // 获取点i的坐标
            double x1 = (i == 0) ? 0 : a[i][0];
            double y1 = (i == 0) ? 0 : a[i][1];

            // 获取点j的坐标
            double x2 = (j == 0) ? 0 : a[j][0];
            double y2 = (j == 0) ? 0 : a[j][1];

            // 计算距离并存储（对称赋值，确保dis[i][j]和dis[j][i]都有值）
            dis[i][j] = dis[j][i] = f(x1, x2, y1, y2);
        }
    }

    // 从起点(0,0)开始DFS，初始步数为1，当前距离为0，当前位置为0（起点）
    dfs(1, 0, 0);

    // 输出结果，保留两位小数
    printf("%.2lf", res);

    return 0;
}