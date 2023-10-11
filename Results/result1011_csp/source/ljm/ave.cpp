#include<bits/stdc++.h>
#define N 1000006
using namespace std;
int n;
double a[N];
signed main() {
    freopen("ave.in", "r", stdin);
    freopen("ave.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
    	scanf("%lf", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 2; i <= n; i++) {
		a[i] = (a[i] + a[i - 1]) * 1.00 / 2;
	}
	printf("%.6f", a[n]);
	return 0;
}

