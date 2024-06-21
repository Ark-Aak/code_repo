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

const int MAXN = 1e5 + 5;
const int BK = 2.5e4;
const int BS = 1000;

int n, m, q;
vector <int> G[MAXN];
int cnt, bel[MAXN], l[BS + 5], r[BS + 5];
int op[MAXN], x[MAXN], y[MAXN], id[MAXN];
int val0[BS + 5][MAXN], val1[MAXN], lstvis[MAXN], now;

int L, R;
bitset <BK + 5> reach[MAXN];
bitset <MAXN> rvis;

void do_ops_2(int u, int val, int qid) {
	if (lstvis[u] == now) return;
	val0[now][u] = val;
	lstvis[u] = now;
	id[u] = qid;
	for (auto v : G[u]) {
		do_ops_2(v, val, qid);
	}
}

void get_reach(int u) {
	if (rvis[u]) return;
	rvis[u] = 1;
	reach[u].reset();
	if (L <= u && u <= R) reach[u][u - L + 1] = 1;
	for (auto v : G[u]) {
		get_reach(v);
		reach[u] |= reach[v];
	}
}

void cover(int u, int val, int qid) {
	if (lstvis[u] == now) return;
	val1[u] = val;
	lstvis[u] = now;
	id[u] = qid;
	for (auto v : G[u]) {
		cover(v, val, qid);
	}
}

int ans[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("dag.in", "r", stdin);
	freopen("dag.out", "w", stdout);
#endif
#endif
	n = read(), m = read(), q = read();
	rep (i, 1, m) {
		int u = read(), v = read();
		G[u].push_back(v);
	}
	cnt = q / BS + !!(q % BS);
	memset(l, 0x3f, sizeof l);
	rep (i, 1, q) {
		bel[i] = (i - 1) / BS + 1;
		l[bel[i]] = min(l[bel[i]], i);
		r[bel[i]] = max(r[bel[i]], i);
		op[i] = read(), x[i] = read();
		if (op[i] != 3) y[i] = read();
	}
	rep (i, 1, cnt) {
		rep (j, 1, n) val0[i][j] = 2e9;
		vector <tuple <int, int, int> > stk;
		rep (j, l[i], r[i]) {
			if (op[j] == 2) {
				stk.push_back(dk(y[j], x[j], j));
			}
		}
		now++;
		sort(stk.begin(), stk.end());
		for (auto [val, id, qid] : stk) do_ops_2(id, val, qid);
	}
	for (int _i = 1; _i <= n; _i += BK) {
		L = _i; R = min(n, L + BK - 1);
		rvis.reset();
		memset(val1, 0, sizeof val1);
		memset(id, 0, sizeof id);
		rep (i, 1, n) get_reach(i);
		vector <tuple <int, int, int> > stk;
		rep (i, 1, q) {
			if (op[i] == 1) {
				stk.push_back(dk(y[i], x[i], i));
				if (stk.size() == BS) {
					++now;
					for (auto it = stk.rbegin(); it != stk.rend(); it++) {
						cover(get <1>(*it), get <0>(*it), get <2>(*it));
					}
					vector <tuple <int, int, int> >().swap(stk);
				}
				assert(stk.size() < BS);
			}
			else if (op[i] == 3 && L <= x[i] && x[i] <= R) {
				int res = val1[x[i]];
				int l = id[x[i]] + 1, r = i - 1;
				for (auto it = stk.rbegin(); it != stk.rend(); it++) {
					if (!reach[x[get <2>(*it)]][x[i] - L + 1]) continue;
					l = get <2>(*it) + 1;
					res = y[get <2>(*it)];
					break;
				}
				if (l <= r) {
					const auto update = [&](int i, int j) {
						if (op[j] == 2 && reach[x[j]][x[i] - L + 1]) res = min(res, y[j]);
					};
					if (bel[l] == bel[r]) rep (j, l, r) update(i, j);
					else {
						int cnt = 0;
						for (int j = l; j <= r && bel[j] == bel[l]; j++) update(i, j), cnt++;
						for (int j = r; j >= l && bel[j] == bel[r]; j--) update(i, j), cnt++;
						rep (j, bel[l] + 1, bel[r] - 1) res = min(res, val0[j][x[i]]), cnt++;
					}
				}
				ans[i] = res;
			}
		}
	}
	rep (i, 1, q) if (op[i] == 3) print(ans[i]), puts("");
	return 0;
}
