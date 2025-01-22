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

string s, t;
unordered_map <int, int> vis;

int compress(string &s) {
	int res = 0;
	for (auto v : s) res <<= 1, res |= v - '0';
	return res;
}

int occur(string &s) {
	int res = 0;
	rep (i, 0, (int) s.size() - 1) {
		bool flg = 0;
		rep (j, 0, (int) t.size() - 1) {
			if (s[i + j] != t[j]) {
				flg = 1;
				break;
			}
		}
		if (!flg) res++;
	}
	return res;
}

void bfs() {
	queue <string> q;
	q.push(s);
	vis[compress(s)] = 0;
	const int st = compress(s);
	int ans = occur(s), minOps = 0;
	while (q.size()) {
		string f = q.front();
		q.pop();
		const int now = compress(f);
		int oc = occur(f);
		if (oc > ans) minOps = vis[now], ans = oc;
		else if (oc == ans) minOps = min(minOps, vis[now]);
		rep (i, 0, (int) f.size() - 2) {
			swap(f[i], f[i + 1]);
			if (!vis[compress(f)] && compress(f) != st) {
				vis[compress(f)] = vis[now] + 1;
				q.push(f);
			}
			swap(f[i], f[i + 1]);
		}
	}
	print(ans), putchar(32), print(minOps), puts("");
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);
#endif
#endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> s >> t;
	bfs();
	return 0;
}
