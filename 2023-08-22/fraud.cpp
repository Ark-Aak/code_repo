#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a); i <= b; i++)
#define _rep(i, a, b) for(int i = (a); i >= b; i--)

using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 3e5 + 5;
const int MOD = 998244353;
ll T, n, a[MAXN], b[MAXN], _a[MAXN], _b[MAXN];
ll plc[2 * MAXN], flg, ans1, ans2;

ll qpow(ll a, ll b, ll p) {
	ll res = 1;
	a %= p, b %= p;
	while (b) {
		if (b & 1) res = (res * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return res;
}

void prt(ll a, ll b) {
	cout << ((a % MOD) * qpow(b, MOD - 2, MOD) % MOD) % MOD << endl;
}

void _dfs(int step) {
	if (step > 2 * n) {
		ans2++;
		if (plc[1] == plc[2 * n]) return;
		for (int i = 3; i <= 2 * n; i += 2) {
			if (plc[i - 1] == plc[i]) return;
		}
		ans1++;
		return;
	}
	int rIndex = (step + 1) / 2;
	if (step % 2) {
		if (a[rIndex] == 0) {
			plc[step] = 1;
			_dfs(step + 1);
			plc[step] = 2;
			_dfs(step + 1);
		}
		else plc[step] = a[rIndex], _dfs(step + 1);
	}
	else {
		if (b[rIndex] == 0) {
			plc[step] = 1;
			_dfs(step + 1);
			plc[step] = 2;
			_dfs(step + 1);
		}
		else plc[step] = b[rIndex], _dfs(step + 1);
	}
}

bitset <MAXN> vis;

void dfs(int step) {
	if (step > n) {
		_dfs(1);
		return;
	}
	rep (i, 1, n) {
		if (!vis[i]) {
			a[step] = _a[i];
			b[step] = _b[i];
			vis[i] = 1;
			dfs(step + 1);
			vis[i] = 0;
		}
	}
}

void Subtask_1() {
	flg = 0;
	ans1 = ans2 = 0;
	dfs(1);
	prt(ans1, ans2);
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("fraud.in", "r", stdin);
	freopen("fraud.out", "w", stdout);
#endif
#endif
	cin >> T;
	while (T --> 0) {
		ans1 = ans2 = 0;
		cin >> n;
		rep (i, 1, n) {
			cin >> _a[i] >> _b[i];
		}
		Subtask_1();
	}
	return 0; 
}
