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

int n;
vector <ll> B;

void insert(ll x) {
	for (auto b : B) x = min(x, x ^ b);
	if (!x) return;
	for (auto &b : B) b = min(b, b ^ x);
	B.emplace_back(x);
}

signed main() {
	read(n);
	rep (i, 1, n) {
		ll t; read(t);
		insert(t);
	}
	sort(B.begin(), B.end());
	int m;
	read(m);
	while (m --> 0) {
		int k;
		read(k);
		if (B.size() < n) k--;
		int res = 0;
		rep (i, 0, B.size() - 1) {
			if (k & 1) res ^= B[i];
			k >>= 1;
		}
		if (k == 0) print(res), putchar(10);
		else puts("-1");
	}
	return 0;
}
