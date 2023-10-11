#include <bits/stdc++.h>
using namespace std;

int n, k, a[1000001], tmp[1000001];
long long sum;

long long dfs(int n, bool who) {
	if (n == 1) {
		return sum - a[1];
	}
	int tmp[12];
	long long ans = -1;
	for (int j = 1; j <= n - k + 1; ++j) {
		for (int j = 1; j <= n; ++j) tmp[j] = a[j];
		for (int tmp = j + k; tmp <= n; ++tmp) a[tmp - k] = a[tmp];
		if (ans == -1) ans = dfs(n - k, who ^ 1);
		else if (who == 1) ans = min(ans, dfs(n - k, 0));
		else ans = max(ans, dfs(n - k, 1));
		for (int j = 1; j <= n; ++j) a[j] = tmp[j];
	}
	return ans;	
}

int main() {
	freopen("ak.in", "r", stdin);
	freopen("ak.out", "w" ,stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}	
	if (k == 1 || n >= 12) {
		sort(a + 1, a + n + 1);
		printf("%lld\n", sum - a[n / 2 + (n & 1)]);
	} else {
		printf("%lld\n", dfs(n, 1));
	}
	return 0;
}
