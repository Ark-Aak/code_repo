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

const int MAXN = 1e6 + 5;
int n, q, x[MAXN], y[MAXN];

struct point {
	int x, y;

	point() {}

	point(int x, int y) {
		this -> x = x, this -> y = y;
	}

	bool operator < (const point &t) const {
		return x == t.x ? y < t.y : x < t.x;
	}
};

vector <point> p;
stack <point> S;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("ds.in", "r", stdin);
	freopen("ds.out", "w", stdout);
#endif
#endif
	read(n), read(q);
	rep (i, 1, n) read(x[i]);
	rep (i, 1, n) read(y[i]);
	rep (i, 1, n) p.emplace_back((point) {x[i], y[i]});
	sort(p.begin(), p.end(), [](point a, point b) {
			return a.x == b.x ? a.y > b.y : a.x < b.x;
	});
	while (q --> 0) {
		int U, R, D, L;
		read(U), read(R), read(D), read(L);
		auto biter = lower_bound(p.begin(), p.end(), point(D, -1));
		auto eiter = lower_bound(p.begin(), p.end(), point(U, 1e9));
		for (; biter != eiter; biter++) {
			int x = (*biter).x, y = (*biter).y;
			if (y < L || y > R) continue;
			while (S.size() && S.top().x < x && S.top().y < y) S.pop();
			S.push(*biter);
		}
		print(S.size()), putchar(10);
		while (S.size()) S.pop();
	}
	return 0;
}
