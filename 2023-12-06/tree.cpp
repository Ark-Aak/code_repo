#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

const int MOD = 1e9 + 7;

int qpow(int a, int b, int p) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

const int MAXN = 5e5 + 5;

int n, ans;
pii edges[MAXN];
int perm[15], tar[MAXN], val[MAXN];
unordered_map <string, bool> vis;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif
#endif
	read(n);
	rep (i, 1, n - 1) read(edges[i].first), read(edges[i].second);
	rep (i, 1, n) read(tar[i]);
	if (n <= 10) {
		rep (i, 1, n - 1) perm[i] = i;
		do {
			bool flg = 0;
			rep (i, 1, n) val[i] = i;
			rep (i, 1, n - 1) swap(val[edges[perm[i]].first], val[edges[perm[i]].second]);
			rep (i, 1, n) if (tar[i] != 0 && val[i] != tar[i]) {
				flg = 1;
				break;
			}
			if (flg) continue;
			stringstream h;
			rep (i, 1, n) h << val[i];
			if (!vis.count(h.str())) ++ans, vis[h.str()] = 1;
			if (ans >= MOD) ans -= MOD;
		} while (next_permutation(perm + 1, perm + n));
		print(ans), putchar(10);
		return 0;
	}
	return 0;
}
