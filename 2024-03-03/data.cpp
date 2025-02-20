#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair

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

mt19937 rnd(time(0));

int Rand(int l, int r) {
	return l + abs((int) rnd()) % (r - l + 1);
}

signed main() {
	freopen("data.in", "w", stdout);
	int n = 10000, m = 10000;
	cout << n << " " << m << endl;
	rep (i, 1, n) {
		cout << Rand(1, n + m) << " ";
	}
	cout << endl;
	rep (i, 1, n) {
		cout << Rand(1, 10) << " ";
	}
	cout << endl;
	rep (i, 1, m) {
		cout << Rand(1, n + m) << " ";
	}
	cout << endl;
	rep (i, 1, m) {
		cout << Rand(1, 10) << " ";
	}
	return 0;
}
