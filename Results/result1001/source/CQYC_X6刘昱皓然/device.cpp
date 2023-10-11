#include<bits/stdc++.h>
using namespace std;
int T, k, n;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9') {
		if(ch == '-')	f = -1;
		ch = getchar();
	}
	while(ch >= '0'&& ch <= '9') {
		x = (x<<3) + (x<<1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int main() {
	freopen("device.in","r",stdin);
	freopen("device.out","w",stdout);
	T = read();
	while(T--) {
		k = read(), n = read();
		if(n == 0) {
			printf("%d\n",1);
			continue;
		}
		int a = k / 100, b = k / 10 % 10, c = k % 10;
		if(a == b&& b == c) {
			printf("%d\n",1);
			continue;
		}
		if(a != b&& b != c&& a != c) {
			if(n == 1)	printf("%d\n",24);
			else	printf("%d\n",27);
			continue;
		}
		if(n == 1)	printf("%d\n",7);
		else	printf("%d\n",8);
	}
	return 0;
}
