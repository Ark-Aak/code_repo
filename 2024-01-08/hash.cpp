#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

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

//测测你的/se/se/se

const int MOD = 998244353;
int T, m, ans;
const int MAXN = 55;
string s, t[MAXN];
int w[MAXN];

int occur(string s, string t) {
	int m = t.length(), ans = 0;
	while (s.find(t) != string::npos) {
		ans++;
		s = s.substr(s.find(t) + m);
	}
	return ans;
}

int h(string s, int l, int r) {
	int val = 0;
	string str = s.substr(l, r - l + 1);
	rep (i, 1, m) {
		val += occur(str, t[i]) * w[i] % MOD;
		val %= MOD;
	}
	return val;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("hash.in", "r", stdin);
	freopen("hash.out", "w", stdout);
#endif
#endif
	cin >> T;
	while (T--) {
		cin >> s;
		m = read();
		rep (i, 1, m) cin >> t[i] >> w[i];
		rep (i, 0, s.length() - 1) {
			rep (j, i, s.length() - 1) {
				int t = h(s, i, j);
				t = t * t % MOD * t % MOD * t % MOD * t % MOD;
				ans = (ans + t) % MOD;
			}
		}
		print(ans); putchar(10);
	}
	return 0;
}
