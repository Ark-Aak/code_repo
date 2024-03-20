#include <bits/stdc++.h>

#define int __int128

#define rep(i, a, b) for (auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for (auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp &first) {
	_Tp x = 0, f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 1e6 + 5, INF = 1e18;

int a[MAXN], n, x, y, z;

struct node {
	int val, id;
	
	node() {val = id = 0;}

	node(int val, int id) {
		this -> val = val;
		this -> id = id;
	}
} _x[MAXN], _y[MAXN], _z[MAXN], xy[MAXN], xz[MAXN], yz[MAXN], xyz[MAXN];
// 1 0 0, 0 1 0, 0 0 1, 1 1 0, 1 0 1, 0 1 1, 1 1 1

string s;

int calc(int x, int y) {
	return (x / y + (x % y != 0)) * y - x;
}

int gcd(int x, int y) {
	return __gcd(x, y);
}

signed main() {
	read(n), read(x), read(y), read(z);
	int _xy = 0, _xz = 0, _yz = 0, _xyz = 0;
	_xy = x * y / gcd(x, y), _xz = x * z / gcd(x, z), _yz = y * z / gcd(y, z), _xyz = _xy * z / gcd(_xy, z);
	rep (i, 1, n) {
		int u;
		read(u);
		_x[i] = node(calc(u, x), i);
		_y[i] = node(calc(u, y), i);
		_z[i] = node(calc(u, z), i);
		xy[i] = node(calc(u, _xy), i);
		xz[i] = node(calc(u, _xz), i);
		yz[i] = node(calc(u, _yz), i);
		xyz[i] = node(calc(u, _xyz), i);
	}
	auto func = [](node a, node b) {
		return a.val < b.val;
	};
	sort(_x + 1, _x + 1 + n, func);
	sort(_y + 1, _y + 1 + n, func);
	sort(_z + 1, _z + 1 + n, func);
	sort(xy + 1, xy + 1 + n, func);
	sort(xz + 1, xz + 1 + n, func);
	sort(xyz + 1, xyz + 1 + n, func);
	sort(yz + 1, yz + 1 + n, func);
	int ans = INF;
	if (xz[1].id == _y[1].id && n != 1) ans = min(ans, min(xz[1].val + _y[2].val, xz[2].val + _y[1].val));
	else if (n != 1) ans = min(ans, xz[1].val + _y[1].val);
	if (xy[1].id == _z[1].id && n != 1) ans = min(ans, min(xy[1].val + _z[2].val, xy[2].val + _z[1].val));
	else if (n != 1) ans = min(ans, xy[1].val + _z[1].val);
	if (yz[1].id == _x[1].id && n != 1) ans = min(ans, min(yz[1].val + _x[2].val, yz[2].val + _x[1].val));
	else if (n != 1) ans = min(ans, yz[1].val + _x[1].val);
	if (n >= 3) rep (i, 1, 3) rep (j, 1, 3) rep (k, 1, 3) {
		if (_x[i].id != _y[j].id && _y[j].id != _z[k].id && _z[k].id != _x[i].id)
			ans = min(ans, _x[i].val + _y[j].val + _z[k].val);
	}
	ans = min(ans, xyz[1].val);
	print(ans);
	return 0;
}
