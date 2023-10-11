#include<bits/stdc++.h>
#define N 4010
#define int long long
#define mod 998244353 
using namespace std;
int n, ans;
int a[N][N];
int Pow(int a, int n) {
	if(n == 0) return 1;
	if(n == 1) return a;
	int x = Pow(a, n / 2);
	if(n % 2 == 0) return x * x % mod;
	return x * x % mod * a % mod;
}
int inv(int x) {
	return Pow(x, mod - 2);
}
int C(int n, int m) {
	int A = 1, B = 1, C = 1;
	for(int i = 1; i <= n; i++) A = A * i % mod;
	for(int i = 1; i <= m; i++) B = B * i % mod;
	for(int i = 1; i <= (n - m); i++) C = C * i % mod;
	return A * inv(B) % mod * inv(C) % mod;
}
signed main() {
	freopen("random.in", "r", stdin);
	freopen("random.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++) a[i][j] = -1;
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++) {
		char c;
		cin >> c;
		if(c == '1') {
			a[i][j] = 1;
			a[j][i] = 0;
		}
	}
	if(n <= 500)
	{
	int sum = 0;
	for(int i = 1; i <= n; i++)
	for(int j = i + 1; j <= n; j++) if(a[i][j] == -1) sum++;
	//cout << sum << endl;
	for(int i = 1; i <= n; i++)
	for(int j = i + 1; j <= n; j++)
	for(int k = j + 1; k <= n; k++) {
		if(a[i][j] != 0 && a[j][k] != 0 && a[k][i] != 0) {
			int num = 1, p = 0;
			if(a[i][j] == -1) p++;
			if(a[j][k] == -1) p++;
			if(a[k][i] == -1) p++;
			//if(p == 3) num = 2;
			//else num = 1;
			num *= Pow(2, sum - p);
			ans = (ans + num) % mod;
			//cout << num << endl;
		}
		if(a[j][i] != 0 && a[k][j] != 0 && a[i][k] != 0) {
			int num = 1, p = 0;
			if(a[j][i] == -1) p++;
			if(a[k][j] == -1) p++;
			if(a[i][k] == -1) p++;
			//if(p == 3) num = 2;
			//else num = 1;
			num *= Pow(2, sum - p);
			ans = (ans + num) % mod;
			//cout << num << endl;
		}
	}
	cout << ans;
	return 0;
	}
	//cout << C(4, 3) << endl;
	int s = n * (n - 1) / 2;
	cout << C(n, 3) * Pow(2, s - 3) * 2 % mod;
	return 0;
}
/*
4
0000
0000
0000
0000
*/
