#include <bits/stdc++.h>
using namespace std;

int n, m, a[100001];
int f[501][501][501];
const int p = 998244353;

long long dfs(int i, int last, int cnt) {
	if (f[i][last][cnt] != -1) return f[i][last][cnt];
	if (i == n + 1) {
		return 1;	
	}
	long long tot = 0;
	for (int j = 1; j <= m; ++j) {
		if (j == last) {
			if (cnt + 1 <= a[j]) tot += dfs(i + 1, j, cnt + 1);
		} else tot += dfs(i + 1, j, 1);
		tot %= p;
	}
	return f[i][last][cnt] = tot;
}

int main() {
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	memset(f, 255, sizeof(f));
	scanf("%d%d", &n, &m);
	if (n <= 500 && m <= 500) {
		for (int i = 1; i <= m; ++i) {
			scanf("%d", &a[i]);
		}
		printf("%lld\n", dfs(1, 0, 0));
	} else puts("0");
	return 0;
}
