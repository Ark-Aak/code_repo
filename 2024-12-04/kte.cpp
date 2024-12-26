#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define int ll

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

int Q, sum;
set <int> s;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("kte.in", "r", stdin);
	freopen("kte.out", "w", stdout);
#endif
#endif
	Q = read();
	while (Q --> 0) {
		int x = read();
		if (s.find(x) == s.end()) s.insert(x), sum += x;
		else s.erase(x), sum -= x;
		if (s.size() <= 1000) {
			auto lp = s.begin();
			auto rp = s.rbegin();
			int RR = 0;
			int ans = 0;
			int pre = 0, suf = 0;
			do {
				int valL = *lp;
				int valR = *rp;
				pre += valL, suf += valR;
				if (pre >= suf) break;
				// L ~ R - 1
				if (pre >= RR) {
					ans += suf - pre;
					RR = suf;
				}
				else {
					ans += suf - RR;
					RR = suf;
				}
				lp++, rp++;
			} while (pre < suf);
			print(ans), puts("");
		}
		else {
			print(sum - 2 * (*s.begin())), puts("");
		}
	}
	return 0;
}
