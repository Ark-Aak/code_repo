#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <ctime>
#define int long long
using namespace std;
/* #ifdef ONLINE_JUDGE */

#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 23], *p1 = buf, *p2 = buf, ubuf[1 << 23], *u = ubuf;

/* #endif */
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
	while (c < '0' || c > '9')
		c = getchar();
	while (c >= '0' && c <= '9') {
		ans += c;
		c = getchar();
	}
	return ans;
}
string read__() {
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

const int N = 1e6 + 5;
array <int, N> isl;
array <array <int, 12>, N> f;

string s1, s2;
bool dfs(int step, int sum, int n) {
	if (~f[step][sum]) return f[step][sum];
	if (step == n) {
		if (!sum) return true;
		else return false;
	}
	bool tp1 = dfs(step + 1, (sum + isl[step + 1]) % 11, n),
		tp2 = dfs(step + 1, sum, n);
	if (s2[step + 1] == 'y')
		return f[step][sum] = (tp1 || tp2);
	else
		return f[step][sum] = (tp1 && tp2);
}
signed main() {
	freopen("yo.in", "r", stdin);
	freopen("yo.out", "w", stdout);
	int n = read();
	s1 = " " + read_(), s2 = " " + read__();
	array <int, 12> tp;
	tp.fill(-1);
	f.fill(tp);
	int idx = 1;
	for (int i = n; i; i--) {
		isl[i] = (s1[i] - '0') * idx % 11;
		idx = idx * 10 % 11;
	}
	if (dfs(0, 0, n)) {
		if (s2[1] == 'y') puts("yoimiya");
		else puts("oimiya");
	}
	else {
		if (s2[1] == 'y') puts("oimiya");
		else puts("yoimiya");
	}
	/* cout << clock() << endl; */
	return 0;
}
