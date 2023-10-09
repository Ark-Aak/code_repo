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

int n, m;
int a[1145141];
int ans[1145141];

int main() {
	cin >> n >> m;
	rep (i, 1, m) cin >> a[i];
	rep (i, 1, m) {
		ans[a[i]] = 0;
		int ptr = a[i] - 1;
		while (ptr && ptr != a[i - 1]) ans[ptr] = ans[ptr + 1] + 1, ptr--;
	}
	rep (i, 1, n) cout << ans[i] << endl;
	return 0; 
}
