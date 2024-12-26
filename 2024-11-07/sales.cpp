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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int MAXN = 2e5 + 5;
int n, s[MAXN], a[MAXN], aans[MAXN];
int f[5005][5005], sans[5005];
vector <int> hosts[MAXN];
vector <int> h;



signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("sales.in", "r", stdin);
	freopen("sales.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) s[i] = read(), h.push_back(s[i]);
	sort(h.begin(), h.end());
	h.erase(unique(h.begin(), h.end()), h.end());
	rep (i, 1, n) s[i] = lower_bound(h.begin(), h.end(), s[i]) - h.begin() + 1;
	rep (i, 1, n) a[i] = read(), hosts[s[i]].push_back(i);
	const int S = h.size();
	rep (i, 1, S) sort(hosts[i].begin(), hosts[i].end(), [](int pa, int pb) { return a[pa] < a[pb]; });
	if (n <= 5000) {
		memset(f, 0x3f, sizeof f);
		memset(sans, 0x7f, sizeof sans);
		f[0][0] = 0;
		rep (i, 1, S) {
			int dis = h[i - 1] - (i == 1 ? 0 : h[i - 2]);
			rep (k, 0, n) f[i][k] = min(f[i][k], f[i - 1][k] + dis);
			for (auto j : hosts[i]) {
				_rep (k, n, 1) {
					f[i][k] = min(f[i][k], f[i][k - 1] + a[j]);
				}
			}
			rep (k, 1, n) sans[k] = min(sans[k], f[i][k] + h[i - 1]);
		}
		rep (i, 1, n) print(sans[i]), puts("");
		return 0;
	}
	else {
	int ptr = 0, sum = 0;
	multiset <int> ss;
	rep (i, 1, S) {
		sum += (h[i - 1] - (i > 1 ? h[i - 2] : 0)) * 2;
		for (auto j : hosts[i]) ss.insert(a[j]);
		if (i != S) {
			int ndis = (h[i] - h[i - 1]) * 2;
			while (ss.size() && ndis + a[hosts[i + 1][0]] > (*ss.begin())) {
				sum += *ss.begin();
				aans[++ptr] = sum;
				ss.erase(ss.begin());
			}
		}
		else {
			while (ss.size()) {
				sum += *ss.begin();
				aans[++ptr] = sum;
				ss.erase(ss.begin());
			}
		}
	}
	rep (i, 1, n) print(aans[i]), puts("");
	}
	return 0;
}
