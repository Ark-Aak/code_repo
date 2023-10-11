#include<bits/stdc++.h>
#define int long long 
#define ull unsigned long long
using namespace std;
const int N = 2.5e5 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
#define SEG (int)(N << 2)
#define EG (int)(N << 1)
int n;
struct node {
	int x, y, c;
}a[N], b[N];
signed main() {
	freopen("imp.in", "r", stdin);
	freopen("imp.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].c;
		b[i] = a[i];
	}
	sort(a + 1, a + n + 1, [](node x, node y){
		return max(x.x, x.y) < max(y.x, y.y);
	});
	sort(b + 1, b + n + 1, [](node x, node y){
		return min(x.x, x.y) < min(y.x, y.y);
	});
	int ans = -INF;
	for(int j = 1; j <= n; j++) {
		int t = min(b[j].x, b[j].y);
		int sum = 0;
		for(int i = 1; i <= n; i++) {
			int c = max(a[i].x, a[i].y) - t;
			if(min(a[i].x, a[i].y) >= t) {
				sum += a[i].c;
				//if(t == 1) cerr << sum << ' ' << c << "\n";
				if(max(a[i + 1].x, a[i + 1].y) - t != c || i + 1 > n) ans = max(ans, sum - c);
			}
			
			//cerr << i << " " << a[i].x << " " << a[i].y << " " << c << " " << sum << "\n";
			//if(ans == 3) cerr << c << "\n";
		}
	}
	ans = max(ans, 0ll);
	cerr << ans << "\n";
	cout << ans << "\n";
	return 0;
}
