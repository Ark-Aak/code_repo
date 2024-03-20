#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7, MAXN = 2e6 + 5;
vector<int> pre, fa;
map<vector<int>, int> id;
int m, n, k, pw[MAXN], to1[MAXN], to2[MAXN], tot;
int f[MAXN], g[MAXN], v[MAXN];
int find(int x) {
    if (x == fa[x])
        return x;
    return fa[x] = find(fa[x]);
}
int ksm(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}
vector<int> change(vector<int> p) {
    vector<int> nw(k - 1);
    for (int i = 1; i < k; i++) nw[i - 1] = p[i] - 1;
    for (int i = 0; i < k - 1; i++) {
        if (nw[i] < 0)
            for (int j = i; j < k - 1; j++) {
                if (nw[j] < 0)
                    nw[j] = i;
            }
    }
    return nw;
}
int dfs(vector<int> p) {
    if (id.find(p) != id.end())
        return id[p];
    int res = ++tot;
    id[p] = tot;
    vector<int> nxt = p;
    nxt.push_back(k - 1);
    fa[k - 1] = k - 1;
    for (int i = 0; i < k - 1; i++) fa[i] = p[i];
    int i = 0, j = k - 1;
    while (i < j) {
        int U = find(i);
        int V = find(j);
        if (U != V) {
            if (U < V)
                fa[V] = U;
            else
                fa[U] = V;
            ++v[res];
        }
        ++i, --j;
    }

    v[res] = mod - pw[v[res]];
    to2[res] = dfs(change(fa));
    to1[res] = dfs(change(nxt));
    return res;
}
signed main() {
    scanf("%lld %lld %lld", &m, &n, &k);
    if (n < k) {
        int ans = 1;
        for (int i = 1; i <= n; i++) ans = (ans * m) % mod;
        printf("%lld\n", ans);
        return 0;
    }
    fa.resize(k);
    pw[0] = 1;
    for (int i = 1; i <= n; i++) pw[i] = ksm(ksm(m, mod - 2), i);
    for (int i = 0; i < k - 1; i++) pre.push_back(i);
    f[dfs(pre)] = 1;
    for (int i = n - k + 1; i; i--) {
        for (int j = 1; j <= tot; j++) g[j] = f[j], f[j] = 0;
        for (int j = 1; j <= tot; j++) {
            if (g[j]) {
                f[to1[j]] = (f[to1[j]] + g[j]) % mod;
                f[to2[j]] = (f[to2[j]] + g[j] * v[j] % mod + 2 * mod) % mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= tot; i++) ans = (ans + f[i] + 2 * mod) % mod;
    for (int i = 1; i <= n; i++) ans = (ans * m) % mod;
    printf("%lld", ans);
    return 0;
}
