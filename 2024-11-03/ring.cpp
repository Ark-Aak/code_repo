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

bool _stmer;

const int MAXN = 1.5e5 + 10;
int n, m, q;
int c[MAXN], a[MAXN];
vector <int> cycles[MAXN], id[MAXN];
vector <int> pre[MAXN];
int tag[MAXN];
int cl[MAXN], cr[MAXN];
bool flg = 1;

bool _edmer;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("ring.in", "r", stdin);
	freopen("ring.out", "w", stdout);
#endif
#endif
	cerr << ((&_stmer) - (&_edmer)) / 1024.0 / 1024.0 << "MiB" << endl;
	n = read(), m = read(), q = read();
	rep (i, 1, n) c[i] = read(), flg &= c[i - 1] <= c[i];
	rep (i, 1, n) a[i] = read();
	rep (i, 1, n) cycles[c[i]].push_back(a[i]);
	rep (i, 1, n) id[c[i]].push_back(i);
	rep (i, 1, n) {
		if (cl[c[i]] == 0) cl[c[i]] = i;
		cr[c[i]] = i;
	}
	rep (i, 1, m) {
		pre[i].resize(cycles[i].size() + 1);
		rep (j, 1, cycles[i].size()) pre[i][j] = pre[i][j - 1] + cycles[i][j - 1];
	}
	if (m == 1) {
		int offset = 0;
		while (q --> 0) {
			int op = read();
			if (op == 1) {
				int l = read(), r = read();
				l -= offset, r -= offset;
				if (l < 1 && r < 1) {
					l += n, r += n;
					print(pre[1][r] - pre[1][l - 1]);
					puts("");
				}
				else if (l < 1) {
					l += n;
					print(pre[1][r] + pre[1][n] - pre[1][l - 1]);
					puts("");
				}
				else {
					print(pre[1][r] - pre[1][l - 1]);
					puts("");
				}
			}
			else {
				read();
				offset++;
				offset %= n;
			}
		}
		return 0;
	}
	if (flg) {
		while (q --> 0) {
			int op = read();
			if (op == 1) {
				int l = read(), r = read();
				int idl = c[l], idr = c[r];
				int sum = 0;
				rep (i, idl + 1, idr - 1) sum += pre[i].back();
				if (idl == idr) {
					int kl = l - cl[idl] + 1, kr = r - cl[idl] + 1;
					kl -= tag[idl], kr -= tag[idl];
					if (kl < 1 && kr < 1) {
						kl += cycles[idl].size(), kr += cycles[idl].size();
						sum += pre[idl][kr] - pre[idl][kl - 1];
					}
					else if (kl < 1) {
						kl += cycles[idl].size();
						sum += pre[idl][kr] + pre[idl].back() - pre[idl][kl - 1];
					}
					else {
						sum += pre[idl][kr] - pre[idl][kl - 1];
					}
				}
				else {
					int kl1 = l - cl[idl] + 1, kr1 = cr[idl] - cl[idl] + 1;
					kl1 -= tag[idl], kr1 -= tag[idl];
					if (kl1 < 1 && kr1 < 1) {
						kl1 += cycles[idl].size(), kr1 += cycles[idl].size();
						sum += pre[idl][kr1] - pre[idl][kl1 - 1];
					}
					else if (kl1 < 1) {
						kl1 += cycles[idl].size();
						sum += pre[idl][kr1] + pre[idl].back() - pre[idl][kl1 - 1];
					}
					else {
						sum += pre[idl][kr1] - pre[idl][kl1 - 1];
					}
					int kl2 = 1, kr2 = r - cl[idr] + 1;
					kl2 -= tag[idr], kr2 -= tag[idr];
					if (kl2 < 1 && kr2 < 1) {
						kl2 += cycles[idr].size(), kr2 += cycles[idr].size();
						sum += pre[idr][kr2] - pre[idr][kl2 - 1];
					}
					else if (kl2 < 1) {
						kl2 += cycles[idr].size();
						sum += pre[idr][kr2] + pre[idr].back() - pre[idr][kl2 - 1];
					}
					else {
						sum += pre[idr][kr2] - pre[idr][kl2 - 1];
					}
				}
				print(sum), puts("");
			}
			else {
				int x = read();
				tag[x]++;
				tag[x] %= cycles[x].size();
			}
		}
		return 0;
	}
	while (q --> 0) {
		int op = read();
		if (op == 1) {
			int l = read(), r = read();
			rep (i, 1, m) {
				rep (j, 1, cycles[i].size()) {
					int x = id[i][j - 1];
					a[x] = cycles[i][(j - 1 - tag[i] + (int) cycles[i].size()) % cycles[i].size()];
				}
				tag[i] = 0;
			}
			int sum = 0;
			rep (i, l, r) sum += a[i];
			print(sum), puts("");
		}
		else {
			int x = read();
			tag[x]++;
			tag[x] %= cycles[x].size();
		}
	}
	return 0;
}
