#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <ctime>
#include <vector>
#define int long long
using namespace std;

#ifdef ONLINE_JUDGE

#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 23], *p1 = buf, *p2 = buf, ubuf[1 << 23], *u = ubuf;

#endif

int read() {
	int p = 0, flg = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') flg = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		p = p * 10 + c - '0';
		c = getchar();
	}
	return p * flg;
}
void write(int x) {
	if (x < 0) {
		x = -x;
		putchar('-');
	}
	if (x > 9) {
		write(x / 10);
	}
	putchar(x % 10 + '0');
}
const int N = 1e5 + 5, mod = 998244353;
void Mod(int &x) {
	if (x >= mod) x -= mod;
	if (x < 0) x += mod;
}
namespace Subtask1 {

array <array <int, N>, 2> f;
array <int, N> g;
array <vector <int>, N> phi;
void main(int n, int m) {
	for (int i = 1; i <= m; i++) {
		for (int j = 2; j * j <= i; j++) {
			if (i % j) continue;
			phi[i].push_back(j);
		}
	}
	g[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f[i & 1][j] = g[i - 1];
			if (j > 1) f[i & 1][j] -= f[(i - 1) & 1][1];
			for (auto x : phi[j]) {
				if (x * x == j)
					f[i & 1][j] += f[(i - 1) & 1][x], Mod(f[i & 1][j]);
				f[i & 1][j] -= f[(i - 1) & 1][j / x], Mod(f[i & 1][j]);
				f[i & 1][j] -= f[(i - 1) & 1][x], Mod(f[i & 1][j]);
			}
			g[i] += f[i & 1][j], Mod(g[i]);
		}
	}
	write(g[n]), puts("");
}

}
namespace Subtask2 {

array <int, N> f, idx;
void main(int n, int m) {
	for (int i = 1; i <= m; i++)
		idx[i] = m / i - 1;
}

}
signed main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	int n = read(), m = read();
	Subtask1::main(n, m);

	/* cout << clock() << endl; */
	return 0;
}
