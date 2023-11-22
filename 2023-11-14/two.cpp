#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;

#define int ll

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

int n, Q;
list <pair <int, int> > s;
int flg[5000005], ans;

int f(int m, int k, int x) {
	return (x - m) * (x - m) + k;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("two.in", "r", stdin);
	freopen("two.out", "w", stdout);
#endif
#endif
	read(n), read(Q);
	rep (i, 1, n) {
		int m, k;
		read(m), read(k);
		s.emplace_back(make_pair(m, k));
	}
	while (Q --> 0) {
		int op;
		read(op);
		if (op == 1) {
			int m, k;
			read(m), read(k);
			s.emplace_back(make_pair(m, k));
			print(s.size()), putchar(10);
		}
		else {
			int x, t;
			read(x), read(t);
			for (auto iter = s.begin(); iter != s.end(); iter++) {
				pair <int, int> val = *iter;
				int m = val.first, k = val.second;
				if (f(m, k, x) <= t) {
					s.erase(iter);
					iter--;
				}
			}
			print(s.size()), putchar(10);
		}
	}
	return 0;
}