#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MOD = 1e7 + 7;

struct _hash {
	int n, now, hd[MOD], nxt[MOD], tim[MOD];
	ll v[MOD];
	void init() { n = 0; now++; }
	bool insert(ll val) {
		ll s = val % MOD;
		if (tim[s] != now) { tim[s] = now; hd[now] = 0; }
		for (int i = hd[s]; i; i = nxt[i]) if(v[i] == val) return 0;
		nxt[n + 1] = hd[s];
		v[n + 1] = val;
		hd[s] = ++n;
		return true;
	}
} mp;

vector <tuple <int, int, int> > tp[20];

const double eps = 1e-6;
int n;
double _x, _y;

string restore(int len, tuple <int, int, int> _seq) {
	if (!len) return "";
	for (auto seq : tp[len - 1]) {
		auto [m, x, y] = seq;
		int mN, xN, yN;
		mN = m + 2 * len - 1;
		xN = x + m + len * (2 * len - 1);
		yN = y + 3 * m + 3 * len - 2;
		auto tpl = dk(mN, xN, yN);
		if (tpl == _seq) return "(" + restore(len - 1, seq) + ")";
	}
	rep (j, 1, len - 1) {
		for (auto seqA : tp[j]) {
			for (auto seqB : tp[len - j]) {
				auto [mL, xL, yL] = seqA;
				auto [mR, xR, yR] = seqB;
				int mN, xN, yN;
				mN = mL + mR;
				xN = xL + xR + 2 * j * mR;
				yN = yL + yR;
				auto tpl = dk(mN, xN, yN);
				if (tpl == _seq) return restore(j, seqA) + restore(len - j, seqB);
			}
		}
	}
	return "";
}

ll compress(tuple <ll, ll, ll> v) {
	auto [x, y, z] = v;
	return (x << 40) + (y << 20) + z;
}

signed main() {
	cin >> n >> _x >> _y;
	tp[0].push_back(dk(0, 0, 0));
	rep (i, 1, n / 2) {
		mp.init();
		rep (j, 1, i - 1) {
			for (auto seqA : tp[j]) {
				for (auto seqB : tp[i - j]) {
					auto [mL, xL, yL] = seqA;
					auto [mR, xR, yR] = seqB;
					int mN, xN, yN;
					mN = mL + mR;
					xN = xL + xR + 2 * j * mR;
					yN = yL + yR;
					auto tpl = compress(dk(mN, xN, yN));
					if (mp.insert(tpl)) tp[i].push_back(dk(mN, xN, yN));
				}
			}
		}
		for (auto seq : tp[i - 1]) {
			auto [m, x, y] = seq;
			int mN, xN, yN;
			mN = m + 2 * i - 1;
			xN = x + m + i * (2 * i - 1);
			yN = y + 3 * m + 3 * i - 2;
			auto tpl = compress(dk(mN, xN, yN));
			if (mp.insert(tpl)) tp[i].push_back(dk(mN, xN, yN));
		}
	}
	for (auto seq : tp[n / 2]) {
		auto [mB, xB, yB] = seq;
		double xN = 1.0 * xB / mB;
		double yN = 1.0 / 3.0 * yB / mB;
		if (fabs(xN - _x) <= eps && fabs(yN - _y) <= eps) {
			cout << restore(n / 2, seq) << endl;
			return 0;
		}
	}
	return 0;
}
