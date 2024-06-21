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

int k, tp = 1, cnt = 1, nw = 0;
const int MAXN = 5e3 + 5;
vector <pii> G[MAXN];
int w[MAXN], f[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("myth.in", "r", stdin);
	freopen("myth.out", "w", stdout);
#endif
#endif
	k = read();
	if (__builtin_popcount(k) == 1) return puts("-1"), 0;
	while ((k & 1) == 0) tp <<= 1, k >>= 1;
	int sh = 0, th = 1;
	G[1].push_back({ 0, 1 });
	while (sh + th <= k) {
		sh += th;
		G[nw].push_back({ ++cnt, k - th});
		f[cnt] = nw;
		G[nw].push_back({ ++cnt, th});
		f[cnt] = nw;
		G[nw].push_back({ ++cnt, k - th});
		f[cnt] = nw;
		G[nw].push_back({ ++cnt, th});
		f[cnt] = nw;
		w[cnt - 2] = th;
		th <<= 1;
		nw = cnt - 2;
	}
	nw = f[nw];
	th >>= 1;
	while (sh < k) {
		while (sh + (w[nw] << 1) <= k) {
			sh += (w[nw] << 1);
			th += w[nw];
			G[f[nw]].push_back({ ++cnt, k - th });
			G[f[nw]].push_back({ ++cnt, th });
			th += w[nw];
			G[nw].push_back({ ++cnt, k - th });
			G[nw].push_back({ ++cnt, th });
		}
		th += w[nw];
		nw = f[nw];
	}
	cout << cnt + 1 << endl;
	rep (i, 0, cnt) {
		for (auto [v, w] : G[i]) {
			cout << (i == 0 ? cnt + 1 : i) << " " << (v == 0 ? cnt + 1 : v) << " " << w * tp << endl;
		}
	}
	return 0;
}
