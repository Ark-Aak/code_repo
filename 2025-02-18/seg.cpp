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

const int MAXN = 3e5 + 5;
const int V = 0.65 * 1e6;
int n;

struct node {

	int l, r, id;

	bool operator <(const node &t) const {
		return l != t.l ? l < t.l : r < t.r;
	}
} p[MAXN];

int dp[MAXN], lst[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("seg.in", "r", stdin);
	freopen("seg.out", "w", stdout);
#endif
#endif
	scanf("%d", &n);
	rep (i, 1, n) {
		double a, b;
		scanf("%lf %lf", &a, &b);
		p[i].l = a * 1e6;
		p[i].r = b * 1e6;
		p[i].id = i;
	}
	sort(p + 1, p + 1 + n);
	dp[1] = p[1].r - p[1].l + 1;
	lst[1] = 1;
	rep (i, 2, n) {
		dp[i] = p[i].r - p[i].l + 1;
		lst[i] = i;
		rep (j, (n <= 5000 ? 1 : max(1, i - 700)), i - 1) {
			int cr = max(0, p[j].r - p[i].l + 1);
			int val = dp[j] - cr + min(p[i].r - p[i].l + 1, p[i].r - p[j].r);
			if (dp[i] < val) dp[i] = val, lst[i] = j;
		}
	}
	int mxa = 0;
	rep (i, 1, n) mxa = max(mxa, dp[i]);
	rep (i, 1, n) {
		if (dp[i] == mxa) {
			int cur = i;
			vector <int> v;
			do {
				v.push_back(p[cur].id);
				cur = lst[cur];
			} while (lst[cur] != cur);
			v.push_back(p[cur].id);
			sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());
			print(v.size()), puts("");
			for (auto val : v) print(val), putchar(32);
			puts("");
			break;
		}
	}
	return 0;
}
