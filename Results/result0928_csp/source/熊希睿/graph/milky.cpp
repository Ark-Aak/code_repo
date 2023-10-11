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

string T;
const int MAXN = 1e6 + 5;
int Q, b[MAXN];
unsigned f[1005][10];
unsigned f2[MAXN][10];

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("milky.in", "r", stdin);
	freopen("milky.out", "w", stdout);
#endif
#endif
	cin >> T;
	int n = T.length();
	rep (i, 1, T.length()) {
		if (T[i - 1] == 'm') b[i] = 1;
		if (T[i - 1] == 'i') b[i] = 2;
		if (T[i - 1] == 'l') b[i] = 3;
		if (T[i - 1] == 'k') b[i] = 4;
		if (T[i - 1] == 'y') b[i] = 5;
	}
	if (T.length() <= 1000) {
		cin >> Q;
		while (Q --> 0) {
			int l, r;
			cin >> l >> r;
			memset(f, 0, sizeof f);
			rep (i, 0, r - l + 1) f[i][0] = 1;
			rep (i, l, r) rep (j, 1, 5) {
				if (b[i] == j) f[i - l + 1][j] = f[i - l][j] + f[i - l + 1][j - 1];
				else f[i - l + 1][j] = f[i - l][j];
			}
			cout << f[r - l + 1][5] << endl;
		}
	}
	else {
		rep (i, 0, n) f2[i][0] = 1;
		rep (i, 1, n) rep (j, 1, 5) {
			if (b[i] == j) f2[i][j] = f2[i - 1][j] + f2[i][j - 1];
			else f2[i][j] = f2[i - 1][j];
		}
		cin >> Q;
		while (Q --> 0) {
			int l, r;
			cin >> l >> r;
			cout << f2[r][5] << endl;
		}
	}
	return 0; 
}
