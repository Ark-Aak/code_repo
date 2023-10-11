#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <queue>
#include <bitset>
#define int long long
#define pii pair <int, int>
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
const int N = 2e6, M = 4e6;
namespace G {

array <int, N> fir;
array <int, M> nex, to;
int cnt;
void add(int x, int y) {
	cnt++;
	nex[cnt] = fir[x];
	to[cnt] = y;
	fir[x] = cnt;
}

}
array <int, N> s;
array <int, N> dis;
bitset <N> vis;
#define fi first
#define se second
priority_queue <pii, vector <pii>, greater <pii> > q;
void dijkstra(int S) {
	using G::fir, G::to, G::nex;
	dis.fill(0x7f7f7f7f);
	dis[S] = 0;
	q.push(make_pair(dis[S], S));
	while (!q.empty()) {
		int u = q.top().se;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = fir[u]; i; i = nex[i]) {
			if (dis[to[i]] > dis[u] + -s[to[i]]) {
				dis[to[i]] = dis[u] + -s[to[i]];
				q.push(make_pair(dis[to[i]], to[i]));
			}
		}
	}
}
signed main() {
	freopen("trade.in", "r", stdin);
	freopen("trade.out", "w", stdout);
	int n = read(), m = read(), c = read();
	for (int i = 1; i <= n; i++)
		s[i] = read();
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read();
		/* G::add(x, y), G::add(y, x); */
		for (int j = 1; j <= 700; j++) {
			s[x + j * n] = s[x];
			s[y + j * n] = s[y];
			G::add(x + (j - 1) * n, y + j * n);
			/* G::add(y + (j - 1) * n, x + j * n); */
		}
	}
	/* bfs(1); */
	int ans = 0;
	/* for (int i = 1; i <= 1000; i++) { */
		/* write(dis[1][i]), puts(""); */
		/* ans = max(ans, dis[1][i] - i * i * c); */
	/* } */
	dijkstra(1);
	int tp = 0;
	for (int i = 1; i <= n * 700; i += n) {
		ans = max(ans, -dis[i] - c * tp * tp);
		tp++;
	}
	write(ans), puts("");
	return 0;
}
