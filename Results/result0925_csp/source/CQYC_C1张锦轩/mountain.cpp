#include <bits/stdc++.h>
using namespace std;

int n;
int st[1000001], top;
int prv[1000001], nxt[1000001], a[1000001];

int main() {
	freopen("mountain.in", "r", stdin);
	freopen("mountain.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		while (top && a[i] > a[st[top]]) {
			nxt[st[top]] = i;
			--top;
		}
		st[++top] = i;
	}
	while (top) nxt[st[top--]] = n + 1;
	top = 0;
	for (int i = n; i >= 1; --i) {
		while (top && a[i] > a[st[top]]) {
			prv[st[top]] = i;
			--top;
		}
		st[++top] = i;
	}
	
	for (int i = 1; i <= n; ++i) {
		printf("%d\n", nxt[i] - prv[i] - 2);
	}
}
