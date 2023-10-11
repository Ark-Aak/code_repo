#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int n, k;
int a[N], f[N], p[20], b[20], tot;
signed main() {
	freopen("elevator.in", "r", stdin);
	freopen("elevator.out", "w", stdout);
    scanf("%lld %lld", &n, &k);
    int h = 0;
    for(int i = 1; i <= n; i++) {
    	scanf("%lld", &a[i]);
    	f[i] = 1e18;
    	h = max(h, a[i]);
	}
	sort(a + 1, a + n + 1);
    for(int i = n; i >= 1; i--) {
    	int maxn = 0;
    	for(int j = i; j <= min(i + k - 1, n); j++) {
    		maxn = max(maxn, a[j]);
    		f[i] = min(f[i], f[j + 1] + (maxn - 1) * 2 * (n - i + 1)); 
		}
	}
	cout << f[1];
	return 0;
}
