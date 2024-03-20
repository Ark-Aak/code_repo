#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

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

#define int ll

int T;

void upd(int& ans, int val) {
	ans = min(ans, val);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("triple.in", "r", stdin);
	freopen("triple.out", "w", stdout);
#endif
#endif
	read(T);
	while (T --> 0) {
		int p, q, r, a, b, c, ans = 3;
		read(p), read(q), read(r);
		read(a), read(b), read(c);
		if (p == a) {
			if (q == b && r == c) ans = 0;
			else if (q == b || r == c) ans = 1;
			else if (q - b == r - c) ans = 1;
			else if (q != 0 && r != 0) {
				if (b % q == 0 && c % r == 0 && b / q == c / r) ans = 1;
				else ans = 2;
			}
			else ans = 2;
			print(ans), putchar(10);
			continue;
		}
		int cc[4] = {0, a - p, b - q, c - r};
		int rr[4] = {0, p == 0 ? INT_MAX : a / p, q == 0 ? INT_MAX : b / q, r == 0 ? INT_MAX : c / r};
		int tt[4] = {0, p == 0 ? INT_MAX : a % p, q == 0 ? INT_MAX : b % q, r == 0 ? INT_MAX : c % r};
		if (p == a && q == b && r == c) upd(ans, 0);
		if (cc[1] == cc[2] && cc[2] == cc[3]) upd(ans, 1);
		if (rr[1] == rr[2] && rr[2] == rr[3] && tt[1] == tt[2] && tt[2] == tt[3] && tt[3] == 0) upd(ans, 1);
		if (rr[1] == rr[2] && rr[2] == rr[3] && tt[1] == tt[2] && tt[2] == tt[3]) upd(ans, 2);
		print(ans), putchar(10);
	}
	return 0; 
}
