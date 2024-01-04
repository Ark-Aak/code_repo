#include <bits/stdc++.h>
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 23, stdin), p1 == p2) ? EOF : *p1++)
using namespace std;
const int maxn = 1e6 + 5, B = 1005, inf = 1e9;
int m, n, q;                         /// m表示关键点个数
int a[maxn], bel[maxn], tran[maxn];  /// tran为转移表
int f[maxn], cnt[maxn], dis[maxn], pos[maxn];
/// cnt[i]表示i子树中有多少个关键点,dis[i]表示i到虚树的距离,pos[i]表示i到虚树上的最近点
int id[maxn], key[maxn], dn[maxn];  /// id表示关键点的编号,key[]存储所有关键点,dn[]存储虚边上的点底端的关键点
int p[maxn], vis[maxn];  /// p[i]表示i在虚树上的父节点,vis[i]用于判断i->fa[i][0]链的移动方向
int tmp[maxn], val[maxn];  /// val[i]表示第i个关键点的代表元,tmp为备份
vector<int> vec[B + 5];    /// vec[i]存储i步后合并到虚树上的所有点
char buf[1 << 23], *p1 = buf, *p2 = buf, obuf[1 << 23], *O = obuf;
struct query {
    int x, l, r;
} g[maxn];
namespace tree {
int cnt;
vector<int> g[maxn];
int d[maxn], mxd[maxn], son[maxn], fa[maxn][17];
int dfn[maxn], id[maxn], top[maxn];
int lg[maxn];
int dn[maxn], up[maxn];
inline void dfs1(int u) {
    mxd[u] = 1;
    for (auto v : g[u]) {
        d[v] = d[u] + 1, fa[v][0] = u;
        for (int i = 1; i <= 16; i++) fa[v][i] = fa[fa[v][i - 1]][i - 1];
        dfs1(v);
        mxd[u] = max(mxd[u], mxd[v] + 1);
        if (mxd[v] >= mxd[son[u]])
            son[u] = v;
    }
}
inline void dfs2(int u, int topf, int p) {
    dfn[u] = ++cnt, id[cnt] = u, top[u] = topf;
    dn[cnt] = u, up[cnt] = p;
    if (son[u])
        dfs2(son[u], topf, fa[p][0]);
    for (auto v : g[u]) {
        if (v == son[u])
            continue;
        dfs2(v, v, v);
    }
}
inline void init() {
    d[1] = 1, dfs1(1), dfs2(1, 1, 1);
    for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
}
inline int query(int u, int k) {
    if (!k)
        return u;
    int x = fa[u][lg[k]], y = top[x], l = d[x] - d[y];
    k ^= 1 << lg[k];
    return k <= l ? dn[dfn[y] + l - k] : up[dfn[y] + k - l];
}
inline void move(int &x, int u) {
    if (x == u)
        return;
    int v = d[u] > d[x] ? query(u, d[u] - d[x] - 1) : 0;
    x = x != fa[v][0] ? fa[x][0] : v;
}
}  // namespace tree
using tree::d;
using tree::fa;
using tree::move;
int buc[maxn];
struct List {
    int h, t, sz;
    int *q;
    inline int add(int x, int y) {
        if ((x += y) >= sz)
            x -= sz;
        return x;
    }
    inline int &operator[](int x) {  ///链表定长,用指针开数组
        return q[add(h, x - 1)];     ///保证x\in[1,sz]
    }
    inline int &front() { return q[h]; }
    inline int &back() { return q[add(h, sz - 1)]; }
    inline int pop_front() {  ///头部删除,返回被删除的元素
        static int res;
        res = q[h], q[h] = 0, h = add(h, 1);
        return res;
    }
    inline int pop_back() {  ///尾部删除,返回被删除的元素
        static int res;
        h = add(h, sz - 1), res = q[h], q[h] = 0;
        return res;
    }
} t[maxn];
inline int read() {
    int q = 0;
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) q = 10 * q + ch - '0', ch = getchar();
    return q;
}
inline void write(int x) {
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}
inline int find(int x) {
    if (f[x] == x)
        return x;
    return f[x] = find(f[x]);
}
inline void merge(int &x, int y) {
    if (!x)
        x = y;
    else if (y)
        f[find(y)] = find(x);
}
int main() {
    n = read(), q = read();
    for (int i = 2; i <= n; i++) tree::g[read()].push_back(i);
    for (int i = 1; i <= n; i++) a[i] = read(), bel[i] = (i - 1) / B + 1;
    for (int i = 1; i <= q; i++) g[i].x = read(), g[i].l = read(), g[i].r = read();
    tree::init();
    for (int i = 1; i <= bel[n]; i++) {
        int st = (i - 1) * B + 1, ed = min(i * B, n), len = ed - st + 1;
        for (int j = 1; j <= n; j++) f[j] = pos[j] = j, cnt[j] = dis[j] = 0;
        cnt[1] = inf;
        for (int j = st; j <= ed; j++) cnt[a[j]] = inf;
        for (int j = n; j >= 1; j--) cnt[fa[j][0]] += cnt[j] != 0;
        /// cnt=0 虚树外,cnt=1 虚边上,cnt>=2 关键点
        for (int j = 1; j <= len; j++) vector<int>().swap(vec[j]);
        id[1] = 0, key[m = 0] = val[0] = 1;
        for (int j = 2, now = 1; j <= n; j++) {
            if (cnt[j] >= 2) {
                id[j] = ++m, key[m] = val[m] = j, t[m].h = 0, t[m].q = buc + now;
                int k = fa[j][0];
                while (cnt[k] == 1) buc[now++] = k, dn[k] = j, k = fa[k][0];
                p[m] = id[k], t[m].sz = d[j] - d[k] - 1;
            } else if (!cnt[j]) {
                dis[j] = dis[fa[j][0]] + 1, pos[j] = pos[fa[j][0]];
                if (dis[j] <= len)
                    vec[dis[j]].push_back(j);
                else
                    tran[j] = tree::query(j, len);
            }
        }
        for (int j = st; j <= ed; j++) {
            for (int k = id[a[j]]; k; k = p[k]) vis[k] = j;  ///所有vis=j的点往下走,其余往上
            for (int k = 0; k <= m; k++)
                if (k != id[a[j]])
                    tmp[k] = val[k], val[k] = 0;  ///备份关键点的信息
            for (int k = 1; k <= m; k++)          ///处理边的转移
            {
                if (!t[k].sz)
                    continue;
                if (vis[k] == j)
                    merge(val[k], t[k].pop_front());
                else
                    merge(val[p[k]], t[k].pop_back());
            }
            for (int k = 1; k <= m; k++)  ///处理点的转移
                if (vis[k] == j)
                    merge(key[p[k]] == fa[key[k]][0] ? val[k] : t[k].back(), tmp[p[k]]);
                else
                    merge(key[p[k]] == fa[key[k]][0] ? val[p[k]] : t[k].front(), tmp[k]);
            for (auto u : vec[j - st + 1])  ///处理不在虚树上的点的转移
            {
                int v = pos[u], x = dn[v];
                merge(cnt[v] >= 2 ? val[id[v]] : t[id[x]][d[x] - d[v]], u);
            }
        }
        for (int j = 0; j <= m; j++) {
            tran[val[j]] = key[j];
            for (int k = 1, u = fa[key[j]][0]; k <= t[j].sz; k++, u = fa[u][0]) tran[t[j][k]] = u;
        }
        for (int j = 1; j <= n; j++)
            if (find(j) != j)
                tran[j] = tran[find(j)];
        for (int j = 1; j <= q; j++)
            if (g[j].l <= st && g[j].r >= ed)
                g[j].x = tran[g[j].x];
            else
                for (int k = max(st, g[j].l); k <= min(ed, g[j].r); k++) move(g[j].x, a[k]);
    }
    for (int i = 1; i <= q; i++) write(g[i].x), putchar('\n');
    return 0;
}
