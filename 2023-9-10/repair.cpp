#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define rep(i, a, b) for(int i = (a); i <= b; i++)
#define _rep(i, a, b) for(int i = (a); i >= b; i--)

using namespace std;
using namespace __gnu_pbds;

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

const int MAXN = 1e6 + 5;
int n, h[MAXN], maxh, sp, tp;

__gnu_pbds::tree <int, null_type,
                  less <int>, rb_tree_tag,
                  tree_order_statistics_node_update> tr;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("repair.in", "r", stdin);
	freopen("repair.out", "w", stdout);
#endif
#endif
	cin >> n;
	rep (i, 1, n) {
		cin >> h[i];
		tr.insert(h[i]);
		if (h[i] > maxh) sp = i, maxh = h[i];
		if (h[i] == maxh) tp = i;
	}
	return 0; 
}
