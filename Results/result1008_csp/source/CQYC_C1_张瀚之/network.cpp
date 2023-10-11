#include <bits/stdc++.h>
using namespace std;

int n, q;
int deep[500005];
int fa[500005][25], minn[500005][25];
vector<int> edge[500005], JCed;
bool vis[500005];

void dfs(int cur, int father) {
    deep[cur] = deep[father] + 1;
    fa[cur][0] = father; minn[cur][0] = min(cur, father);
    for (int i = 1; i <= 20; i++) {
        fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
        minn[cur][i] = min(minn[cur][i - 1], minn[fa[cur][i - 1]][i - 1]);
    }
    for (auto i: edge[cur])
        if (i != father) dfs(i, cur);
}

int get_LCA(int x, int y) {
    int ans;
    if (deep[x] < deep[y]) swap(x, y);
    ans = y;
    for (int i = 0, p = deep[x] - deep[y]; p; i--, p >>= 1)
        if (p & 1) {
            ans = min(ans, minn[x][i]);
            x = fa[x][i];
        }
    if (x == y) return ans;
    for (int i = 20; i >= 0; i--)
        if (fa[x][i] != fa[y][i]) {
            ans = min(ans, min(minn[x][i], minn[y][i]));
            x = fa[x][i]; y = fa[y][i];
        }
    return min(ans, min(minn[x][0], minn[y][0]));
}

int gt(int x) {
    int ans = 2e9;
    for (int i: JCed) ans = min(ans, get_LCA(x, i));
    return ans;
}

int main() {
    freopen("network.in", "r", stdin);
    freopen("network.out", "w", stdout);
    scanf("%d%d", &n, &q);
    memset(minn, 0x3f, sizeof minn);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        edge[u].push_back(u);
        edge[v].push_back(v);
    }
    dfs(1, 0);
    while (q--) {
        char select[10];
        int x;
        scanf("%s%d", select, &x);
        if (!strcmp(select, "JC")) {
            if (vis[x]) continue;
            vis[x] = 1;
            JCed.push_back(x);
        }
        else printf("%d\n", gt(x));
    }
    return 0;
}
