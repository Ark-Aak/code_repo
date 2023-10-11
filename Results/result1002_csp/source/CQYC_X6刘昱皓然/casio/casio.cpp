#include<bits/stdc++.h>
using namespace std;
int T, p, zs[20000005], id, n;
bool flag[30010000];
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0'|| ch > '9' ) {
		if (ch == '-')	f = -1;
		ch = getchar();
	}
	while(ch >= '0'&& ch <= '9') {
		x = (x<<3) + (x<<1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int main() {
	freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout);
	T = read(); p = read();
	flag[1] = 1;
	for(int i = 2; i <= 5478; ++i) {
		if(!flag[i]) {
			for(int j = 2; j * i <= 30008484; ++j) {
				flag[i * j] = true;
			}
		}
	}
	for(int i = 2; i <= 30008484; ++i) {
		if(!flag[i]) {
			zs[++id] = i;
		}
	}
	while(T--) {
		n = read();
		int ans = *lower_bound(zs + 1, zs + id + 1, n);
		for(int i = n; i < ans; ++i) {
			for(int j = 1; j <= id; ++j) {
				if(i % zs[j] == 0) {
					if(zs[j] <= p) {
						break;
					}
					ans = i;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
