#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define inv 500000004
#define N 1000006
using namespace std;
int n, m, Q;
int a[N], b[N];
int A[N], tot1, B[N], tot2;
int aa[N], bb[N], cnt1, cnt2;
int Pow(int a, int n) {
	if(n == 0) return 1;
	if(n == 1) return a % mod;
	int x = Pow(a, n / 2);
	if(n % 2 == 0) return x * x % mod;
	else return x * x % mod * a % mod;
}
int find_hang(int x) {
	int s = 1 + (x - 1) * m;
	return (s + (s + m - 1)) * m / 2;
}
int find_lie(int x) {
	int s = x, mo = x + (n - 1) * m;
	return (s + mo) * n / 2;
}
int find(int x, int y) {
	int d = 1 + (x - 1) * m;
	return d + (y - 1);
}
signed main() {
	freopen("wisdom.in", "r", stdin);
	freopen("wisdom.out", "w", stdout);
    scanf("%lld %lld %lld", &n, &m, &Q);
    for(int i = 1; i <= n; i++) a[i] = 1;
    for(int i = 1; i <= m; i++) b[i] = 1;
    while(Q--) {
    	char c;
    	int x, y;
    	cin >> c;
    	scanf("%lld %lld", &x, &y);
    	if(c == 'R') {
    		a[x] *= y;
    		a[x] %= mod;
    		A[++tot1] = x;
		}
    	else {
    		b[x] *= y;
    		b[x] %= mod;
    		B[++tot2] = x;
		} 
	}
	int sum = (1 + n * m) % mod * n * m % mod * inv % mod;
	//cout << sum << endl;
	sort(A + 1, A + tot1 + 1);
	sort(B + 1, B + tot2 + 1);
	for(int i = 1; i <= tot1; i++) {
		if(i == 1 || A[i] != A[i - 1]) {
			aa[++cnt1] = A[i];
		}
	}
	for(int i = 1; i <= tot2; i++) {
		if(i == 1 || B[i] != B[i - 1]) {
			bb[++cnt2] = B[i];
		}
	}
	for(int i = 1; i <= cnt1; i++) {
		int now = aa[i];
		sum = (sum - find_hang(now) % mod + mod) % mod;
	}
	for(int i = 1; i <= cnt2; i++) {
		int now = bb[i];
		sum = (sum - find_lie(now) % mod + mod) % mod;
	}
	for(int i = 1; i <= cnt1; i++) {
	    for(int j = 1; j <= cnt2; j++) {
	        sum = (sum + find(aa[i], bb[j])) % mod;
		}
	}
	//cout << sum << endl;
	for(int i = 1; i <= cnt1; i++) {
		sum = (sum + find_hang(aa[i]) * a[aa[i]] % mod) % mod;
		for(int j = 1; j <= cnt2; j++) {
			sum = (sum - find(aa[i], bb[j]) % mod * a[aa[i]] % mod + mod) % mod;
		}
    }
	for(int i = 1; i <= cnt2; i++) {
		sum = (sum + find_lie(bb[i])  * b[bb[i]] % mod) % mod;
		for(int j = 1; j <= cnt1; j++) {
			sum = (sum - find(aa[j], bb[i]) % mod * b[bb[i]] % mod + mod) % mod;
		}
	}
	for(int i = 1; i <= cnt1; i++) {
	    for(int j = 1; j <= cnt2; j++) {
	        sum = (sum + find(aa[i], bb[j]) * a[aa[i]] % mod * b[bb[j]] % mod) % mod;
		}
	}
	printf("%lld", sum);
	return 0;
}








