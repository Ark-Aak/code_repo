#include <bits/stdc++.h>
using namespace std;
const int N = 120010;
const int NN = N * 8;
struct edge {
    int to;
    edge *nex;
} *head[NN];
int in[NN];
void add(int u, int v, int rev) {
    if (!u || !v)
        return ;

    if (rev)
        swap(u, v);

    edge *cur = new edge;
    cur->to = v;
    cur->nex = head[u];
    head[u] = cur;
}
int h[N], top[N], siz[N], fa[N], son[N], dfn[N], tot;
void dfs(int u, int v) {
    h[u] = h[v] + 1;
    siz[u] = 1;
    fa[u] = v;
    son[u] = 0;

    for (edge *cur = head[u]; cur; cur = cur->nex) {
        if (cur->to == v)
            continue;

        dfs(cur->to, u);
        siz[u] += siz[cur->to];

        if (siz[son[u]] < siz[cur->to])
            son[u] = cur->to;
    }
}
void dfs2(int u, int v) {
    dfn[u] = ++tot;
    top[u] = v;

    if (son[u])
        dfs2(son[u], v);

    for (edge *cur = head[u]; cur; cur = cur->nex) {
        if (cur->to == fa[u] || cur->to == son[u])
            continue;

        dfs2(cur->to, cur->to);
    }
}
int det, n, m;
int ls[NN][2], rs[NN][2], own[N][2];
int root[2];
int build(int l, int r, int rev) {
    if (l == r)
        return own[l][1 - rev];

    int mid = (l + r) / 2;
    int rt = ++det;
    add(rt, ls[rt][rev] = build(l, mid, rev), rev);
    add(rt, rs[rt][rev] = build(mid + 1, r, rev), rev);
    return rt;
}
void up(int x, int L, int R, int l, int r, int rt, int rev) {
    if (!rt)
        return ;

    if (L <= l && r <= R)
        return add(x, rt, rev), void();

    int m = (l + r) / 2;

    if (L <= m)
        up(x, L, R, l, m, ls[rt][rev], rev);

    if (R > m)
        up(x, L, R, m + 1, r, rs[rt][rev], rev);
}
int s[N], t[N];
void U(int o, int x, int y, int rev) { //remove x
    int remx = 1;

    while (top[x] != top[y]) {
        if (h[top[x]] < h[top[y]])
            swap(x, y), remx = -remx;

        if (remx == 1) {
            if (dfn[top[x]] <= dfn[x] - 1)
                up(o, dfn[top[x]], dfn[x] - 1, 1, n, root[rev], rev);

            remx = 0;
        } else
            up(o, dfn[top[x]], dfn[x], 1, n, root[rev], rev);

        x = fa[top[x]];
    }

    if (h[x] > h[y])
        swap(x, y), remx = -remx;

    if (remx == 1) {
        if (dfn[x] != dfn[y])
            up(o, dfn[x] + 1, dfn[y], 1, n, root[rev], rev);
    } else if (remx == -1) {
        if (dfn[x] != dfn[y])
            up(o, dfn[x], dfn[y] - 1, 1, n, root[rev], rev);
    } else
        up(o, dfn[x], dfn[y], 1, n, root[rev], rev);
}
void get() {
    int i, u, v;
    cin >> n;
    tot = 0;

    for (i = 1; i <= n; i++)
        head[i] = 0;

    for (i = 1; i < n; i++)
        cin >> u >> v, add(u, v, 0), add(v, u, 0);

    dfs(1, 0);
    dfs2(1, 1);
    cin >> m;

    for (i = 1; i <= n; i++)
        own[i][0] = own[i][1] = 0;

    for (i = 1; i <= m; i++)
        cin >> s[i] >> t[i], own[dfn[s[i]]][0] = own[dfn[t[i]]][1] = i;

    for (i = 1; i <= 8 * n; i++)
        head[i] = 0, in[i] = 0;

    det = m;
    root[0] = build(1, n, 0);
    root[1] = build(1, n, 1);

    for (i = 1; i <= m; i++) {
        U(i, t[i], s[i], 0);
        U(i, s[i], t[i], 1);
    }

    for (i = 1; i <= det; i++)
        for (edge *cur = head[i]; cur; cur = cur->nex)
            in[cur->to]++;

    queue<int> q;

    for (i = 1; i <= det; i++)
        if (!in[i])
            q.push(i);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (edge *cur = head[u]; cur; cur = cur->nex) {
            in[cur->to]--;

            if (!in[cur->to])
                q.push(cur->to);
        }
    }

    int ok = 1;

    for (i = 1; i <= det; i++)
        if (in[i])
            ok = 0;

    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int main() {
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
    int T;
    cin >> T;

    while (T--)
        get();

    return 0;
}
