#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;
struct node {
	int x, y;
} a[N];
bool cmp(node a, node b) {
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}
vector<int>v[N];
signed main() {
	freopen("ds.in", "r", stdin);
	freopen("ds.out", "w", stdout);
	int n, Q;
	cin >> n >> Q;
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i].x);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i].y);
	sort(a + 1, a + n + 1, cmp);
	while(Q--) {
		int U, R, D, L;
		scanf("%lld%lld%lld%lld", &R, &U, &L, &D);
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			if(L <= a[i].x && a[i].x <= R && D <= a[i].y && a[i].y <= U) {
				int f = 0;
				for(int j = i + 1; j <= n; j++) {
					if((a[j].x > a[i].x && a[j].x <= R) && (a[j].y > a[i].y && a[j].y <= U)) {
						f = 1;
						break;
					}
				}
				if(!f) ++ans;
			}
		}
		printf("%lld\n", ans);
	}
}
