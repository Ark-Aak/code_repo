#include<bits/stdc++.h>
#define int long long
using namespace std;
int T, k, n;
signed main() {
	freopen("device.in", "r", stdin);
	freopen("device.out", "w", stdout);
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld %lld", &k, &n);
		int a = k % 10;
		int b = (k - a) / 10 % 10;
		int c = (k - a - 10 * b) / 100 % 10;
		if(n == 0) {
			printf("1\n");
			continue;
		}
		if(n == 1) {
			if(a == b && b == c) {
				printf("1\n");
				continue;
			}
			if(a == b || a == c || b == c) {
				printf("7\n");
				continue;
			}
			printf("24\n");
			continue;
		}
		if(n > 1) {
			if(a == b && b == c) {
				printf("1\n");
				continue;
			}
			if(a == b || a == c || b == c) {
				printf("8\n");
				continue;
			}
			printf("27\n");
			continue;
		}
	}
	return 0;
}
