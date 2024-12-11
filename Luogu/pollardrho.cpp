#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define _rep(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long ll;
typedef __int128 lll;

#define int lll
#define PRIMEN 17

int prime[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 61, 1215, 34862, 574237825, 97};

mt19937_64 rnd(time(0));

__int128 myabs(__int128 a) {
	return a >= 0 ? a : -a;
}

void read(){}
template <typename T,typename... Types>
void read(T& first, Types&... args) {
	T x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c^'0'), c = getchar();
	first = x * f;
	read(args...);
}

template <typename T>
void _print(T x) {if (x < 0) x = (~x + 1), putchar('-');if (x > 9) _print(x / 10);putchar(x % 10 + '0');}

int mul(int a, int b, int mod) {
	int res = 0;
	while (b) {
		if (b & 1) res = (res + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return res % mod;
}

lll qpow(ll a, ll b, ll mod) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (lll) res * a % mod;
		a = (lll) a * a % mod;
		b >>= 1;
	}
	return res % mod;
}

bool Miller_Rabin(int n, int p) {
	if (n == 1) return false;
	ll d = n - 1, r = 0;
	while(!(d & 1)) d >>= 1, r++;
	int z = qpow(p, d, n);
	if (z == 1) return true;
	rep (i, 1, r) {
	    if(z == n - 1) return true;
	    z = mul(z, z, n);
	}
	return false;
}

bool isPrime(lll n) {
	//if (n == 2152302898747ll || n < 2) return false;
	rep (i, 0, PRIMEN - 1) {
		if (n == prime[i]) return true;
		if (n % prime[i] == 0) return false;
		if (!Miller_Rabin(n, prime[i])) return false;
	}
	return true;
}

int f(int x, int c, int mod) {
	return ((lll) x * x % mod + c) % mod;
}

int PollardRho(int x) {
	//cout << "PR" << endl;
	int s = 0, t = 0, c = rnd() % (x - 1) + 1;
	int target = 1, val = 1, cnt = 0;
	for (target = 1; ; target <<= 1, s = t, val = 1) {
		rep(i, 1, target) {
			cnt++;
			t = f(t, c, x);
			val = (lll) val * myabs(t - s) % x;
			if (cnt % 127 == 0) {
				int gcd = __gcd(val, x);
				if (gcd > 1) return gcd;
			}
		}
		int gcd = __gcd(val, x);
		if (gcd > 1) return gcd;
	}
}

int ans, T, n;

void solve(int x) {
	//cout << "solve" << endl;
	if (x <= ans || x < 2) return;
	if (isPrime(x)) {
		ans = ans > x ? ans : x;
		return;
	}
	int p = x;
	while (p >= x) p = PollardRho(x);
	while ((x % p) == 0 ) x /= p;
	solve(x), solve(p);
}

signed main() {
	// cout << isPrime(9000000000000000013ll) << endl;
	// read(T);
	// while (T --> 0) {
	rep (n, 9000000000000000000ll, 9000000000000000100ll) {
		// read(n);
		ans = 0;
		if (isPrime(n)) {
			cout << "Prime: ";
			_print(n);
			puts("");
			continue;
		}
		solve(n);
		if (ans == n) cout << "Prime" << endl;
		else _print(ans), putchar('\n');
	}
	return 0;
}
