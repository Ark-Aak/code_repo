#include <iostream>
#include <cstdio>
#include <vector>
#include <functional>
#include "testlib.h"
int main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    int n = inf.readInt(), k = inf.readInt();
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u = inf.readInt(1, n), v = inf.readInt(1, n);
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<int> p(n);
    for (int i = 0; i < n; i++)
        p[i] = inf.readInt();
    std::vector<int> lg2(n + 1);
    lg2[0] = -1;
    for (int i = 1; i <= n; i++)
        lg2[i] = lg2[i / 2] + 1;
    std::vector<std::vector<int>> mn(n, std::vector<int>(lg2[n] + 1));
    std::vector<int> dfn(n);
    int Index = 0;
    std::vector<int> dis(n, 0);
    std::function<void(int, int)> dfs = [&](int u, int father)
    {
        dfn[u] = Index++;
        mn[dfn[u]][0] = father;
        for (int v : g[u])
        {
            if (v == father)
                continue;
            dis[v] = dis[u] + 1;
            dfs(v, u);
        }
        return;
    };
    dfs(0, -1);
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 0; i + (1 << j) - 1 < n; i++)
        {
            if (mn[i][j - 1] == -1 || (mn[i + (1 << (j - 1))][j - 1] != -1 && dfn[mn[i][j - 1]] < dfn[mn[i + (1 << (j - 1))][j - 1]]))
                mn[i][j] = mn[i][j - 1];
            else
                mn[i][j] = mn[i + (1 << (j - 1))][j - 1];
        }
    std::function<int(int, int)> lca = [=](int u, int v)
    {
        if (u == v)
            return u;
        u = dfn[u], v = dfn[v];
        if (u > v)
            std::swap(u, v);
        u++;
        int d = lg2[v - u + 1];
        if (mn[u][d] == -1 || (mn[v - (1 << d) + 1][d] != -1 && dfn[mn[u][d]] < dfn[mn[v - (1 << d) + 1][d]]))
            return mn[u][d];
        else
            return mn[v - (1 << d) + 1][d];
    };
    long long sumu = ouf.readLong(), suma = ans.readLong();
    if (sumu < suma)
        quitf(_wa, "Your solution is less profitable than the standard answer");
    long long sum = 0;
    int m = ouf.readInt(1, n);
    std::vector<int> x(m);
    for (int i = 0; i < m; i++)
        x[i] = ouf.readInt(1, n), x[i]--, sum += p[x[i]];
    if (sum != sumu)
        quitf(_wa, "Your profit is not equal to the plan you give");
    if (x.front() != 0)
        quitf(_wa, "You have to start from 1");
    std::vector<int> vis(n, 0);
    for (int i = 0; i < m; i++)
        if (vis[x[i]])
            quitf(_wa, "%d appears more than once", x[i] + 1);
        else
            vis[x[i]] = 1;
    for (int i = 1; i < m; i++)
    {
        int u = x[i - 1], v = x[i];
        int l = lca(u, v);
        int d = dis[u] + dis[v] - dis[l] * 2;
        if (d > k)
            quitf(_wa, "distance between (%d, %d) is greater than %d", u, v, k);
    }
    if (sumu == suma)
        quitf(_ok, "Accepted");
    else
        quitf(_fail, "Your solution is more profitable than the standard answer");
    return 0;
}
