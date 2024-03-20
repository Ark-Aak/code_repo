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
const int MAXN = 105;
int n, C;
int A[MAXN][MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("bigben.in", "r", stdin);
	freopen("bigben.out", "w", stdout);
#endif
#endif
	n = read(), C = read();
	rep (i, 1, n) {
		rep (j, 1, n) {
			if (i == j) A[i][j] = 1;
			else if (i != j && j % i == 0) A[i][j] = 0;
			else A[i][j] = C;
		}
	}
	int ans = 1;
	rep (i, 1, n) {
		rep (j, i + 1, n) {
			while (A[j][i]) {
				int t = A[i][i] / A[j][i];
				rep (k, i, n) A[i][k] = (A[i][k] - A[j][k] * t % MOD + MOD) % MOD;
				swap(A[i], A[j]);
				ans = -ans;
			}
		}
		if (!A[i][i]) return puts("0"), 0;
		ans = ans * A[i][i] % MOD;
	}
	print((ans + MOD) % MOD);
	return 0;
}
