#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep (i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define ec first
#define fb second
#define de(x) cerr << #x << " = " << (x) << endl

#define int ll

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

bool flg;
int len;

int read() {
	int x = 0, w = 1;
	len = 0;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') w = -1, assert(0);
		ch = getchar();
	}
	int len = 0;
	while (isdigit(ch)) {
		x = x * 10 + (ch ^ 48);
		ch = getchar();
		len++;
	}
	if (flg) ::len = len, flg = 0;
	if (ch == '.') flg = 1;
	return x * w;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}

const int MAXN = 2e5 + 5;
ll a[MAXN];
ll n;
ll cnt[50][50];

signed main() {
#ifndef LOCAL
	freopen("integer.in", "r", stdin);
	frepoen("integer.out", "w", stdout);
#endif
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
	cin >> n;
	rep (i, 1, n) {
	//	a[i] = read();
	//	de(a[i]);
	//	if (flg) {
	//		ll tp = 0;
	//		tp = read();
	//		de(tp);
	//		a[i] *= pow(10ll, len);
	//		a[i] += tp;
	//		a[i] *= pow(10ll, 9 - len);
	//	}
	//	else a[i] *= 1000000000ll;
		
		double val;
		cin >> val;
		stringstream ss;
		ss << fixed << setprecision(9) << val;
		//cout << ss.str() << endl;
		for (auto ch : ss.str()) {
			if (!isdigit(ch)) continue;
			a[i] *= 10;
			a[i] += ch ^ 48;
		}
	}
	ll ans = 0;
	rep (i, 1, n) {
		int cnt2 = 0, cnt5 = 0;
		while (a[i] % 2 == 0) cnt2++, a[i] /= 2;
		while (a[i] % 5 == 0) cnt5++, a[i] /= 5;
		cnt2 = min(cnt2, 18ll), cnt5 = min(cnt5, 18ll);
		rep (j, 0, 18) {
			rep (k, 0, 18) {
				if (min(cnt2 + j, cnt5 + k) >= 18ll) {
					ans += cnt[j][k];
				}
			}
		}
	//	de(a[i]), de(cnt2), de(cnt5);
		cnt[cnt2][cnt5]++;
	}
	cout << ans << endl;
	return 0;
}
