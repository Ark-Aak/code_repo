#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
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
string read_() {
	string ans;
	char c = getchar();
	while (c < 'a' || c > 'z')
		c = getchar();
	while (c >= 'a' && c <= 'z') {
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
const int N = 1e5 + 5, M = 28;
array <int, N> pre, f;
array <int, M> cur;
int main() {
	freopen("reinforce.in", "r", stdin);
	freopen("reinforce.out", "w", stdout);
	string s = read_();
	int n = s.size();
	s = " " + s;
	int maxn = 0;
	for (int i = 1; i <= n; i++)
		maxn = max(maxn, ++cur[s[i] - 'a']);
	write(maxn), puts("");
	return 0;
}
