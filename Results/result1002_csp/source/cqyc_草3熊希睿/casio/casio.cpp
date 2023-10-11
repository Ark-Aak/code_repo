#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

const int MAXN = 5e7 + 5;
bitset <MAXN> vis;
vector <int> pri;
int T, p;
mt19937_64 rnd(time(0));

int prime[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 61, 1215, 34862, 574237825};

#define PRIMEN 13

int qpow(int a, int b, int p) {
	int res = 1;
	while (b) {
		if (b & 1) res = (res * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return res;
}

bool Miller_Rabin(int n, int p) {
	if (n == 1) return false;
	ll d = n - 1, r = 0;
	while (!(d & 1)) d >>= 1, r++;
	int z = qpow(p, d, n);
	if(z == 1) return true;
	rep (i, 1, r){
	    if(z == n - 1) return true;
		z = (z * z) % n;
	}
	return false;
}

bool isPrime(ll n) {
	rep (i, 0, PRIMEN - 1) {
		if (n == prime[i]) return true;
		if (n % prime[i] == 0) return false;
		if (!Miller_Rabin(n, prime[i])) return false;
	}
	return true;
}

int f(int x, int c, int mod) {
	return ((ll) x * x % mod + c) % mod;
}

int PollardRho(int x) {
	int s = 0, t = 0, c = rnd() % (x - 1) + 1;
	int target = 1, val = 1, cnt = 0;
	for (target = 1; ; target <<= 1, s = t, val = 1) {
		rep(i, 1, target) {
			cnt++;
			t = f(t, c, x);
			val = (ll) val * abs(t - s) % x;
			if (cnt % 127 == 0) {
				int gcd = __gcd(val, x);
				if (gcd > 1) return gcd;
			}
		}
		int gcd = __gcd(val, x);
		if (gcd > 1) return gcd;
	}
}

int ans = 1e9;

void solve(int x) {
	if (x < 2) return;
	if (isPrime(x)) {
		ans = min(ans, x);
		return;
	}
	int p = x;
	while (p >= x || p < 2) p = PollardRho(x);
	while ((x % p) == 0) x /= p;
	solve(x), solve(p);
}

void sieve(int n) {
	vis[1] = 1;
	rep (i, 2, n) {
		if (!vis[i]) {
			pri.emplace_back(i);
			for (int x = 2 * i; x <= n; x += i) vis[x] = 1;
		}
	}
}

int status[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("casio.in", "r", stdin);
	freopen("casio.out", "w", stdout);
#endif
#endif
	sieve(3e7 + 1e3);
	read(T); read(p);
	while (T --> 0) {
		int n;
		read(n);
		int tans = *(lower_bound(pri.begin(), pri.end(), n));
		rep (i, n, tans - 1) {
			if (status[i] == 1) {
				tans = i; break;
			}
			else if (status[i] == 2) continue;
			//ans = 1e9;
			//solve(i);
			//if (ans != 1e9 && ans > p) {
			//	tans = i;
			//	status[i] = 1;
			//	break;
			//}
			//else status[i] = 2;
			for (auto x : pri) {
				if (x > p) {
					status[i] = 1;
					tans = i; break;
				}
				if (x > i) {
					status[i] = 1;
					tans = i; break;
				}
				if (i % x == 0) {
					status[i] = 2;
					break;
				}
			}
		}
		print(tans), putchar(10);
	}
	//7840553
	return 0; 
}
