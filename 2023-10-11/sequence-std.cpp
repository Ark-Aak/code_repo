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

const int MAXN = 2e3 + 5, MAXM = 1e5 + 5;
const int MOD = 998244353;
int n, m, f[MAXN][MAXN];
vector <int> g[MAXM];

void Mod(int &x) {
	if (x >= MOD) x -= MOD;
	if (x < 0) x += MOD;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
#endif
#endif
	read(n), read(m);
	int sum = m;
	rep (i, 1, m) f[n][i] = 1;
	rep (i, 1, m) rep (j, 1, m) {
		if (i > j && i % j == 0) {
			g[i].emplace_back(j);
		}
	}
	_rep (i, n - 1, 1) {
		rep (j, 1, m) f[i][j] += sum, Mod(f[i][j]);
		rep (j, 1, m) {
			for (auto k : g[j]) f[i][j] -= f[i + 1][k], Mod(f[i][j]);
		}
		sum = 0;
		rep (j, 1, m) sum += f[i][j], Mod(sum);
	}
	int ans = 0;
	rep (i, 1, m) ans += f[1][i], Mod(ans);
	rep (i, 1, m) {
		rep (j, 1, n) print(f[j][i]), putchar('\t');
		putchar(10);
	}
	print(ans);
	return 0;
}
