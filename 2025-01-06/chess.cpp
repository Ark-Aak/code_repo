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

const int MAXN = 2e5 + 5;
const int MOD = 998244353;
int n;
vector <int> G[MAXN];
int dp[MAXN], pre[MAXN];
bool sub2 = 1;

namespace subtask2 {
	
	void solve() {
		dp[1] = pre[1] = pre[2] = 1;
		dp[2] = 0;
		rep (i, 3, n - 1) {
			dp[i] = (pre[i - 2]) % MOD;
			pre[i] = (pre[i - 1] + dp[i]) % MOD;
		}
		print(pre[n - 1] * 2 % MOD);
		puts("");
	}

} // namespace subtask2

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
#endif
#endif
	n = read();
	if (n == 2) return puts("2"), 0;
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
		if (G[u].size() > 2 || G[v].size() > 2) sub2 = 0;
	}
	if (sub2) return subtask2::solve(), 0;
	else if (G[1].size() == n - 1) return puts("0"), 0;
	else {
		
	}
	return 0;
}
