#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int MAXN = 1e5 + 5;
string s, t;
int n, m;

bool check(vector <int> &ans) {
	vector <int> p;
	p.push_back(0);
	for (auto v : ans) p.push_back(v);
	p.push_back(n + 1);
	rep (i, 0, (int) p.size() - 1) {
		bool flg = 1;
		rep (j, p[i] + 2, p[i + 1] - 1) {
			flg &= s[j] == s[j - 1];
		}
		if (!flg) return false;
	}
	return true;
}

void wrong() {
	int lp = 1, rp = 1;
	vector <int> ans;
	while (rp <= m && lp <= n) {
		while (rp <= m && lp <= n && s[lp] != t[rp]) lp++;
		while (rp <= m && lp <= n && s[lp] == t[rp]) {
			ans.push_back(lp);
			lp++, rp++;
		}
	}
	if (check(ans)) {
		puts("YES");
		for (auto v : ans) print(v), putchar(32);
		puts("");
		exit(0);
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
#endif
#endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> s >> t;
	n = s.size(), m = t.size();
	s = ' ' + s, t = ' ' + t;
	wrong();
	puts("NO");
	return 0;
}
