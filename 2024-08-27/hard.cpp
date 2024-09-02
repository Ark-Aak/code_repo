#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
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

int n;
string s1, s2;
const int MAXN = 1e6 + 5;
int a[MAXN], b[MAXN];
int f[MAXN][3][2];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
    freopen("hard.in", "r", stdin);
    freopen("hard.out", "w", stdout);
#endif
#endif
    cin >> n;
    cin >> s1 >> s2;
    s1 = ' ' + s1;
    s2 = ' ' + s2;
	rep (i, 1, n) a[i] = s1[i] - '0';
	rep (i, 1, n) b[i] = s2[i] - '0';
	memset(f, 0x3f, sizeof f);
 	f[0][2][0] = 0;
	rep (i, 1, n) {
		rep (j, 0, 2) {
			rep (k, 0, 1) {
				if (f[i - 1][j][k] == 1e9) continue;
				rep (x, 0, 2) {
					rep (y, 0, 1) {
						int ch = a[i];
						if (x <= 1) ch = x;
						if (y) ch = !ch;
						if (ch != b[i]) continue;
						int ct = f[i - 1][j][k] + (y == 1 && k == 0) + (x != 2 && x != j);
						f[i][x][y] = min(f[i][x][y], ct);
					}
				}
			}
		}
	}
	int ans = 1e9;
	rep (i, 0, 2) rep (j, 0, 1) ans = min(ans, f[n][i][j]);
	print(ans), puts("");
	return 0;
}
