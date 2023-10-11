#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;

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



int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("kel.in", "r", stdin);
	freopen("kel.out", "w", stdout);
#endif
#endif
	int n, l, r;
	cin >> n >> l >> r;
	if (r - l + 1 >= n) {
		rep (i, l, l + n - 1) cout << i << endl;
		return 0;
	}
	cout << "Shinomiya";
	return 0; 
}
