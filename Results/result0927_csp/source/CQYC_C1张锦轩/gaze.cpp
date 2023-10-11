#include <bits/stdc++.h>
using namespace std;

int n, m, opt, x, y, a[200001];
 
int main() {
	freopen("gaze.in", "r", stdin);
	freopen("gaze.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	a[0] = 2e9;
	while (m--) {
		scanf("%d%d", &opt, &x);
		if (opt == 1) {
			int ans = 0, pts = n;
			for (int i = 1; i <= n; ++i) {
				bool pre = (a[i - 1] < x);
				bool now = (a[i] < x);
				if (now) --pts;
				if (pre ^ now && now) {
					++ans;
				}
				if (now && i != n && i != 1) ++ans;
			}
			printf("%d\n", pts - (n - 1 - ans));
		} else scanf("%d", &y), a[x] = y;
	}
	return 0;
}
