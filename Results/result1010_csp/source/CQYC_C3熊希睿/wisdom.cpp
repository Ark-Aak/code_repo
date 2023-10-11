#include <bits/stdc++.h>

#define int ll

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

const int MAXK = 1e3 + 5;
const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int qpow(int a, int b, int p) {
	int res = 1;
	while (b) {
		if (b & 1) res = (res * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return res;
}

struct operation {
	int tp, x, y;

	operation() {}

	operation(int tp, int x, int y) {
		this -> tp = tp;
		this -> x = x;
		this -> y = y;
	}

	bool operator < (const operation &t) const {
		return tp == t.tp ? x == t.x ? y < t.y : x < t.x : tp < t.tp;
	}
};

vector <operation> R, S, Rop, Sop;

int n, m, k, ans;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("wisdom.in", "r", stdin);
	freopen("wisdom.out", "w", stdout);
#endif
#endif
	const int INV = qpow(2, MOD - 2, MOD);
	cin >> n >> m >> k;
	rep (i, 1, k) {
		char c;
		cin >> c;
		int x, y;
		cin >> x >> y;
		if (c == 'R') R.emplace_back(operation(0, x, y));
		else S.emplace_back(operation(1, x, y));
	}
	sort(R.begin(), R.end());
	sort(S.begin(), S.end());
	int lst = 0, times = 1;
	for (auto [_tp, x, y] : R) {
		if (x == lst) times *= y, times %= MOD;
		else {
			if (lst != 0) Rop.emplace_back(operation(0, lst, times));
			lst = x; times = y;
		}
	}
	Rop.emplace_back(operation(0, lst, times));
	lst = 0, times = 1;
	for (auto [_tp, x, y] : S) {
		if (x == lst) times *= y, times %= MOD;
		else {
			if (lst != 0) Sop.emplace_back(operation(1, lst, times));
			lst = x; times = y;
		}
	}
	Sop.emplace_back(operation(0, lst, times));
	ans = (n * m) % MOD * (n * m + 1) % MOD * INV % MOD;
	for (auto [_tp, x, y] : Rop) {
		int ts = y - 1;
		int st = m * (x - 1) % MOD + 1, ed = (st + m - 1) % MOD;
		int sum = (st + ed) % MOD * m % MOD * INV % MOD;
		int delta = (((sum * ts) + MOD) % MOD);
		ans += delta;
		ans = (ans + MOD) % MOD;
	}
	for (auto [_tp, x, y] : Sop) {
		int ts = y - 1;
		int st = x, ed = (st + (n - 1) * m % MOD) % MOD;
		int sum = (st + ed) % MOD * n % MOD * INV % MOD;
		int delta = (((sum * ts) + MOD) % MOD);
		ans += delta;
		ans = (ans + MOD) % MOD;
	}
	for (auto [_tp, x, y] : Rop) {
		for (auto [__tp, _x, _y] : Sop) {
			int f = ((y * _y) + MOD) % MOD;
			int ts = f - 1;
			int fs = y - 1 + _y - 1;
			int val = ((x - 1) * m % MOD + _x) % MOD;
			int c = fs - ts;
			ans -= (c * val) % MOD;
			ans = (ans + MOD) % MOD;
		}
	}
	cout << (ans + MOD) % MOD;
	return 0;
}
