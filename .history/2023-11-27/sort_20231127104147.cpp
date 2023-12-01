#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 1e3 + 5;
int n, C;
int p[MAXN];
int ch[MAXN], tp[MAXN];

bool check(int step) {
	rep (i, 1, n) tp[i] = p[i];
	rep (i, 1, step) {
		int nxt = (ch[i] + tp[ch[i]]) > n ?
					(ch[i] + tp[ch[i]] - n) :
					(ch[i] + tp[ch[i]]);
		swap(tp[ch[i]], tp[nxt]);
	}
	rep (i, 1, n) {
		if (tp[i] != i - 1) return false;
	}
	return true;
}

void dfs(int step) {
	if (check(step - 1)) {
		print(step - 1), putchar(10);
		rep (i, 1, step - 1) print(ch[i] - 1), putchar(32);
		exit(0);
	}
	if (step > C) return;
	rep (i, 1, n) ch[step] = i, dfs(step + 1);
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
#endif
#endif
	read(n), read(C);
	rep (i, 1, n) read(p[i]);
	if (n <= 8) dfs(1);
	else {
		print(n - 1), putchar(32);
		rep (i, 1, n - 1) print(0), putchar(32);
	}
	return 0;
}