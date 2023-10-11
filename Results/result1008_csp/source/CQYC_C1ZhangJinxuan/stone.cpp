#include <bits/stdc++.h>
using namespace std;

int a[101], n, k;
long long ans = 0;
const int p = 1e9 + 7;

int stone() {
	int ans = 1 << 30, sum = 0, have = 0;
	for (int j = 1; j <= n; ++j) {
		sum += a[j];
		if (a[j] == j) {
			have = 1;
			int tmp = a[j];
			a[j] = 0;
			for (int k = 1; k < j; ++k) a[j]++;
			ans = min(ans, stone());
			a[j] = tmp;
			for (int k = 1; k < j; ++k) a[j]--;
		}
	}
	if (have == 0) return sum;
	else return ans;
}

void dfs(int i) {
	if (i == n + 1) {
		(ans += stone()) %= p;
		return;
	} 
	for (int j = 0; j <= k; ++j) {
		a[i] = j;
		dfs(i + 1);
	}
}

int main() {
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	scanf("%d%d", &n, &k);
	dfs(1);
	printf("%lld\n", ans);
}
