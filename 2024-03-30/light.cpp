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

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
int T, n, ans[MAXN];
string s;
int ch[MAXN];
int f[MAXN][2];

void calc() {
	int flg = 0;
	rep (i, 1, n) {
		if (!flg) f[i][ch[i] ^ 1] = 1, f[i][ch[i]] = 1e9;
		else f[i][ch[i]] = f[i - 1][0] + 2, f[i][ch[i] ^ 1] = f[i - 1][1] + 4;
		flg += ch[i];
	}
	flg = 0;
	int g0 = 0, g1 = 3;
	_rep (i, n, 1) {
		int nu = 1 + (ch[i] ? g0 : g1), nv = 3 + (ch[i] ? g1 : g0);
		ans[i] = min(ans[i], min(g0 + f[i][0], g1 + f[i][1])) % MOD;
		flg += ch[i];
		g0 = nu, g1 = nv;
		if (!flg) g0 = 0, g1 = 3;
		if (flg == 1 && ch[i] == 1) g1 = 2;
	}
}

void solve() {
	cin >> n;
	cin >> s;
	bool flg = 0;
	for (auto c : s) flg |= (c ^ 48);
	if (!flg) return puts("0"), void();
	rep (i, 1, n) ch[i] = s[i - 1] - '0';
	rep (i, 0, n + 1) ans[i] = 1e9;
	calc();
	reverse(ch + 1, ch + 1 + n);
	reverse(ans + 1, ans + 1 + n);
	calc();
	reverse(ch + 1, ch + 1 + n);
	reverse(ans + 1, ans + 1 + n);
	int fans = 0;
	rep (i, 1, n) fans = (fans + 1ll * i * min(ans[i - 1], ans[i + 1])) % MOD;
	print(fans), puts("");
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("light.in", "r", stdin);
	freopen("light.out", "w", stdout);
#endif
#endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T --> 0) solve();
	return 0;
}
