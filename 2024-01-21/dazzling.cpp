#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

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

const int MOD = 998244353;

int n, w, ans;
int a[200005];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int calc(int k) {
	int res = 0;
	rep (i, 1, k - 1) res += (a[i] == a[i + 1] + 1);
	return res;
}

void dfs(int step, int sum) {
	if (step == 1) {
		rep (i, 1, n) {
			a[step] = i;
			dfs(step + 1, a[step]);
		}
	}
	else {
		if (sum == n) {
			ans += qpow(w, calc(step - 1));
			ans %= MOD;
			return;
		}
		if (sum > n) return;
		if (a[step - 1] > 1) a[step] = a[step - 1] - 1, dfs(step + 1, sum + a[step - 1] - 1);
		if (a[step - 1] < n) a[step] = a[step - 1] + 1, dfs(step + 1, sum + a[step - 1] + 1);
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("dazzling.in", "r", stdin);
	freopen("dazzling.out", "w", stdout);
#endif
#endif
	n = read(), w = read();
	if (w == 0 && n > 30) {
		// (a + b) * (b - a + 1) / 2 = n
		rep (i, 1, n) {
			// (sqrt(1 + 4x) - 1) / 2
			int x = 2 * n - i + i * i;
			int b = sqrt(1 + 4 * x) - 1;
			b /= 2;
			if (b * b + b != x) continue;
			if (b < i) continue;
			ans++;
			ans %= MOD;
		}
		print(ans);
		return 0;
	}
	dfs(1, 0);
	print(ans);
	return 0;
}
