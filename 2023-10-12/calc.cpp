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

ll a, b, ans;
const int MAXN = 5e7 + 5;

vector <int> p;
bitset <MAXN> vis;
int f[MAXN];

void sieve(int n) {
	f[1] = 1;
	vis[1] = 1;
	rep (i, 2, n) {
		if (!vis[i]) {
			p.emplace_back(i);
			f[i] = i + 1;
		}
		for (auto j : p) {
			if (i * j > n) break;
			int pos = i * j;
			vis[pos] = 1;
			f[pos] = f[i] * f[j];
			if (i % j == 0) {
				f[pos] -= f[i / j] * j;
				break;
			}
		}
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("calc.in", "r", stdin);
	freopen("calc.out", "w", stdout);
#endif
#endif
	int tans = 0;
	read(a), read(b);
	sieve(b);
	rep (i, a, b) {
		tans += abs(i - (f[i] - i));
	}
	print(tans);
	return 0;
}
