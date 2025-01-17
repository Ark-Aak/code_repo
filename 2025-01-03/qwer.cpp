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

const int MAXN = 2e5 + 5;
const int INF = 1e9;
int n, q, pre[MAXN], eN[MAXN];
int k = 0, r = 0;

namespace subtask1 {
	
	void solve() {
		int tp = n, sum = 0;
		for (int i = 1; tp; i++) {
			int x = min(tp, (i + 1) / 2);
			if (x == tp) {
				k = i - 1;
				r = x;
			}
			tp -= x;
			sum += x * i;
		}
		print(sum), puts("");
	}
} // namespace subtask1

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("qwer.in", "r", stdin);
	freopen("qwer.out", "w", stdout);
#endif
#endif
	n = read(), q = read();
	subtask1::solve();
	rep (i, 0, k) eN[i] = (k - i + 1) / 2;
	for (int i = r, cur = k; i >= 1; i--, cur -= 2) eN[cur]++;
	pre[0] = eN[0];
	rep (i, 1, k) pre[i] = pre[i - 1] + eN[i];
	while (q --> 0) {
		int b = read();
		int pos = lower_bound(pre, pre + k + 1, (b + 1) / 2) - pre;
		if (pos < 0) pos = 0;
		if (pos > 0) b -= pre[pos - 1];
		int ans = 0;
		rep (i, pos, INF) {
			if (b > 2 * eN[i] - 1) b -= eN[i];
			else {
				if (b & 1) { ans = b + i; break; }
				else b >>= 1;
			}
		}
		print(ans), puts("");
	}
	return 0;
}
// x->a*2^b,a+b=x
