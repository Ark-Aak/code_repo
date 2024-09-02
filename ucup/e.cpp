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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int n;
int l[65], r[65], cnt[65], nw = 0;
int w[65], ans = -1e9;

void dfs(int step, int sum) {
	if (step > n) {
		ans = max(ans, sum);
		return;
	}
	if (nw > 0) {
		cnt[nw]++;
		dfs(step + 1, sum - w[cnt[nw] - 1] + w[cnt[nw]]);
		cnt[nw]--;
	}
	nw++;
	cnt[nw]++;
	dfs(step + 1, sum + w[1]);
	cnt[nw]--;
	nw--;
}

signed main() {
	n = read();
	rep (i, 1, n) l[i] = read(), r[i] = read();
	rep (i, 1, n) w[i] = read();

	return 0;
}
