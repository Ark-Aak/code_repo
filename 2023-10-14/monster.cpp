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

const int MAXN = 1e5 + 5, MOD = 1e9 + 7;
int n, a[MAXN], base[MAXN], cnt[MAXN];
unordered_map <int, int> c;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("monster.in", "r", stdin);
	freopen("monster.out", "w", stdout);
#endif
#endif
	read(n);
	rep (i, 1, n) read(a[i]);
	rep (i, 1, n) base[i] = (base[i - 1] << 1 | 1) % MOD;
	//n = unique(a + 1, a + 1 + n) - a - 1;
	//cout << n << "\n";
	sort(a + 1, a + 1 + n);
	//rep (i, 1, n) cout << a[i] << " ";
	//cout << "\n"; 
	int ans = 0;
	rep (i, 1, n) {
		if (a[i] == a[i - 1]) cnt[i] -= c[a[i]], cnt[i] = (cnt[i] + MOD) % MOD;
		c[a[i]] += base[i - 1] + 1;
		//cout << "i = " << i << " a[i] = " << a[i] << " c[a[i]] = " << c[a[i]] << "\n";
		c[a[i]] %= MOD;
		ans += ((base[i] - base[i - 1]) * a[i]) % MOD;
		ans %= MOD;
		cnt[i] += ((cnt[i - 1] << 1) + (base[i - 1] + 1)) % MOD;
		cnt[i] %= MOD;
		ans -= (cnt[i] - cnt[i - 1]) % MOD;
		ans = (ans + MOD) % MOD;
		ans %= MOD;
	}
	//rep (i, 1, n) cout << cnt[i] << " ";
	//cout << "\n";
	print((ans + MOD) % MOD);
	return 0;
}
