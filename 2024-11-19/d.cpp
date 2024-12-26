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

const int MOD = 1e9 + 7;
const int MAXN = 30;
int n, ns;
int ord[MAXN], vis[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
#endif
#endif
	n = read(), ns = read();
	if (ns == 0) {
		int res = 1;
		rep (i, 1, 1 << n) {
			res = res * i % MOD;
		}
		print(res), puts("");
		return 0;
	}
	rep (i, 1, ns) vis[read()] = 1;
	rep (i, 1, 1 << n) {
		ord[i] = i;
	}
	int ans = 0;
	do {
		vector <int> s;
		rep (i, 1, 1 << n) s.push_back(ord[i]);
		rep (i, 1, n) {
			vector <int> res;
			rep (j, 1, (int) s.size() / 2) {
				int a = 2 * j - 2, b = 2 * j - 1;
				if (s[a] >= 2 && s[b] >= 2) {
					res.push_back(min(s[a], s[b]));
				}
				else {
					if (s[a] == 1 && vis[s[b]]) res.push_back(s[b]);
					else if (s[b] == 1 && vis[s[a]]) res.push_back(s[a]);
					else res.push_back(1);
				}
			}
			s.swap(res);
		}
		if (s[0] == 1) ans++;
		ans %= MOD;
	} while (next_permutation(ord + 1, ord + 1 + (1 << n)));
	print(ans); puts("");
	return 0;
}
