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

const int MAXN = 1e5 + 5;
int n, m, a[MAXN], st[MAXN][21];

int main() {
	read(n), read(m);
	rep (i, 1, n) read(a[i]);
	rep (i, 1, n) st[i][0] = a[i];
	rep (j, 1, log2(n)) {
		rep (i, 1, n - (1 << j) + 1) {
			st[i][j] = max(st[i + (1 << (j - 1))][j - 1], st[i][j - 1]);
		}
	}
	rep (i, 1, m) {
		int u, v;
		read(u), read(v);
		int l = log2(v - u + 1);
		print(max(st[u][l], st[v - (1 << l) + 1][l]));
		putchar(10);
	}
	return 0;
}
