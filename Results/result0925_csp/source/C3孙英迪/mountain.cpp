#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <stack>
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
const int N = 1e6 + 5;
array <int, N> s;
stack <int> stk;

array <int, N> ls, rs;
int main() {
	freopen("mountain.in", "r", stdin);
	freopen("mountain.out", "w", stdout);
	int n = read();
	for (int i = 1; i <= n; i++)
		s[i] = read();
	ls.fill(0), rs.fill(n + 1);
	for (int i = 1; i <= n; i++) {
		while (!stk.empty() && s[stk.top()] <= s[i])
			stk.pop();
		if (stk.size())
			ls[i] = stk.top();
		stk.push(i);
	}
	while (stk.size()) stk.pop();
	for (int i = n; i >= 1; i--) {
		while (!stk.empty() && s[stk.top()] <= s[i])
			stk.pop();
		if (stk.size())
			rs[i] = stk.top();
		stk.push(i);
	}
	for (int i = 1; i <= n; i++) {
//		write(ls[i]), putchar(32);
//		write(rs[i]), putchar(32);
		write(rs[i] - ls[i] - 2), puts("");
	}
	return 0;	
}
