#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 200010, M = 2000010, MOD = 1e9 + 7;

struct node {
    ll deg, cnt;
}nd[N];
int tot;

int n, m, deg[N], cnt[M];
ll ans;

int main() {
    freopen("gen.in", "r", stdin);
    freopen("gen.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= m; ++i) cin >> u >> v, ++deg[u], ++deg[v];
    for(int i = 1; i <= n; ++i) ++cnt[deg[i]];
    for(int i = 1; i <= m; ++i) if(cnt[i]) nd[++tot].deg = i, nd[tot].cnt = cnt[i];
    for(int i = 1; i <= tot; ++i) {
        for(int j = i + 1; j <= tot; ++j) {
            ll t = (nd[i].deg ^ nd[j].deg) * (nd[i].deg | nd[j].deg) * (nd[i].deg & nd[j].deg) % MOD;
            ans = (ans + t * nd[i].cnt * nd[j].cnt) % MOD;
        }
    }
    cout << ans;
    return 0;
}