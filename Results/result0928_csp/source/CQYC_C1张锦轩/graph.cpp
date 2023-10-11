#include <bits/stdc++.h>
using namespace std;

int n;
int x[100001], y[100001], fa[100005];

int get_fa(int i) {
	if (fa[i] == i) return i;
	return fa[i] = get_fa(fa[i]);
}

struct Point {
	int x, y;
	bool operator < (const Point &b) const {
		if (x != b.x) return x < b.x;
		return y < b.y;
	}
} a[1000001];

inline int read() {
	int l;
	scanf("%d", &l);
	return l;
}

void solve() {
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; ++i) {
		a[i].x = read(); a[i].y = read();
		fa[i] = i;
	}
	sort(a + 1, a + n + 1);
	int ans = n;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if ((a[i].x >= a[j].x && a[i].y >= a[j].y) || (a[i].x <= a[j].x && a[i].y <= a[j].y)) {
				int fi = get_fa(i);
				int fj = get_fa(j);
				if (fi != fj) {
					--ans;
					fa[fi] = fj;
				} else break;
			}
		}
	}	
	printf("%d\n", ans);
}

int main() {
	solve();
	return 0;
}
