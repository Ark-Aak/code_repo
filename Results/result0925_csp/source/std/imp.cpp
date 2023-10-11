#include<bits/stdc++.h>
using namespace std;
#define For(i, j, k) for ( int i = (j) ; i <= (k) ; i++ )
#define Fol(i, j, k) for ( int i = (j) ; i >= (k) ; i-- )
using ll = long long;
constexpr ll inf = (ll)1e18;
int n, m, x, y, l[250009], r[250009], c[250009], num[500009]; ll ans;
vector < pair < int, int > > op[500009];
struct SEGMENT_TREE
{
	struct node { ll v, lz; } t[500009 << 2];
	inline int lc(int x) { return x << 1; }
	inline int rc(int x) { return ( x << 1 ) | 1; }
	inline int md(int x, int y) { return ( x + y ) >> 1; }
	inline void pu(int p) { t[p].v = max(t[lc(p)].v, t[rc(p)].v); }
	inline void pd(int p)
	{
		if ( !t[p].lz ) return;
		t[lc(p)].v += t[p].lz, t[rc(p)].v += t[p].lz,
		t[lc(p)].lz += t[p].lz, t[rc(p)].lz += t[p].lz, t[p].lz = 0;
	}
	inline void build(int p, int l, int r)
	{
		if ( l == r ) { t[p].v = -num[l]; return; }
		build(lc(p), l, md(l, r)), build(rc(p), md(l, r) + 1, r), pu(p);
	}
	inline void add(int p, int l, int r, int lp, int rp, ll v)
	{
		if ( l > rp || r < lp ) return;
		if ( lp <= l && r <= rp ) { t[p].v += v, t[p].lz += v; return; }
		pd(p), add(lc(p), l, md(l, r), lp, rp, v), add(rc(p), md(l, r) + 1, r, lp, rp, v), pu(p);
	}
	inline ll qry(int p, int l, int r, int lp, int rp)
	{
		if ( l > rp || r < lp ) return -inf;
		if ( lp <= l && r <= rp ) return t[p].v;
		return pd(p), max(qry(lc(p), l, md(l, r), lp, rp), qry(rc(p), md(l, r) + 1, r, lp, rp));
	}
}	t;
int main()
{
	freopen("imp.in", "r", stdin), freopen("imp.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n;
	For(i, 1, n) cin >> x >> y >> c[i], num[++m] = l[i] = min(x, y), num[++m] = r[i] = max(x, y);
	sort(num + 1, num + m + 1), m = unique(num + 1, num + m + 1) - num - 1;
	For(i, 1, n)
	{
		l[i] = lower_bound(num + 1, num + m + 1, l[i]) - num;
		r[i] = lower_bound(num + 1, num + m + 1, r[i]) - num;
		op[l[i]].emplace_back(r[i], c[i]);
	}
	t.build(1, 1, m);
	Fol(i, m, 1)
	{
		for ( auto j : op[i] ) t.add(1, 1, m, j.first, m, j.second);
		ans = max(ans, num[i] + t.qry(1, 1, m, i, m));
	}
	return cout << ans << '\n', 0;
}