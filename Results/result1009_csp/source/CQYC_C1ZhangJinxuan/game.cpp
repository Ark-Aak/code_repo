#include <bits/stdc++.h>
using namespace std;

inline int gcd(int a, int b) {return b ? gcd(b, a % b): a;};
inline int f(int n, int m) {
	return (n + m) / gcd(n, m) - 2;
}
int t, n, m;
long long sum[1001][1001];
const int p = 1e9 + 7;
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= 1000; ++j) {
			sum[i][j] = (sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + f(i, j)) % p;
		}
	}
	while (t--) {
		scanf("%d%d", &n, &m);
		if (n <= 1000 && m <= 1000) printf("%lld\n", sum[n][m]);
	}
	return 0;
}
/*
ans = $(\sum_{i=1}{n} \sum_{i=1}{m}\frac{i+j}{\gcd(i,j)}) - 2nm$
*/
