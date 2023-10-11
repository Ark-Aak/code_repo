#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int T, n, m;
int lcm(int a, int b) {
	return a * b / __gcd(a, b);
}
int f(int a, int b) {
	if(a > b) swap(a, b);
	return lcm(a, b) / a - 1 + lcm(a, b) / b - 1;
}
int sum[2005][20005];
signed main() {
    scanf("%lld", &T);
    for(int i = 1; i <= 1000; i++)
    for(int j = 1; j <= 1000; j++) sum[i][j] = (sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + f(i, j) + mod) % mod;
    while(T--) {
    	scanf("%lld %lld", &n, &m);
    	printf("%lld\n", sum[n][m]);
	}
	return 0;
}

