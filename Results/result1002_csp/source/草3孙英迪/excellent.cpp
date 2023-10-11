#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#define int unsigned long long
using namespace std;
#ifdef ONLINE_JUDGE

/* #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++) */
/* char buf[1 << 23], *p1 = buf, *p2 = buf, ubuf[1 << 23], *u = ubuf; */

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
const int N = 3005;
char strbuf[N];
namespace subtask1 {

array <array <bool, N>, N> vis;
void main(int n, string s) {
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j += 2) {
			int mid = (i + j) >> 1;
			vis[i][j] = true;
			for (int k = 0; i + k <= mid; k++) {
				if (s[i + k] != s[mid + k + 1] &&
					s[i + k] != '?' &&
					s[mid + k + 1] != '?') {
					vis[i][j] = false;
					break;
				}
			}
		}
	}
	/* puts("-------------"); */
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 3; j <= n; j += 2) {
			for (int k = i + 1; k <= j - 2; k++) {
				if (vis[i][k] && vis[k + 1][j])
					ans++;
			}
		}
	}
	write(ans), puts("");
}

}
namespace subtask2 {

array <int, N> hs;
int pow_(int x, int k) {
	int ans = 1;
	while (k) {
		if (k & 1) ans = ans * x;
		x = x * x;
		k >>= 1;
	}
	return ans;
}
void gethash(int n, string s) {
	for (int i = 1; i <= n; i++)
		hs[i] = hs[i - 1] * 131ull + s[i];
}
array <int, N> f, g;
void main(int n, string s) {
	f.fill(0);
	g.fill(0);
	gethash(n, s);
	for (int i = n; i; i--) {
		for (int j = i + 1; j <= n; j += 2) {
			int mid = (i + j) >> 1;
			if ((hs[mid] - hs[i - 1] * pow_(131ull, mid - i + 1))
				== (hs[j] - hs[mid] * pow_(131ull, j - mid))) {
				g[i]++;
				f[i] += g[j + 1];
				/* write(i), putchar(32); */
				/* write(j), puts(""); */
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += f[i];
	write(ans), puts("");
}

}
namespace subtask3 {

array <array <int, N>, N> f;
array <int, N> g;
void main(int n, string s) {
	g.fill(0);
	for (int l = 1; l <= n; l++) {
		for (int i = 1; i + l <= n; i++) {
			f[i][l] = f[i - 1][l];
			if (s[i] == s[i + l] || s[i] == '?' || s[i + l] == '?')
				f[i][l]++;
			/* write(f[i][l]), putchar(32); */
		}
		/* puts(""); */
	}
	int ans = 0;
	for (int i = n; i; i--) {
		for (int l = 1; i + 2 * l - 1 <= n; l++) {
			if (i >= i + 2 * l - 1) continue;
			/* if (i == 1 && l == i) { */
				/* write(f[i + l - 1][l]), putchar(32); */
				/* write(f[i - 1][l]), puts("#"); */
			/* } */
			if (f[i + l - 1][l] - f[i - 1][l] == l) {
				int r = i + 2 * l - 1;
				g[i]++;
				ans += g[r + 1];
				/* write(i), putchar(32); */
				/* write(r), puts(""); */
			}
		}
	}
	write(ans), puts("");
}

}
signed main() {
	freopen("excellent.in", "r", stdin);
	freopen("excellent.out", "w", stdout);
	int T = read();
	while (T--) {
		scanf("%s", strbuf);
		string s = strbuf;
		int n = s.size();
		s = " " + s;
		/* cerr << "@"; */
		subtask3::main(n, s);
	}
	return 0;
}
