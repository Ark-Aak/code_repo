/* #define debug */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <tuple>
#include <set>
#include <vector>
#include <ctime>
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
#define fi first
#define se second
const int N = 2e5 + 5;
array <int, N> s, dis;
array <pii, N> lrs;
/* sum id l  r */
/* 0   1  2  3 */

array <tuple <int, int, int>, N> qrl;
vector <int> cur;
namespace Bit {

array <int, N * 4> edge;
int lowbit(int x) {
	return x & -x;
}
void modify(int x, int y, int n) {
	if (!x) return;
	while (x <= n) {
		edge[x] += y;
		x += lowbit(x);
	}
	return;
}
int query(int x) {
	int ans = 0;
	while (x) {
		ans += edge[x];
		x -= lowbit(x);
	}
	return ans;
}

}

void update(int x, int y, int n, int len) {
	if (x < 1 || x > n) return;
	Bit::modify(y, -dis[x], len);
	if (x == 1) {
		if (s[x + 1] <= s[x]) dis[x] = -1;
		else dis[x] = 0;
		Bit::modify(s[x], dis[x], len);
		return;
	}
	if (x == n) {
		if (s[x - 1] <= s[x]) dis[x] = -1;
		else dis[x] = 0;
		Bit::modify(s[x], dis[x], len);
		return;
	}
	if (s[x - 1] >= s[x] && s[x + 1] >= s[x]) dis[x] = 1;
	if (s[x - 1] <= s[x] && s[x + 1] <= s[x]) dis[x] = -1;
	if (s[x - 1] <= s[x] && s[x + 1] >= s[x]) dis[x] = 0;
	if (s[x + 1] <= s[x] && s[x - 1] >= s[x]) dis[x] = 0;
	Bit::modify(s[x], dis[x], len);
}


signed main() {
	freopen("gaze.in", "r", stdin);
	freopen("gaze.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 1; i <= n; i++)
		s[i] = read(), cur.push_back(s[i]);
	for (int i = 1; i <= m; i++) {
		int op = read(), x = read();
		if (op == 1) qrl[i] = make_tuple(op, x, 0), cur.push_back(x);
		else {
			int y = read();
			cur.push_back(y);
			qrl[i] = make_tuple(op, x, y);
		}
	}
	sort(cur.begin(), cur.end());
	int len = unique(cur.begin(), cur.end()) - cur.begin();
	for (int i = 1; i <= n; i++)
		s[i] = lower_bound(cur.begin(), cur.begin() + len, s[i]) - cur.begin() + 1;
	for (int i = 1; i <= n; i++)
		update(i, 0, n, len);
	/* for (int i = 1; i <= n; i++) */
		/* write(dis[i]), putchar(32); */
	/* puts(""); */
	for (int i = 1; i <= m; i++) {
		if (get <0>(qrl[i]) == 1) {
			int x = lower_bound(cur.begin(), cur.begin() + len, get <1>(qrl[i])) - cur.begin() + 1;
			write(Bit::query(x - 1) + 1), puts("");
		}
		else {
			int x = get <1>(qrl[i]), y = get <2>(qrl[i]);
			int k = s[x];
			s[x] = lower_bound(cur.begin(), cur.begin() + len, y) - cur.begin() + 1;
			update(x, k, n, len);
			update(x - 1, s[x - 1], n, len);
			update(x + 1, s[x + 1], n, len);
			/* if (s[x] == s[x - 1] || s[x] == s[x + 1]) puts("@"); */
		}
	}
	/* write(clock()), puts(""); */
	return 0;
}
