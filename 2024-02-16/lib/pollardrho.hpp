#ifndef __LIB_POLLARDRHO_HPP
#define __LIB_POLLARDRHO_HPP

#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

#ifndef _rep
#define _rep(i,a,b) for(lll i=(a);i>=(b);i--)
#endif
#ifndef rep
#define rep(i,a,b) for(lll i=(a);i<=(b);i++)
#endif

typedef long long ll;
typedef __int128 lll;

#define PRIMEN 16

namespace pollardrho {

lll prime[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 61, 1215, 34862, 574237825};

mt19937_64 rnd(time(0));

__int128 myabs(__int128 a) {
	return a >= 0 ? a : -a;
}

lll mul(lll a, lll b, lll p) {
	a %= p, b %= p;
	return (a * b - (lll) ((__float128) a / p * b) * p + p) % p;
}

lll qpow(lll a, lll b, lll mod) {
	a %= mod;
	lll res = 1;
	while (b) {
		if (b & 1) res = (lll) mul(res, a, mod);
		a = (lll) mul(a, a, mod);
		b >>= 1;
	}
	return res % mod;
}

bool Miller_Rabin(lll n, lll p) {
	if (n == 1) return false;
	lll d = n - 1, r = 0;
	while (!(d & 1)) d >>= 1, r++;
	lll z = qpow(p, d, n);
	if (z == 1) return true;
	rep (i, 1, r) {
	    if (z == n - 1) return true;
	    z = mul(z, z, n); 
	}
	return false;
}

bool isPrime(lll n) {
	rep (i, 0, PRIMEN - 1) {
		if (n == prime[i]) return true;
		if (n % prime[i] == 0) return false;
		if (!Miller_Rabin(n, prime[i])) return false;
	}
	return true;
}

lll f(lll x, lll c, lll mod) {
	return ((lll) x * x % mod + c) % mod;
}

lll pr(lll x) {
	lll s = 0, t = 0, c = rnd() % (x - 1) + 1;
	lll target = 1, val = 1, cnt = 0;
	for (target = 1; ; target <<= 1, s = t, val = 1) {
		rep(i, 1, target) {
			cnt++;
			t = f(t, c, x);
			val = (lll) val * myabs(t - s) % x;
			if (cnt % 127 == 0) {
				lll gcd = __gcd(val, x);
				if (gcd > 1) return gcd;
			}
		}
		lll gcd = __gcd(val, x);
		if (gcd > 1) return gcd;
	}
}

vector <lll> res;

void solve(lll x) {
	if (x < 2) return;
	if (isPrime(x)) {
		res.push_back(x);
		return;
	}
	lll p = x;
	while (p >= x) p = pr(x);
	while ((x % p) == 0) x /= p;
	solve(x), solve(p);
}

} // namespace pollardrho

vector <lll> PollardRho(lll x) {
	pollardrho::res.clear();
	pollardrho::solve(x);
	sort(pollardrho::res.begin(), pollardrho::res.end());
	pollardrho::res.erase(unique(pollardrho::res.begin(), pollardrho::res.end()), pollardrho::res.end());
	return pollardrho::res;
}

vector <pair <lll, lll> > PollardRhoSplit(lll x) {
	vector <lll> factors = PollardRho(x);
	vector <pair <lll, lll> > res;
	for (auto i : factors) {
		lll cnt = 0;
		while ((x % i) == 0) x /= i, cnt++;
		res.push_back(make_pair(i, cnt));
	}
	return res;
}

#undef lll
#undef PRIMEN
#endif