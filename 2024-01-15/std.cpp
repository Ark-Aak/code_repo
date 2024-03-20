#include <bits/stdc++.h>
const int N = 1000005, mod = 998244353;
typedef long long ll;
ll ksm(ll a, ll b = mod - 2)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return res;
}
int fac[N], f[N], g[N];
int solve(int n, int m, int k)
{
	f[0] = 1;
	for (int j = 1; j <= k; ++j)
		f[j] = 1LL * f[j - 1] * (m + j) % mod;
	g[k] = ksm(f[k]);
	for (int j = k; j >= 1; --j)
		g[j - 1] = 1LL * g[j] * (m + j) % mod;
	ll A = 1, B = 1;
	for (int j = 1; j <= k; ++j)
	{
		if (j <= n)
			A = A * fac[j - 1] % mod;
		else
			A = A * fac[j - n - 1] % mod * f[j - 1] % mod * g[j - n - 1] % mod;
	}
	for (int j = 1; j <= k; ++j)
		B = B * fac[j - 1] % mod;
	std::cout << "debug:" << A << " " << B << std::endl;
	return A * ksm(B) % mod;
}
void MAIN()
{
	int n, m, k;
	std::cin >> n >> m >> k;
	int p = n % m;
	if (p <= m - k)
		printf("%d\n", solve(k, n / m, m - p));
	else
		printf("%d\n", solve(k - (m - p), n / m + 1, p));
}
int main()
{
	fac[0] = 1;
	for (int i = 1; i < N; ++i)
		fac[i] = 1LL * fac[i - 1] * i % mod;
	int _;
	std::cin >> _;
	while (_--)
		MAIN();
	return 0;
}
