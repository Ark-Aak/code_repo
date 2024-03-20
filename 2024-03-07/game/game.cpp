#include <bits/stdc++.h>

#define int __int128

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int n, m, x;
multiset <int> a, b;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
#endif
#endif
	n = read(), m = read(), x = read();
	rep(i, 1, n) a.insert(read() % x);
	rep(i, 1, m) b.insert(read() % x);
	int ansA = *a.rbegin() - *a.begin(), ansB = *b.rbegin() - *b.begin();
	while (1) {
		auto valG = *a.rbegin();
		a.erase(a.find(valG));
		a.insert(valG - x);
		ansA = min(ansA, *a.rbegin() - *a.begin());
		valG = *b.rbegin();
		b.erase(b.find(valG));
		b.insert(valG - x);
		ansB = min(ansB, *b.rbegin() - *b.begin());
		if (clock() * 1.0 / CLOCKS_PER_SEC > 0.95) break;
	}
	print(ansA + ansB);
	return 0;
}
