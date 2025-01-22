#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r) {
	uniform_int_distribution <int> dis(l, r);
	return dis(rnd);
}

vector <vector <pii> > resr;

signed main() {
	freopen("data.in", "w", stdout);
	int n = 500, m = 1;
	cout << n << " " << m << endl;
	rep (i, 1, n) {
		int cnt = rand(1, m);
		vector <pii> res;
		rep (j, 1, cnt) {
			// if (rand(0, 10)) res.emplace_back(rand(0, 299), rand(1, 100));
			/*else */res.emplace_back(-1, rand(1, 100));
		}
		int totpen = 0, totac = 0;
		for (auto [x, y] : res) {
			if (x == -1) continue;
			totac++;
			totpen += (y - 1) * 20 + x;
		}
		cout << totac << totpen;
		for (auto [x, y] : res) {
			if (x == -1) cout << y << (y == 1 ? "try" : "tries");
			else cout << x << y << (y == 1 ? "try": "tries");
		}
		cout << endl;
		resr.push_back(res);
	}
	freopen("data.ans", "w", stdout);
	for (auto res : resr) {
		int totpen = 0, totac = 0;
		for (auto [x, y] : res) {
			if (x == -1) continue;
			totac++;
			totpen += (y - 1) * 20 + x;
		}
		cout << totac << " " << totpen << " ";
		int cnt = 0;
		for (auto [x, y] : res) {
			if (x == -1) cout << y << " " << (y == 1 ? "try" : "tries");
			else cout << x << " " << y << " " << (y == 1 ? "try": "tries");
			cnt++;
			if (cnt < (int) res.size()) cout << " ";
			else cout << endl;
		}
	}
	return 0;
}
