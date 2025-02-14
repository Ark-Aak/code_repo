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

const int MAXN = 5e5 + 5;
struct node {
	int x, y;

	bool operator<(const node &t) const { 
		return x == t.x ? y < t.y : x < t.x;
	}

	node() { x = 0, y = 0; }
	node(int x, int y) { this -> x = 0, this -> y = 0; }

} s[MAXN], t[MAXN];

int n, m;
int cnt[MAXN];

inline node fws(int i) { return node(s[i].x, s[i].y); }
inline node bks(int i) { return node(s[i].y, s[i].x); }
inline node fwt(int i) { return node(t[i].x, t[i].y); }
inline node bkt(int i) { return node(t[i].y, t[i].x); }

map <set <pii>, int> mp;

void dfs(int step) {
	
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("super.in", "r", stdin);
	freopen("super.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	rep (i, 1, m) {
		s[i].x = read(), s[i].y = read();
		cnt[s[i].x]++, cnt[s[i].y]++;
		if (s[i].x > s[i].y) swap(s[i].x, s[i].y);
	}
	rep (i, 1, m) {
		t[i].x = read(), t[i].y = read();
		cnt[t[i].x]--, cnt[t[i].y]--;
		if (t[i].x > t[i].y) swap(t[i].x, t[i].y);
	}
	bool flg = 1;
	rep (i, 1, n) flg &= cnt[i] == 0;
	if (!flg) return puts("NO"), 0;
	puts("YES");
	puts("0");
	return 0;
}
