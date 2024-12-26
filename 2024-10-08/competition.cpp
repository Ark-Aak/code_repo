#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define int ll

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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, m;
int l[MAXN], r[MAXN];
vector <int> h;

int find(int x) {
	return lower_bound(h.begin(), h.end(), x) - h.begin() + 1;
}

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

vector <int> pt[MAXN << 1], del[MAXN << 1];
set <int> s;
int neg_prob;
const int inv = qpow(2, MOD - 2);

#define val(x) (((x) * ((x) + 1) % MOD * inv) % MOD)

inline int pans() {
	int p = n * (n + 1) % MOD * inv % MOD - neg_prob;
	// de(p);
	return p * qpow(n * (n + 1) % MOD * inv % MOD, MOD - 2) % MOD;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("competition.in", "r", stdin);
	freopen("competition.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	rep (i, 1, n) l[i] = read(), r[i] = read();
	rep (i, 1, n) h.emplace_back(l[i]), h.emplace_back(r[i]);
	sort(h.begin(), h.end());
	h.erase(unique(h.begin(), h.end()), h.end());
	const int N = h.size();
	rep (i, 1, n) {
		pt[find(l[i])].push_back(i);
		del[find(r[i])].push_back(i);
	}
	neg_prob = n * (n + 1) % MOD * inv % MOD;
	s.insert(0), s.insert(n + 1);
	int ans = 0;
	rep (i, 1, N) {
		for (auto p : pt[i]) {
			auto iter = s.lower_bound(p);
			auto piter = prev(iter);
			int pv = *piter, nx = *iter;
			int len = nx - pv - 1;
			neg_prob -= val(len);
			neg_prob += val(p - pv - 1);
			neg_prob += val(nx - p - 1);
			neg_prob %= MOD;
			neg_prob = (neg_prob + MOD) % MOD;
			s.insert(p);
		}
		ans += pans();
		ans %= MOD;
		// cout << i << "-1:" << endl;
		// cout << "neg:" << neg_prob << endl;
		// cout << "pans:" << pans() << endl;
		if (i == N) break;
		for (auto p : del[i]) {
			s.erase(p);
			auto iter = s.lower_bound(p);
			auto piter = prev(iter);
			int pv = *piter, nx = *iter;
			int len = nx - pv - 1;
			neg_prob += val(len);
			neg_prob -= val(p - pv - 1);
			neg_prob -= val(nx - p - 1);
			neg_prob %= MOD;
			neg_prob = (neg_prob + MOD) % MOD;
		}
		// cout << i << "-2:" << endl;
		// cout << "neg:" << neg_prob << endl;
		// cout << "pans:" << pans() << endl;
		// cout << "len:" << h[i] - h[i - 1] - 1 << endl;
		// cout << "h:" << h[i] << " " << h[i - 1] << endl;
		ans += ((h[i] - h[i - 1] - 1) % MOD * (pans())) % MOD;
		ans %= MOD;
	}
	print((ans + MOD) % MOD);
	return 0;
}
