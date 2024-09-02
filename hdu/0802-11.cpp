#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int ch[30], n;

int comp(int n) {
	int res = 0;
	rep (i, 1, n) res <<= 1, res |= ch[i];
	return res;
}

unordered_map <int, int> umap;

void dfs() {
	if (umap[comp(n)]) return;
	umap[comp(n)] = 1;
	dfs();
	rep (step, 1, n) {
		ch[step] = !ch[step];
		ch[step - 1] = !ch[step - 1];
		ch[step + 1] = !ch[step + 1];
		dfs();
	}
}

const int MOD = 998244353;

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

signed main() {
	int T = read();
	while (T --> 0) {
		int n = read();
		int cnt = n / 3;
		ll ans = qpow(8, cnt);
		int r = n % 3;
		if (r) ans = (ans * 2) % MOD;
		print(ans); puts("");
	}
	return 0;
}
