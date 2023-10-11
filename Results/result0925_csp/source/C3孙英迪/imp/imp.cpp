#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
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
const int N = 3e5 + 5;
struct Node {
	int x, y, dis;
} edge[N];
vector <int> isl;
bool cmp(Node a, Node b) {
	return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}
bool check(int x, int y, Node k) {
	if (k.x >= x && k.x <= y &&
		k.y >= x && k.y <= y) 
		return true;
	return false;	
}
signed main() {
	freopen("imp.in", "r", stdin);
	freopen("imp.out", "w", stdout);
	int n = read();
	for (int i = 1; i <= n; i++) {
		edge[i].x = read(), edge[i].y = read(), edge[i].dis = read();
		isl.push_back(edge[i].x);
		isl.push_back(edge[i].y);
	}
	sort(isl.begin(), isl.end());
	unique(isl.begin(), isl.end());
	sort(edge + 1, edge + 1 + n, cmp);
	int ans_ = 0;
//	for (auto x : isl) {
//		write(x), putchar(32);	
//	}
//	puts("");
//	for (int i = 1; i <= n; i++) {
//		write(edge[i].x), putchar(32);
//		write(edge[i].y), putchar(32);
//		write(edge[i].dis), puts("");	
//	}
//	puts("@");
	for (int i = 0; i < isl.size(); i++) {
		int tp = 0, ans = 0;
		for (int j = i; j < isl.size(); j++) {
			while (tp < n && edge[tp + 1].x <= isl[j]) {
				if (check(isl[i], isl[j], edge[tp + 1]))
					ans += edge[tp + 1].dis;
				tp++;
			}
			ans_ = max(ans_, ans - (isl[j] - isl[i]));
//			write(i), putchar(32);
//			write(j), putchar(32);
//			write(ans), puts("");
		}
	}
	write(ans_), puts("");
	return 0;	
}
