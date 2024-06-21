#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

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

string s;
int _val[128], _cha[128];
int m[105][105];
const int MAXN = 1e6 + 5;
int val[MAXN];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
char w[] = { 'D', 'U', 'R', 'L' };

function <double (int, int, int, int)> dist =
	[](int a0, int a1, int b0, int b1) {
		return sqrt(pow(a0 - b0, 2) + pow(a1 - b1, 2));
	};

function <bool (int, int)> out =
	[](int x, int y) { return x < 1 || x > 30 || y < 1 || y > 30; };

signed main() {
	_val['R'] = 1, _val['G'] = 2, _val['B'] = 3;
	_cha[1] = 'R', _cha[2] = 'G', _cha[3] = 'B';
	cin >> s;
	const int n = s.size();
	rep (i, 1, n) val[i] = _val[(int) s[i - 1]];
	memset(m, -1, sizeof m);
	rep (i, 1, 30) rep (j, 1, 30) {
		if (i % 3 == 0) m[i][j] = 3;
		if (i % 3 == 2) m[i][j] = ((j - 1) / 2 + 1) % 2 + 1;
		if (i % 3 == 1) m[i][j] = ((j - 1) / 2) % 2 + 1;
	}
	puts("30 30");
	rep (i, 1, 30) {
		rep (j, 1, 30) putchar(_cha[m[i][j]]);
		puts("");
	}
	int cirX = 15, cirY = 15;
	double mindis = 100;
	int staX = 0, staY = 0;
	rep (i, 1, 30) rep (j, 1, 30) {
		if (mindis > dist(i, j, cirX, cirY) && val[1] == m[i][j]) {
			mindis = dist(i, j, cirX, cirY);
			staX = i, staY = j;
		}
	}
	cout << staX << " " << staY << endl;
	int x = staX, y = staY;
	rep (i, 2, n) {
		double mindis = 100;
		int p = 0;
		int px = 0, py = 0;
		rep (j, 0, 3) {
			int nx = x + dx[j], ny = y + dy[j];
			if (out(nx, ny)) continue;
			if (dist(cirX, cirY, nx, ny) < mindis && m[nx][ny] == val[i]) {
				p = j;
				px = nx, py = ny;
				mindis = dist(cirX, cirY, nx, ny);
			}
		}
		putchar(w[p]);
		x = px, y = py;
	}
	puts("");
	return 0;
}
