#include<bits/stdc++.h>
using namespace std;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0'|| ch > '9') {
		if(ch == '-')	f = -1;
		ch = getchar();
	}
	while(ch >= '0'&& ch <= '9') {
		x = (x<<3) + (x<<1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n, a[500005], st[500005], ans[500005], top = 0;
int main() {
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	n = read();
	for(int i = 1; i <= n; ++i) {
		a[i] = read();
		while(top && a[i] >= a[st[top]]) {
			top--;
		}
		ans[i] = ans[st[top]] + 1;
		st[++top] = i;
		printf("%d ", ans[i]);
	}
	return 0;
} 
