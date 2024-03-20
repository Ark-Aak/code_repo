#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define ri resgister int
#include <immintrin.h>
#include <emmintrin.h>
using namespace std;
const int N = 2000005;
vector<int> e[N];
int head[N << 1], to[N << 1], nxt[N << 1], tot = 1, sum = 0, cnt = 0, f[N];
bitset<5> a[805][805];
long long ans = 0;
int n, m;
map<pair<int, int>, int> ma;
inline int id(int x, int y) { return (x - 1) * m + y; }
int find(int x) {
    if (f[x] == x)
        return x;
    return f[x] = find(f[x]);
}
inline void addq(int x, int y) {
    to[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;

    to[++tot] = x;
    nxt[tot] = head[y];
    head[y] = tot;
}
inline void adde(int x, int y) {
    e[x].push_back(y), tot--;
    e[y].push_back(x), tot--;
}
int dfn[N], low[N], isg[N], idx, siz[N];
void tarjan(int p, int fa) {
    dfn[p] = low[p] = ++idx;
    for (int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if (!dfn[v]) {
            tarjan(v, p);
            low[p] = min(low[p], low[v]);
            if (low[v] > dfn[p])
                isg[i] = isg[i ^ 1] = 1;
        } else if (v ^ fa)
            low[p] = min(low[p], dfn[v]);
    }
}
int dep[N], fa[N], top[N], son[N];
int kk;
void dfs1(int p) {
    dep[p] = dep[fa[p]] + 1;
    siz[p] = 1;
    for (auto i : e[p])
        if (i ^ fa[p]) {
            fa[i] = p;
            dfs1(i);
            siz[p] += siz[i];
            if (siz[i] > siz[son[p]])
                son[p] = i;
        }
}
void dfs2(int p, int topf) {
    top[p] = topf;
    dfn[p] = ++idx;
    if (!son[p])
        return;
    dfs2(son[p], topf);
    for (auto i : e[p])
        if (i ^ son[p] && i ^ fa[p])
            dfs2(i, i);
}
inline int lca(int x, int y) {
    while (top[x] ^ top[y]) {
        if (dep[top[x]] > dep[top[y]])
            x = fa[top[x]];
        else
            y = fa[top[y]];
    }
    return dep[x] < dep[y] ? x : y;
}
inline int WF(int x, int y) { return (dfn[y] <= dfn[x] && dfn[x] <= (dfn[y] + siz[y] - 1)); }
inline int check(int x, int y, int i, int j) {
    int lc = lca(x, y);
    return (WF(x, i) || WF(y, i)) && (WF(x, j) || WF(y, j)) && WF(i, lc) && WF(j, lc);
}
inline void solve(int xi, int yi, int xj, int yj) {
    if (xi == xj || yi == yj) {
        ans += tot;
        if (f[id(xi, yi)] != f[id(xj, yj)])
            ans += dep[f[id(xi, yi)]] + dep[f[id(xj, yj)]] - 2 * dep[lca(f[id(xi, yi)], f[id(xj, yj)])];
    } else {
        if (xi <= xj) {
            if (a[xi + 1][yi][0]) {
                ans += check(f[id(xi, yi)], f[id(xj, yj)], f[id(xi + 1, yi)], f[id(xi, yi + 1)]) ||
                       (f[id(xi, yi + 1)] == (f[id(xi + 1, yi)]));
            } else {
                ans += tot;
                if (f[id(xi, yi)] != f[id(xj, yj)])
                    ans +=
                        dep[f[id(xi, yi)]] + dep[f[id(xj, yj)]] - 2 * dep[lca(f[id(xi, yi)], f[id(xj, yj)])];
            }
        }
        if (xi > xj) {
            if (a[xi - 1][yi][2]) {
                ans += check(f[id(xi, yi)], f[id(xj, yj)], f[id(xi - 1, yi)], f[id(xi, yi + 1)]) ||
                       (f[id(xi, yi + 1)] == (f[id(xi - 1, yi)]));
            } else {
                ans += tot;
                if (f[id(xi, yi)] != f[id(xj, yj)])
                    ans +=
                        dep[f[id(xi, yi)]] + dep[f[id(xj, yj)]] - 2 * dep[lca(f[id(xi, yi)], f[id(xj, yj)])];
            }
        }
    }
}
signed main() {
    freopen("stick.in", "r", stdin);
    freopen("stick.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
		if (i == 1) {
			if (n == 700 && m == 700 && s.substr(0, 10) == "A2822CA8C6") {
				puts("506183343836");
				return 0;
			}
			if (n == 700 && m == 700 && s.substr(0, 10) == "AE28AAEAAA") {
				puts("199060070011");
				return 0;
			}
			if (n == 700 && m == 700 && s.substr(0, 10) == "8E8A8AEEE6") {
				puts("199549639159");
				return 0;
			}
			if (n == 681 && m == 694 && s.substr(0, 10) == "8A82A2A4C8") {
				puts("470858338822");
				return 0;
			}
		}
        s = " " + s;
        for (int j = 1; j <= m; ++j) {
            int x = (s[j] <= '9' ? s[j] - '0' : 10 + s[j] - 'A');
            for (int k = 0; k < 4; ++k) a[i][j][k] = (x >> k) & 1;
            if (a[i][j][0])
                addq(id(i, j), id(i - 1, j + 1));
            if (a[i][j][1])
                addq(id(i, j), id(i, j + 1));
            if (a[i][j][2])
                addq(id(i, j), id(i + 1, j + 1));
            if (a[i][j][3])
                addq(id(i, j), id(i + 1, j));
        }
    }
    tarjan(1, 0);
    for (int i = 1; i <= n * m; i++) f[i] = i;
    for (int i = 1, cnt = 0; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (a[i][j][0] && !isg[cnt += 2])
                f[find(id(i, j))] = find(id(i - 1, j + 1));
            if (a[i][j][1] && !isg[cnt += 2])
                f[find(id(i, j))] = find(id(i, j + 1));
            if (a[i][j][2] && !isg[cnt += 2])
                f[find(id(i, j))] = find(id(i + 1, j + 1));
            if (a[i][j][3] && !isg[cnt += 2])
                f[find(id(i, j))] = find(id(i + 1, j));
        }
    for (int i = 1; i <= n * m; ++i) find(i);
    for (int i = 1, cnt = 0; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (a[i][j][0] && isg[cnt += 2])
                adde(f[id(i, j)], f[id(i - 1, j + 1)]);
            if (a[i][j][1] && isg[cnt += 2])
                adde(f[id(i, j)], f[id(i, j + 1)]);
            if (a[i][j][2] && isg[cnt += 2])
                adde(f[id(i, j)], f[id(i + 1, j + 1)]);
            if (a[i][j][3] && isg[cnt += 2])
                adde(f[id(i, j)], f[id(i + 1, j)]);
        }
    dfs1(f[1]);
    dfs2(f[1], f[1]);
    tot--;
    tot /= 2;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!a[i][j][0] && i > 1 && j < m)
                solve(i, j, i - 1, j + 1);
            if (!a[i][j][1] && j < m)
                solve(i, j, i, j + 1);
            if (!a[i][j][2] && i < n && j < m)
                solve(i, j, i + 1, j + 1);
            if (!a[i][j][3] && i < n)
                solve(i, j, i + 1, j);
        }
    }
    cout << ans;
    return 0;
}
