#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
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

int a, b, c;
int ch[70];
int A[70], B[70], suma, sumb;

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

signed main() {
	cin >> a >> b >> c;
	int tc = c, tta = a, ttb = b;
	/* int pp = __builtin_popcountll(c); */
	int cnt = 0;
	while (c) ch[++cnt] = c & 1, c >>= 1;
	rep (i, 1, cnt) {
		if (ch[i]) A[i] = 1, suma++;
	}
	bool ok = 0;
	rep (i, 1, cnt + 1) {
		if (a - suma == b - sumb) {
			/* cout << a - suma << " " << b - sumb << endl; */
			ok = 1;
			if (a - suma < 0) {
				ok = 0;
			}
			if (a - suma > 0) {
				rep (i, 1, 60) {
					if (!A[i] && !B[i]) {
						A[i] = B[i] = 1;
						a--;
					}
					if (a - suma == 0) break;
				}
				if (a - suma > 0) ok = 0;
			}
			if (ok) break;
		}
		if (cnt > 60) break;
		if (ch[i]) {
			swap(A[i], B[i]);
			suma--;
			sumb++;
		}
	}
	if (!ok) puts("-1");
	else {
		int ta = 0;
		/* cout << endl; */
		rep (i, 1, 60) ta += qpow(2, i - 1) * A[i];
		int tb = 0;
		rep (i, 1, 60) tb += qpow(2, i - 1) * B[i];
		/* cout << __builtin_popcountll(ta) << " " << __builtin_popcountll(tb) << endl; */
		assert((ta ^ tb) == tc);
		/* cout << tta << endl; */
		assert(__builtin_popcountll(ta) == tta);
		assert(__builtin_popcountll(tb) == ttb);
		cout << ta << " " << tb << endl;
	}
	return 0;
}
