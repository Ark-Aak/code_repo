#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

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

#define int ll

const int MAXN = 2e5 + 5;
int n, q;
int r[MAXN];

signed main() {
	cin >> n >> q;
	rep (i, 1, n) cin >> r[i];
	sort(r + 1, r + 1 + n);
	rep (i, 1, n) r[i] += r[i - 1];
	rep (i, 1, q) {
		int x;
		cin >> x;
		cout << upper_bound(r + 1, r + 1 + n, x) - 1 - r << endl;
	}
	return 0;
}
