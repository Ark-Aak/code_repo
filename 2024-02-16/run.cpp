#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int read() {
	int x = 0, f = 1;
	char c = getchar();
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

string str;

const int MOD = 998244353;

int n, m, ans, tans;
int s[100005], bs[100005];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
#endif
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	bs[0] = 1;
	rep(i, 1, 1e5) bs[i] = (bs[i - 1] << 1) % MOD;
	rep(i, 1, 1e5) bs[i] = 1ll * (i + 1) * bs[i] % MOD;
	cin >> n >> m >> str;
	rep(i, 1, n) s[n - i + 1] = str[i - 1] - '0';
	while (m --> 0) {
		int ops, l, r;
		cin >> ops >> r >> l;
		l = n - l + 1, r = n - r + 1;
		if (ops == 1) rep (i, l, r) s[i] ^= 1;
		if (ops == 2) rep (i, l, r) s[i] = 0;
		if (ops == 3) rep (i, l, r) s[i] = 1;
		if (ops == 4) {
			ans = 1, tans = 6;
			int p = 0, flg = 1;
			while (s[l] == 0 && l <= r) l++;
			rep (i, l + 1, r) {
				p++;
				if (s[i] == 1) {
					if (flg) p++;
					flg = 0;
				}
				int nxt = ((ans + (s[i] == 1 ? tans : ans)) % MOD + bs[p]) % MOD;
				int tnxt = (((s[i] == 1 ? tans : ans) + tans) % MOD + bs[p + (s[i] == 1 ? 0 : flg)]) % MOD;
				ans = nxt, tans = tnxt;
			}
			if (l > r) cout << 0 << endl;
			else cout << ans << endl;
		}
	}
	return 0;
}
