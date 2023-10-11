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
vector <int> rev(vector <int> x, vector <int> y) {
	vector <int> ans(x.size(), 0);
	for (int i = 0; i < x.size(); i++)
		ans[x[i] - 1] = y[i];
	return ans;
}
void write(vector <int> x) {
	for (auto y : x)
		write(y), putchar(32);
}
vector <int> operator +(vector <int> a, vector <int> b) {
	return rev(a, b);
}
int main() {
	/* freopen("permutation.in", "r", stdin); */
	/* freopen("permutation.out", "w", stdout); */
	vector <int> p, q;
	int n = read(), k = read();
	for (int i = 1; i <= n; i++)
		p.push_back(read());
	for (int i = 1; i <= n; i++)
		q.push_back(read());
	vector <int> ans;
	for (int i = 2; i <= k; i++) {
		ans = rev(p, q);
		p = q, q = ans;
	}
	write(ans), puts("");
	return 0;
}
