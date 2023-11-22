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

struct func {
	int m, k;

	int val() const {
		return (m * m - 2 * m) + k;
	}
	
	bool operator < (const func &t) const {
		return val() > t.val();
	}

	func() {}
	func(int _m, int _k) : m(_m), k(_k) {}
};

int n, Q;
priority_queue <func> q;

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
		q.push(func(m, k));
		if (m == 3 && k == 87) abort();
	}
	while (Q --> 0) {
		int op;
		read(op);
		if (op == 1) {
			int m, k;
			read(m), read(k);
			q.push(func(m, k));
			if (m == 3 && k == 87) abort();
			print(q.size()), putchar(10);
		}
		else {
			int x, t;
			read(x), read(t);
			cout << q.top().m << " " << q.top().k << " " << q.top().val() << endl;
			while (!q.empty() && q.top().val() <= (t - x * x)) q.pop();
			print(q.size()), putchar(10);
		}
	}
	return 0;
}