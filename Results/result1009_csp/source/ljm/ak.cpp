#include<bits/stdc++.h>
#define int long long
#define N 1000006
using namespace std;
int n, k;
int a[N], b[N], tot;
signed main() {
	freopen("ak.in", "r", stdin);
	freopen("ak.out", "w", stdout);
    scanf("%lld %lld", &n, &k);
    int sum = 0;
    for(int i = 1; i <= n; i++) {
    	scanf("%lld", &a[i]);
    	sum += a[i];
	}
    int j = 1;
    while(1) {
    	b[++tot] = a[j];
    	j += k;
    	if(j > n) break;
	}
	sort(b + 1, b + tot + 1);
	cout << sum - b[tot / 2 + 1];
	return 0;
}

