#include<bits/stdc++.h>
#define N 1000006
using namespace std;
int n;
int a[N], S[N], L[N], R[N], top;
int main() {
	freopen("mountain.in", "r", stdin);
	freopen("mountain.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		L[i] = 0;
		R[i] = n + 1;
	} 
	for(int i = n; i >= 1; i--) {
		while(top > 0 && a[i] >= a[S[top]]) top--;
		if(top > 0) R[i] = S[top];
		S[++top] = i;
	} 
	top = 0;
	for(int i = 1; i <= n; i++) {
		while(top > 0 && a[i] >= a[S[top]]) top--;
		if(top > 0) L[i] = S[top];
		S[++top] = i;
	}
	for(int i = 1; i <= n; i++) printf("%d\n", i - L[i] - 1 + R[i] - i - 1);
	return 0;
} 
