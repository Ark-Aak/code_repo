#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define _rep(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long ll;

#define int ll
#define PRIMEN 13

int prime[PRIMEN] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 61};

int mul(int a, int b, int mod) {
	int res = 0;
	while (b) {
		if (b & 1) res = (res + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return res % mod;
}

int qpow(int a, int b, int mod) {
	int res = 1;
	while (b) {
		if (b & 1) res = mul(res, a, mod);
		a = mul(a, a, mod);
		b >>= 1;
	}
	return res % mod;
}

bool Miller_Rabin(int n, int a) {
	if (n == 1) return false;
	int k = n - 1;
	while (k) {
		int cur = qpow(a, k, n);
		if (cur != 1 && cur != n - 1) return false;
		if ((k & 1) == 1 || cur == n - 1) return true;
		k >>= 1;
	}
	return true;
}

bool isPrime(int n) {
	rep (i, 0, PRIMEN - 1) {
		if (n == prime[i]) return true;
		//cout << n << " " << prime[i] << endl;
		if (n % prime[i] == 0) return false;
		//cout << n << " " << prime[i] << endl;
		if (!Miller_Rabin(n, prime[i])) return false;
		//cout << n << " " << prime[i] << endl;
	}
	return true;
}

signed main() {
	const int N = 1e7;
	rep (i, 2, N) {
		int a = i * i;
		int b = (i - 1) * (i - 1);
		int qc = a - b;
		if (isPrime(qc)) {
			b = qc;
			goto print;
		}
		do {
			b = b - qc;
			if (b < 0) return 0;
		//	printf("value = %lld, pos = %lld\n", b, i);
		} while (!isPrime(b));
print:
		//printf("%lld, %lld\n", i, b);
		printf("%lld checked\n", i);
		//printf("\n");
		continue;
	}
	return 0;
}
