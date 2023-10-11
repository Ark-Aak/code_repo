#include<bits/stdc++.h>
using namespace std;
int n, k, a[1000005], ans;
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
int main() {
	freopen("ak.in", "r", stdin);
	freopen("ak.out", "w", stdout);
	n = read(); k = read();
	int sum =0;
	for(int i = 1; i<= n ;++i) {
		a[i] = read();
		sum += a[i];
	}
	if(n <= 10) {
		bool op = false;
		while(n > 1) {
			if(!op) {
				int minn = 1e9, id;
				for(int i = 1; i <= n - k + 1; ++i) {
					int x = 0;
					for(int j = i; j <= i + k - 1; ++j) {
						x += a[j];
					}
					if(x < minn)	minn = x, id = i;
				}
				ans += minn;
				for(int i = id + k; i <= n; ++i) {
					a[i - k] = a[i];
				}
				n -= k;
			}
			else {
				int maxx = -1, id;
				for(int i = 1; i <= n - k + 1; ++i) {
					int x = 0;
					for(int j = i; j <= i + k - 1; ++j) {
						x += a[j];
					}
					if(x > maxx)	maxx = x, id = i;
				}
				ans += maxx;
				for(int i = id + k; i <= n; ++i) {
					a[i - k] = a[i];
				}
				n -= k;
			}
		}
		cout<<ans;
	}
	else {
		sort(a + 1, a + n + 1);
		int id = ceil(n / 2.0);
		cout<<sum - a[id];
	} 
	return 0;
}
