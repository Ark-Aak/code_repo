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

const int MAXN = 355;
int n, K, a[MAXN];
int f[2][MAXN][MAXN];

int dfs(bool w, int l, int r, int k1, int k2) {
	if (f[w][l][r] != -1) return f[w][l][r];
	if (k1 >= K && w) return 1;
	if (k2 >= K && w) return 0;
	if (k1 >= K && (!w)) return 0;
	if (k2 >= K && (!w)) return 1;
	if (l > r) return 0;
	if (l == r) {
		if (!w) k1 += a[l];
		else k2 += a[l];
		if (!w) return f[w][l][r] = (k1 < K);
		else return f[w][l][r] = (k2 < K);
	}
	int L = 0, R = 0;
	if (!w) L = f[!w][l + 1][r] = dfs(!w, l + 1, r, k1 + a[l], k2);
	if (!w) R = f[!w][l][r - 1] = dfs(!w, l, r - 1, k1 + a[r], k2);
	if (w) L = f[!w][l + 1][r] = dfs(!w, l + 1, r, k1, k2 + a[l]);
	if (w) R = f[!w][l][r - 1] = dfs(!w, l, r - 1, k1, k2 + a[r]);
	return f[w][l][r] = (!min(L, R));
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("beach.in", "r", stdin);
	freopen("beach.out", "w", stdout);
#endif
#endif
	memset(f, -1, sizeof f);
	read(n), read(K);
	rep (i, 1, n) {
		char c; scanf("%c", &c);
		if (c == 'P') a[i] = 0;
		else a[i] = 1;
	}
	if (dfs(0, 1, n, 0, 0)) {
		cout << "DA";
	}
	else cout << "NE";
	return 0;
}
