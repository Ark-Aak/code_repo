#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

const int MAXN = 2e5 + 5;
int n, p[MAXN], a[MAXN];
vector <int> G[MAXN];
bool vis[MAXN];
int idx[MAXN];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

pair <int, vector <pii> > get_gcd(int val) {
	vector <pii> fac;
	rep (i, 2, sqrt(val)) {
		int pw = 0;
		while (val % i == 0) pw++, val /= i;
		if (pw > 0) fac.push_back(dl(i, pw));
	}
	if (val) fac.push_back(dl(val, 1));
	vector <pii> tmp = fac;
	for (auto &p : fac) {
		p.fb = min((ll) p.fb, idx[p.ec]);
	}
	int res = 1;
	for (auto [bs, pw] : fac) {
		res *= qpow(bs, pw);
	}
	rep (i, 0, tmp.size() - 1) {
		tmp[i].fb = tmp[i].fb - fac[i].fb;
	}
	return dl(res, tmp);
}

int rem[MAXN];
vector <int> df;

void insert(vector <pii> &v) {
	vector <int> val;
	for (auto [bs, pw] : v) {
		val.push_back(qpow(bs, pw));
		idx[bs] += pw;
	}
	for (auto v : val) {
		for (auto ps : df) {
			rem[ps] = rem[ps] * v % ps;
		}
	}
}

int len;
vector <int> cir;
int dis[MAXN];

void dfs(int u) {
	++len;
	vis[u] = 1;
	cir.push_back(u);
	for (auto v : G[u]) if (!vis[v]) dfs(v);
}

void getdis(int u) {
	dis[u] = 1;
	for (auto v : G[u]) if (!dis[v]) getdis(v), dis[u] = dis[v] + 1;
}

int ans[MAXN], mk[MAXN];
int steps[MAXN];

void update_step(int a) {
	for (auto ps : df) {
		steps[ps] = (steps[ps] + rem[ps] * a) % ps;
	}
}

signed main() {
	n = read();
	rep (i, 1, n) p[i] = read();
	rep (i, 1, n) a[i] = read();
	rep (i, 1, n) G[p[i]].push_back(i);
	rep (i, 1, n) {
		if (vis[i]) continue;
		len = 0;
		vector <int>().swap(cir);
		dfs(i);
		df.push_back(len);
	}
	sort(df.begin(), df.end());
	df.erase(unique(df.begin(), df.end()), df.end());
	memset(vis, 0, sizeof vis);
	rep (i, 0, n) rem[i] = 1;
	rep (i, 1, n) {
		if (vis[i]) continue;
		len = 0;
		vector <int>().swap(cir);
		dfs(i);
		auto val = get_gcd(len);
		vector <pii> ins;
		ins.swap(val.fb);
		int gval = val.ec;
		vector <int> ccir;
		int r = steps[len];
		rep (i, r, cir.size() - 1) ccir.push_back(cir[i]);
		for (auto val : cir) ccir.push_back(val);
		rep (i, 0, r - 1) ccir.push_back(cir[i]);
		getdis(ccir[0]);
		dis[ccir[0]] = 0;
		int ps = 0, mxval = 1e9;
		for (auto i = 0; i < len; i += gval) {
			if (a[ccir[i]] < mxval) ps = i, mxval = a[ccir[i]];
		}
		int pos = 0, cnt = 0;
		do {
			pos = (pos + rem[len]) % len;
			if (pos == 0) break;
			mk[pos] = ++cnt;
		} while (pos != 0);
		update_step(mk[ps]);
		insert(ins);
		rep (i, ps, ps + len - 1) {
			ans[cir[i - ps]] = a[ccir[i]];
		}
	}
	rep (i, 1, n) print(ans[i]), putchar(32);
	puts("");
	return 0;
}
