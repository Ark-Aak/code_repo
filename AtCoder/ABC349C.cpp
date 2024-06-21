#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

signed main() {
	string str, t;
	cin >> str >> t;
	str = ' ' + str;
	t = ' ' + t;
	int n = str.size() - 1;
	rep (i, 1, n) str[i] -= 'a' - 'A';
	int m = t.size() - 1;
	int lp = 0;
	int cnt = 0;
	rep (i, 1, m) {
		bool moved = 0;
		while (lp <= n && str[lp] != t[i]) {
			lp++;
			moved = 1;
		}
		if (str[lp] == t[i] && moved) cnt++;
		if (lp == n && cnt < m) break;
		if (cnt >= m) return puts("Yes"), 0;
	}
	if (t[3] == 'X') {
		cnt = 0;
		lp = 0;
		m--;
		rep (i, 1, m) {
			bool moved = 0;
			while (lp <= n && str[lp] != t[i]) {
				lp++;
				moved = 1;
			}
			if (str[lp] == t[i] && moved) cnt++;
			if (lp == n && cnt < m) break;
			if (cnt >= m) return puts("Yes"), 0;
		}
	}
	puts("No");
	return 0;
}
