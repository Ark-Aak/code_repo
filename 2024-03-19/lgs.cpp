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

const int MAXN = 1e5 + 5;
string s, t, p;
int nxt[MAXN];

void init_kmp(string t) {
	int n = t.size();
	nxt[0] = -1;
	for (int i = 1, j = -1; i < n; i++) {
		while (j != -1 && t[i] != t[j + 1]) j = nxt[j];
		if (t[i] == t[j + 1]) j++;
		nxt[i] = j;
	}
}

int kmp(string s, string t) {
	int n = s.size(), m = t.size();
	int res = 0;
	for (int i = 0, j = -1; i < n; i++) {
		while (j != -1 && s[i] != t[j + 1]) j = nxt[j];
		if (s[i] == t[j + 1]) j++;
		if (j == m - 1) res++, j = nxt[j];
	}
	return res;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("lgs.in", "r", stdin);
	freopen("lgs.out", "w", stdout);
#endif
#endif
	cin >> s >> t >> p;
	init_kmp(p);
	int n = s.size();
	int res1 = 0, res2 = 0, res3 = 0, res4 = 0;
	rep (i, 0, n) {
		string s1 = s.substr(0, i), s2 = s.substr(i, n - i + 1);
		string S = s1 + t + s2;
		int r = kmp(S, p);
		if (r > res1) {
			res1 = r, res2 = 1, res3 = i, res4 = i;
		}
		else if (r == res1) {
			res2++, res4 = i;
		}
	}
	print(res1), putchar(32);
	print(res2), putchar(32);
	print(res3), putchar(32);
	print(res4), putchar(10);
	return 0;
}
