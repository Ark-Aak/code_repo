#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <vector>
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
const int N = 2e5 + 5;
array <int, N> lst, s;
namespace Bit {

array <int, N> edge;
int lowbit(int x) {
	return x & -x;
}
void modify(int x, int y, int n) {
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
using namespace Bit;
vector <int> isl;
int main() {
	freopen("gather.in", "r", stdin);
	freopen("gather.out", "w", stdout);
	int n = read();
	s.fill(n + 1);
	for (int i = 1; i <= n; i++) {
		int x = read();
		if (lst[x]) s[lst[x]] = i;
		else isl.push_back(i);
		lst[x] = i;
	}
	int ans = 0;
	for (auto x : isl)
		modify(x, 1, n);

	for (int i = 1; i <= n; i++) {
		if (s[i - 1] <= n)
			modify(s[i - 1], 1, n);
		ans += query(s[i] - 1) - query(i);
		/* write(query(s[i] - 1) - query(i)), putchar(32); */
	}
	/* puts(""); */
	write(ans), puts("");
	return 0;
}
