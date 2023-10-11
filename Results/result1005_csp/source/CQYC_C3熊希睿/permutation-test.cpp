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

const int MAXN = 1e5 + 5;
int n, k;
int p[MAXN][3];
int _p[MAXN], _q[MAXN];

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
#endif
#endif
	read(n);
	rep (i, 1, n) read(p[i][0]), _p[i] = p[i][0];
	rep (i, 1, n) read(p[i][1]), _q[i] = p[i][1];
	rep (i, 2, 1e9) {
		if (i % (int) 1e6 == 0) cout << i << "\n";
		rep (j, 1, n) {
			p[p[j][(i - 2 + 3) % 3]][i % 3] = p[j][(i - 1 + 3) % 3];
		}
		bool flg = 1;
		rep (j, 1, n) {
			if (p[j][(i + 2) % 3] != _p[j] || p[j][i % 3] != _q[j]) {
				flg = 0;
				break;
			}
		}
		if (flg) {
			cout << n << " " << i - 1;
			break;
		}
	}
	//rep (i, 1, n) cout << p[i][k % 3] << " ";
	return 0;
}
