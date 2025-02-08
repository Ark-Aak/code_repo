#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define int ll

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

const int MAXN = 15;
int c, n;
ll a[MAXN];
int cnt, l[MAXN * MAXN], r[MAXN * MAXN];
int ch[MAXN * MAXN];
ll ans[MAXN * MAXN];
bool flg = 0;

void dfs(int step, int qcnt) {
	if (c == 7 && qcnt > 12) return;
	if (step > cnt) {
		if (qcnt < 12) return;
		int cho = 0;
		rep (i, 1, cnt) cho += ch[i];
		ll tot = 0;
		rep (i, 1, n) {
			rep (j, i, n) {
				ll sum = a[n] - (a[j] - a[i - 1]);
				rep (k, 1, cnt) {
					if (!ch[k]) continue;
					if (l[k] < i || r[k] > j) continue;
					sum = max(sum, a[n] - (a[j] - a[i - 1]) + a[r[k]] - a[l[k] - 1]);
				}
				tot += sum;
			}
		}
		ans[cho] = max(ans[cho], tot);
		return;
	}
	ch[step] = 1;
	dfs(step + 1, qcnt + 1);
	ch[step] = 0;
	dfs(step + 1, qcnt);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("sunrise.in", "r", stdin);
	freopen("sunrise.out", "w", stdout);
#endif
#endif
	c = read();
	n = read();
	rep (i, 1, n) a[i] = read(), a[i] += a[i - 1];
	rep (i, 1, n) {
		rep (j, i, n) {
			l[++cnt] = i;
			r[cnt] = j;
		}
	}
	dfs(1, 0);
	rep (i, 1, n * (n + 1) / 2) print(ans[i]), puts("");
	return 0;
}
