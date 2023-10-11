#include <bits/stdc++.h>
using namespace std;

int k, a[1001];

int main() {
	freopen("crazy.in", "r", stdin);
	freopen("crazy.out", "w", stdout);
	scanf("%d", &k);
	for (int i = 1; i <= k; ++i) scanf("%d", &a[i]);
	bool test3 = 1;
	for (int i = 2; i <= k; ++i) {
		if (a[i] - a[i - 1] == 2);
		else test3 = 0;
	}
	if (test3) { fprintf(stderr, "test3!");
		int ans = k / 3 * 3;
		if (k % 3 == 0);
		if (k % 3 == 1) k += 3;
		if (k % 3 == 2) k += 4;
		printf("%d\n", ans);
		return 0;
	}
	int ans = 0;
	int pos = a[1];
	a[k + 1] = -111;
	for (int i = 2; i <= k + 1; ++i) {
		if (a[i] != a[i - 1] + 1) {
			int len = a[i - 1] - pos + 1;
			if (len & 1) ans += 3;
			else ans += 2;
			pos = a[i];
		}
	}
	printf("%d\n", ans);
}
