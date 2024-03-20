#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 3005;
int T, n;
int a[MAXN], b[MAXN];
char c[MAXN];

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("brace.in", "r", stdin);
	freopen("brace.out", "w", stdout);
#endif
#endif
	read(T);
	while (T --> 0) {
		read(n);
		rep (i, 1, 2 * n) cin >> a[i] >> b[i] >> c[i];
		if (c[2] == '(') swap(a[1], a[2]), swap(b[1], b[2]), swap(c[1], c[2]);
		if (a[1] > b[1]) swap(a[1], b[1]);
		if (a[2] > b[2]) swap(a[2], b[2]);
		if ((a[1] > a[2] && b[1] < b[2]) || (a[1] < a[2] && b[1] > b[2])) puts("YES");
		else puts("NO");
	}
	return 0;
}