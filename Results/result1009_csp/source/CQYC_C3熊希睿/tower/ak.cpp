#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

long long int n, k, a[1000005], sum;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("ak.in", "r", stdin);
	freopen("ak.out", "w", stdout);
#endif
#endif
	read(n), read(k);
	rep (i, 1, n) read(a[i]), sum += a[i];
	sort(a + 1, a + 1 + n);
	sum -= a[n / 2 + 1];
	cout << sum;
	return 0; 
}
