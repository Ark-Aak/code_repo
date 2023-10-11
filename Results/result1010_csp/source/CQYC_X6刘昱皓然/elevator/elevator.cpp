#include<bits/stdc++.h>
#define int long long
using namespace std;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')	f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n, k, a[500005], cnt, b[500005], pre, ans;
signed main() {
	freopen("elevator.in", "r", stdin);
	freopen("elevator.out", "w", stdout);
	n = read(); k = read();
	for(int i = 1; i <= n; ++i) {
		a[i] = read();
		a[i]--;
	}
	sort(a + 1, a + n + 1);
	b[1] = 1;
	cnt = 1;
	for(int i = 2; i <= n; ++i) {
		if((n - i + 1) * a[i - 1] * 2 >= (n - i) * a[i] * 2 && cnt <= k) {
			cnt ++;
			b[i] = b[i - 1];
		}
		else {
			cnt = 1;
			b[i] = b[i - 1] + 1; 
		}
	}
	pre = 1;
	for(int i = 2; i <= n; ++i) {
		if(b[i] != b[i - 1]) {
			ans += a[i - 1] * 2 * (n - pre + 1);
			pre = i;
		}
	}
	ans += a[n] * 2 * (n - pre + 1);
	cout<<ans;
	return 0;
}
