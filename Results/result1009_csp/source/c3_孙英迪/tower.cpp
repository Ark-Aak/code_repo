#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <queue>
#include <set>
#define pii pair <int, int>
using namespace std;
#ifdef ONLINE_JUDGE

#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 23], *p1 = buf, buf, ubuf[1 << 23], *u = ubuf;

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
string read_() {
	string ans;
	char c = getchar();
	while (c != '0' && c != '1')
		c = getchar();
	while (c == '0' || c == '1') {
		ans += c;
		c = getchar();
	}
	return ans;
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
#define fi first
#define se second
const int N = 5e5 + 5, M = 1e6 + 5;
namespace G {

array <int, N> fir;
array <int, M> nex, to, len;
int cnt;
void add(int x, int y, int z) {
	/* write(x), putchar(32); */
	/* write(y), putchar(32); */
	/* write(z), puts(""); */
	cnt++;
	nex[cnt] = fir[x];
	to[cnt] = y;
	len[cnt] = z;
	fir[x] = cnt;
}

}

array <int, N> s;

array <int, N> dis, vis;
using G::fir, G::to, G::len, G::nex;
priority_queue <pii, vector <pii>, greater <pii> > q;
void dijkstra(int n) {
	dis.fill(0x7f7f7f7f);
	dis[1] = 0;
	q.push(make_pair(0, 1));
	while (!q.empty()) {
		int u = q.top().se;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = fir[u]; i; i = nex[i]) {
			if (dis[to[i]] > dis[u] + len[i]) {
				dis[to[i]] = dis[u] + len[i];
				q.push(make_pair(dis[to[i]], to[i]));
			}
		}
	}
}
array <set <int>, N> isl;
array <string, N> mp;
int main() {
	freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);
	int n = read(), k = read();
	for (int i = 1; i <= n; i++) {
		s[i] = read();
		isl[s[i]].insert(i);
	}
	for (int i = 1; i <= k; i++) {
		mp[i] = " " + read_();
		/* for (int j = 1; j <= k; j++) { */
			/* if (T[j] == '0') continue; */
			/* G::add(i + n, n + j + k, 0); */
		/* } */
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (mp[s[i]][j] == '0') continue;
			if (isl[j].size() >= 2) {
				int tp = *isl[j].upper_bound(i);
				G::add(i, tp, abs(i - tp));
				auto it = isl[j].upper_bound(i);
				it--;
				G::add(i, *it, abs(i - *it));
			}
			if (!isl[j].size()) continue;
			if (isl[j].size() == 1) {
				G::add(i, *isl[j].begin(), abs(i - *isl[j].begin()));
			}
		}
	}
	dijkstra(n);
	write(dis[n]), puts("");
	return 0;
}
