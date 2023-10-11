#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5 * 1e5 + 10;
int a[N];
signed main() {
	freopen("elevator.in", "r", stdin);
	freopen("elevator.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int last = 0, ans = 0;
	for(int i = 1; i <= n; i++) cin >> a[i], --a[i], ans += a[i] * 2;
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		int cnt = 1;
		while(a[i] == a[i + 1]) ++cnt, ++i;
		
		int l = i + 1, r = n, pos = -1;
		int add1 = (n - i) * a[i] * 2;
		while(l <= r) {
			int mid = (l + r) / 2;
			int add2 = (mid - i) * (a[mid] - a[i]) * 2;
			if(add2 < add1) {
				pos = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if(pos == -1) ans += add1;
		else ans += (pos - i - 1) * (a[pos] - a[i]) * 2, i = pos;
		last = i;
	}
	cout << ans;
}
