#include <bits/stdc++.h>
constexpr int P = 1e9 + 7;
struct mint {
  public:
  	mint(int x = 0): v(x % P) { v += ((v >> 31) & P); }
  	int val() const { return v; }
  	
  	mint &operator += (const mint &rhs) { v += rhs.v - P; v += ((v >> 31) & P); return *this; }
  	mint &operator -= (const mint &rhs) { v -= rhs.v; v += ((v >> 31) & P); return *this; }
  	mint &operator *= (const mint &rhs) { v = (unsigned long long)(v) * rhs.v % P; return *this; }
  	mint &operator /= (const mint &rhs) { return *this *= rhs.inv(); }
  	
	mint operator - () const { return mint(-v); }

  	bool operator == (const mint &rhs) const { return v == rhs.v; }
    bool operator != (const mint &rhs) const { return v != rhs.v; } 
  	
  	friend mint operator + (mint lhs, const mint &rhs) { return lhs += rhs; }
  	friend mint operator - (mint lhs, const mint &rhs) { return lhs -= rhs; }
  	friend mint operator * (mint lhs, const mint &rhs) { return lhs *= rhs; }
  	friend mint operator / (mint lhs, const mint &rhs) { return lhs /= rhs; }

  	friend std::istream &operator >> (std::istream &is, mint &m) { return is >> m.v; }
	friend std::ostream &operator << (std::ostream &os, const mint &m) { return os << m.v; }
  	
  	mint inv() const;
  	
  	mint pow(int n) const {
  		mint x = *this, r = 1;
  		for (; n; n >>= 1, x *= x) {
  			if (n & 1) {
  				r *= x;
			}
		}
		return r;
	}
  private:
  	int v;
};

struct _simple {
  public:
	friend struct mint;
	_simple() { init(1); }
	
	mint fac(int n) const { return _fac[n]; }
	mint ifac(int n) const { return _ifac[n]; }
	mint inv(int n)	const { return _inv[n]; }
	mint binom(int n, int m) const {
		if (m < 0 || m > n) {
			return 0;
		} else {
			return _fac[n] * _ifac[m] * _ifac[n - m];
		}
	}
	
	void init(int n) {
		_n = n;
		_fac.resize(n + 1), _ifac.resize(n + 1), _inv.resize(n + 1);
		
		_fac[0] = 1;
		for (int i = 1; i <= n; i++) {
			_fac[i] = _fac[i - 1] * i;
		}
		
		_ifac[n] = _fac[n].pow(P - 2);
		for (int i = n; i >= 1; i--) {
			_ifac[i - 1] = _ifac[i] * i;
		}
		
		for (int i = 1; i <= n; i++) {
			_inv[i] = _ifac[i] * _fac[i - 1];
		}
	}
  private:
  	int _n;
  	std::vector<mint> _fac, _ifac, _inv;
} simple;

mint mint::inv() const {
	if (v <= simple._n) {
		return simple.inv(v);
	} else {
		return pow(P - 2);
	}
}

void solve() {
	using ll = long long;

	int n;
	std::cin >> n;
	simple.init(n);

	std::vector<ll> p(n);
	for (ll &x : p) {
		std::cin >> x;
	}

	ll M = (std::accumulate(p.begin(), p.end(), ll(0)) + n) / 2;

	std::vector<std::pair<ll, int>> L, R;
	L.reserve(1 << (n / 2));
	R.reserve(1 << (n - n / 2));
	L.emplace_back(0, 1);
	R.emplace_back(0, 1);

	auto ins = [&](auto &V, ll x) {
		int n = V.size();
		for (int i = 0; i < n; i++) {
			auto [v, c] = V[i];
			V.emplace_back(v + x, -c);
		}
		std::inplace_merge(V.begin(), V.begin() + n, V.end());
	};

	for (int i = 0; i < n / 2; i++) {
		ins(L, p[i]);
	}
	for (int i = n / 2; i < n; i++) {
		ins(R, p[i]);
	}

	std::reverse(L.begin(), L.end());

	mint ans = 0;
	std::vector<mint> sum(n);
	for (int i = 0, j = 0; i < L.size(); i++) {
		while (j < R.size() && L[i].first + R[j].first <= M - 1) {
			mint v = (-R[j].first) % P, c = R[j].second;
			for (int k = 0; k < n; k++) {
				sum[k] += c;
				c *= (v - k) / (k + 1);
			}
			j++;
		}

		mint v = (M - 1 - L[i].first) % P, c = L[i].second;
		for (int k = 0; k < n; k++) {
			ans += sum[n - 1 - k] * c;
			c *= (v - k) / (k + 1);
		}
	}
	std::cout << ans << "\n";
}

int main() {
	freopen("separate.in", "r", stdin);
	freopen("separate.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();
	
	return 0;
}