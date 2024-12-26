#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>
#include <bits/extc++.h>

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

__gnu_pbds::cc_hash_table <int, set <tuple <int, int> > > s;
const int MAXN = 5e5 + 5;
int n, k, a[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("checkln.in", "r", stdin);
	freopen("checkln.out", "w", stdout);
#endif
#endif
	n = read(), k = read();
	rep (i, 1, n) a[i] = read();
	int ans = 0;
	rep (i, 1, n) {
		int r = a[i] % k;
		int v = a[i] / k;
		if (s[r].size() == 0) {
			ans++;
			s[r].insert(dk(v, v));
			// continue;
		}
		else {
			auto nxt = s[r].lower_bound(dk(v, 0));
			if (nxt == s[r].end()) {
				auto pre = prev(nxt);
				tuple <int, int> val = *pre;
				int L = get<0>(val), R = get<1>(val);
				if (v == R + 1) {
					s[r].erase(pre);
					if (((R - L + 1) & 1) == 0) ans++;
					s[r].insert(dk(L, R + 1));
				}
				else s[r].insert(dk(v, v)), ans++;
			}
			else if (nxt == s[r].begin()) {
				tuple <int, int> val = *nxt;
				int L = get<0>(val), R = get<1>(val);
				if (v == L - 1) {
					s[r].erase(nxt);
					if (((R - L + 1) & 1) == 0) ans++;
					s[r].insert(dk(L - 1, R));
				}
				else s[r].insert(dk(v, v)), ans++;
			}
			else {
				auto pre = prev(nxt);
				tuple <int, int> valpre = *pre;
				tuple <int, int> valnxt = *nxt;
				int L1 = get<0>(valpre), R1 = get<1>(valpre);
				int L2 = get<0>(valnxt), R2 = get<1>(valnxt);
				if (v == R1 + 1 && v == L2 - 1) {
					s[r].erase(pre), s[r].erase(nxt);
					ans -= (R1 - L1 + 2) / 2;
					ans -= (R2 - L2 + 2) / 2;
					ans += (R2 - L1 + 2) / 2;
					s[r].insert(dk(L1, R2));
				}
				else if (v == R1 + 1) {
					s[r].erase(pre);
					if (((R1 - L1 + 1) & 1) == 0) ans++;
					s[r].insert(dk(L1, R1 + 1));
				}
				else if (v == L2 - 1) {
					s[r].erase(nxt);
					if (((R2 - L2 + 1) & 1) == 0) ans++;
					s[r].insert(dk(L2 - 1, R2));
				}
				else {
					ans++;
					s[r].insert(dk(v, v));
				}
			}
		}
		print(ans), putchar(32);
	}
	puts("");
	return 0;
}
