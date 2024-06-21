#include <bits/stdc++.h>
#define int ll
#define Gc() getchar()
#define Me(x, y) memset(x, y, sizeof(x))
#define Mc(x, y) memcpy(x, y, sizeof(x))
#define d(x, y) ((m) * (x - 1) + (y))
#define R(n) (rnd() % (n) + 1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
using namespace std;
using ll = long long;
using db = double;
using lb = long db;
using ui = unsigned;
using ull = unsigned long long;
using pii = pair<int, int>;
using LL = __int128;
const int N = 2e5 + 5, M = N * 60 + 5, K = 600 + 5, mod = 998244353, Mod = mod - 1;
const db eps = 1e-9;
const int INF = 1e9 + 7;
mt19937 rnd(263082);
int n, m, Ns[N], Nh, Ro[N];
pii A[N];

namespace Tree
{
    int L[M], R[M], Ct;
    ll f[M], Sum[M];
    void CP(int &v)
    {
        f[++Ct] = f[v];
        Sum[Ct] = Sum[v];
        L[Ct] = L[v];
        R[Ct] = R[v];
        v = Ct;
    }
    void Ins(int x, int &v, int l = 1, int r = Nh)
    {
        CP(v);
        f[v]++;
        Sum[v] += Ns[x];
        if (l == r)
            return;
        int m = l + r >> 1;
        x <= m ? Ins(x, L[v], l, m) : Ins(x, R[v], m + 1, r);
    }
    ll qry(int z, int v, int l = 1, int r = Nh)
    {
        if (l == r)
            return 1ll * z * Ns[l];
        int m = l + r >> 1;
        if (f[L[v]] >= z)
            return qry(z, L[v], l, m);
        else
            return Sum[L[v]] + qry(z - f[L[v]], R[v], m + 1, r);
    }
}
ll ans[N];

void calc(int x, int y, int l, int r)
{
    if (l > r || x > y)
        return;
    int m = l + r >> 1, p = 0;
    ans[m] = 1e18 + 7;
    for (int i = max(x, m); i <= y; i++)
    {
        ll w = A[i].fi + Tree::qry(m, Ro[i]);
        if (w < ans[m])
            ans[m] = w, p = i;
    }
    calc(x, p, l, m - 1);
    calc(p, y, m + 1, r);
}

void Solve()
{
    int i, j;
    scanf("%lld", &n);
    for (i = 1; i <= n; i++)
        scanf("%lld%lld", &A[i].se, &A[i].fi), A[i].se = -A[i].se;
    for (i = 1; i <= n; i++)
        Ns[++Nh] = A[i].se;
    sort(Ns + 1, Ns + Nh + 1);
    Nh = unique(Ns + 1, Ns + Nh + 1) - Ns - 1;
    for (i = 1; i <= n; i++)
        A[i].se = LB(Ns + 1, Ns + Nh + 1, A[i].se) - Ns;
    sort(A + 1, A + n + 1);
    for (i = 1; i <= n; i++)
        Ro[i] = Ro[i - 1], Tree::Ins(A[i].se, Ro[i]);
    calc(1, n, 1, n);
    for (i = 1; i <= n; i++)
        printf("%lld\n", -ans[i]);
}

signed main()
{
    // freopen("order.in", "r", stdin);
    // freopen("order.out", "w", stdout);
    int t = 1;
    while (t--)
        Solve();
    /* cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n'; */
}
