#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;

#define int ll

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

const int MAXN = 1e6 + 5;

bool f[MAXN][11];

string s, op;
int n, ops[MAXN], val[MAXN];
char charBuf[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("yo.in", "r", stdin);
	freopen("yo.out", "w", stdout);
#endif
#endif
	scanf("%lld", &n);
	scanf("%s", charBuf);
	s = charBuf;
	scanf("%s", charBuf);
	op = charBuf;
	s = ' ' + s;
	op = ' ' + op;
	rep (i, 1, n) {
		ops[i] = (op[i] == 'y');
		val[i] = s[i] - '0';
	}
	f[n + 1][0] = 1;
	_rep (i, n, 1) {
		rep (j, 0, 10) {
			if (ops[i] == 1) {
				if (f[i + 1][(j * 10 + val[i]) % 11]) f[i][j] = 1;
				if (f[i + 1][(j * 10) % 11]) f[i][j] = 1;
			}
			else {
				if (f[i + 1][(j * 10 + val[i]) % 11] && f[i + 1][(j * 10) % 11]) f[i][j] = 1;
				else f[i][j] = 0;
			}
		}
	}
	if (f[1][0]) cout << "yoimiya";
	else cout << "oimiya";
	return 0; 
}
