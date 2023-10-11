#include <bits/stdc++.h>
using namespace std;

int k;
long long ans = 0, n, m, x[1000001], y[1000001];
const int p = 1e9 + 7;
char opt[1000002][3];
long long col[1000001], row[1000001];

inline long long value(int x, int y) { return (x - 1) * m % p + y % p; }
bool vis[1000001];
int optst[1000001], top;
int main() {
	freopen("wisdom.in", "r", stdin);
	freopen("wisdom.out", "w" ,stdout);	
	scanf("%lld%lld%d", &n, &m, &k);
	if (n <= 1000 && m <= 1000) {
		for (int i = 1; i <= 1000; ++i) {
			col[i] = 1;
		}
		for (int i = 1; i <= 1000; ++i) row[i] = 1;
		__int128 ans = 0;
		for (int i = 1; i <= k; ++i) {
			srand(time(0) + i + clock());
			scanf("%s%lld%lld", opt[i] + 1, &x[i], &y[i]);
			if (opt[i][1] == 'R') {
				row[x[i]] = (row[x[i]] * y[i]) % p;
			} else col[x[i]] = (col[x[i]] * y[i]) % p;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				ans += value(i, j) * (row[i] * col[j] % p) % p;
				ans %= p;
			} 
		}
		printf("%lld\n", (long long)ans);
	} else {
		for (int i = 1; i <= 1000000; ++i) {
			col[i] = 1;
		}
		for (int i = 1; i <= 1000000; ++i) row[i] = 1;
		__int128 ans = (((1 + n * m) % p) * ((n * m) % p)) % p * 500000004  % p;
		for (int i = 1; i <= k; ++i) {
			scanf("%s%lld%lld", opt[i] + 1, &x[i], &y[i]);
			__int128 yn;
			top = 0;
			if (opt[i][1] == 'R') {
				yn = ((value(x[i], 1) + value(x[i], m)) % p * m % p * 500000004) % p * (row[x[i]]) % p;	
				for (int j = 1; j < i; ++j) {
					if (opt[j][1] == 'S' && vis[x[j]] == 0) {
						yn += (row[x[i]]) * (col[x[j]] - 1) % p * value(x[i], x[j]) % p;
						vis[x[j]] = 1;
						optst[++top] = x[j];
					}
				}
				yn = (yn * (y[i] - 1)) % p;
			} else {
				yn = ((value(1, x[i]) + value(n, x[i])) % p * n % p * 500000004) % p * (col[x[i]])  % p;
				for (int j = 1; j < i; ++j) {
					if (opt[j][1] == 'R' && vis[x[j]] == 0) {
						yn += (col[x[i]]) * (row[x[j]] - 1) % p * value(x[j], x[i]) % p;
						vis[x[j]] = 1;
						optst[++top] = x[j];
					}
				}
				yn = (yn * (y[i] - 1)) % p;
			}
			while (top) vis[optst[top--]] = 0;
			if (opt[i][1] == 'R') {
				row[x[i]] = (row[x[i]] * y[i]) % p;
			} else col[x[i]] = (col[x[i]] * y[i]) % p;
			ans = (ans + yn) % p;
		}
		printf("%lld\n", (long long)(ans % p + p) % p);
	}
	return 0;
}
/*
1 1 2
R 1 0
S 1 0

78
0
42
-128

1 2  3  4
5 6  7  8
9 10 11 12

60 + 44 = 104

1  2  3  4
20 24 28 32
9  10 11 12

42

15 + 20 + 14 + 21 = 70
*/
