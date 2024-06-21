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

int A, B;
int n;

signed main() {
	cin >> n >> A >> B;
	int LL = A + B - 1, RR = 0;
	int l = 0, r = A + B - 1;
	rep (i, 1, n) {
		int x;
		cin >> x;
		x %= A + B;
		int L = (A + B - x) % (A + B);
		int R = (A - 1 - x + A + B) % (A + B);
		if (L > R) {
			LL = min(LL, R);
			RR = max(RR, L);
		}
		else {
			l = max(l, L);
			r = min(r, R);
		}
	}
	if ((l <= r) && (LL >= l || r >= RR)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}
