#include <bits/stdc++.h>
using namespace std;
#define fo(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)
typedef long long ll;
const int N = 1000010;
int n, l, r, k;
ll f[N], inf = 1e18, a[N];
struct line {
    ll k, b;
    line() {}
    line(ll _k, ll _b) : k(_k), b(_b) {}
    ll f(ll x) { return k ? k * x + b : inf; }
} t[N << 2];
ll qry(int p, int l, int r, int k) {
    ll res = t[p].f(a[k]);
    int mid = l + r >> 1;
    if (l < r)
        res = min(res, k <= mid ? qry(p << 1, l, mid, k) : qry(p << 1 | 1, mid + 1, r, k));
    return res;
}
void upd(int p, int l, int r, line tmp) {
    if (!t[p].k)
        return t[p] = tmp, void();
    int mid = l + r >> 1;
    if (t[p].f(a[mid]) > tmp.f(a[mid]))
        swap(t[p], tmp);
    if (l < r)
        t[p].f(a[l]) > tmp.f(a[l]) ? upd(p << 1, l, mid, tmp) : upd(p << 1 | 1, mid + 1, r, tmp);
}
void ins(int p, int l, int r, int ll, int rr, line tmp) {
    if (l > rr || r < ll)
        return;
    if (l >= ll && r <= rr)
        return upd(p, l, r, tmp);
    int mid = l + r >> 1;
    ins(p << 1, l, mid, ll, rr, tmp), ins(p << 1 | 1, mid + 1, r, ll, rr, tmp);
}
int main() {
    fo("elevator");
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i]--;
    sort(a + 1, a + 1 + n), ins(1, 1, n, 1, k, line(n, 0));
    for (int i = 1; i < n; i++)
        ins(1, 1, n, i + 1, min(i + k, n), line(n - i, qry(1, 1, n, i)));
    printf("%lld\n", qry(1, 1, n, n) * 2);
    return 0;
}