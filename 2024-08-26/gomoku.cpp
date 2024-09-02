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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int mp[505][505];
int n, m, k;
vector <pii> z, o;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
    freopen("gomoku.in", "r", stdin);
    freopen("gomoku.out", "w", stdout);
#endif
#endif
    n = read(), m = read(), k = read();
    if (k == 1) return puts("-1"), 0;
    if (k == 2) {
        if (n > 1 && m > 1) return puts("-1"), 0;
        else {
            if (n == 1) {
                rep (i, 1, m) {
                    cout << "1 " << i << endl;
                }
            }
            else {
                rep (i, 1, n) {
                    cout << i << " 1" << endl;
                }
            }
        }
        return 0;
    }
    rep (i, 1, n) {
        int st = i & 1;
        rep (j, 1, m) {
            if (j % 4 < 2) mp[i][j] = st;
            else mp[i][j] = !st;
        }
    }
    rep (i, 1, n) {
        rep (j, 1, m) {
            if (mp[i][j]) o.push_back(dl(i, j));
            else z.push_back(dl(i, j));
        }
    }
    int p0 = 0, p1 = 0;
    if (o.size() & 1) o.swap(z);
    rep (i, 1, n * m) {
        if (p0 <= p1) cout << z[p0].ec << " " << z[p0].fb << endl, p0++;
        else cout << o[p1].ec << " " << o[p1].fb << endl, p1++;
    }
	return 0;
}
