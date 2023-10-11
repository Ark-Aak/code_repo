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

int s[15], _s[15], id[15], n, ans, mod, cnt;
bitset <15> vis;

void dfs(int step) {
	if (step > n) {
		rep (i, 1, n) _s[i] = s[i];
		rep (i, 1, n) id[s[i]] = i;
		rep (i, 1, n) {
			int p = id[i];
			int lid = p - 1, rid = p + 1;
			if (lid < 1) lid = n;
			if (rid > n) rid = 1;
			int mx = max(_s[lid], _s[rid]), mn = min(_s[lid], _s[rid]);
			if (mn < i && i < mx) {
				ans++; ans %= mod;
				return;
			}
			swap(id[_s[lid]], id[_s[rid]]);
			swap(_s[lid], _s[rid]);
		}
		return;
	}
	rep (i, 1, n) {
		if (!vis[i]) {
			vis[i] = 1;
			s[step] = i;
			dfs(step + 1);
			vis[i] = 0;
		}
	}
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("ring.in", "r", stdin);
	freopen("ring.out", "w", stdout);
#endif
#endif
	read(n), read(mod);
	if (n & 1) {
		ll ans = 1;
		rep (i, 2, n) {
			ans = (ans * i) % mod;
		}
		print(ans);
		return 0;
	}
	dfs(1);
	print(ans % mod);
	return 0;
}
