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

const int MAXN = 2e5 + 5;

struct edge {
	int v, b, c;
	
	edge(int _v, int _b, int _c): v(_v), b(_b), c(_c) {}
};

vector <edge> G[MAXN];
int n, m;
long double f[MAXN];

const long double EPS = 1e-10;

signed main(){
	read(n), read(m);
	rep (i, 1, m) {
		int u, v, b, c;
		read(u), read(v), read(b), read(c);
		G[v].emplace_back(edge(u, b, c));
	}
	long double l = 0, r = 2e9, mid = (l + r) / 2.0;
	while (r - l > EPS) {
		mid = (l + r) / 2.0;
		f[1] = 0;
		rep (i, 2, n) f[i] = -1e18;
		rep (i, 1, n) {
			for (auto [v, b, c] : G[i]) {
				f[i] = max(f[i], f[v] + b * 1.0 - mid * c);
			}
		}
		if (f[n] >= 0) l = mid;
		else r = mid;
	}
	printf("%.9Lf", mid);
	return 0;
}
