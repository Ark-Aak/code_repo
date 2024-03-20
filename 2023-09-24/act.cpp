#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a); i <= b; i++)
#define _rep(i, a, b) for(int i = (a); i >= b; i--)

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

int n, q;
int a[1000005], b[1000005];

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("act.in", "r", stdin);
	freopen("act.out", "w", stdout);
#endif
#endif
	cin >> n >> q;
	rep (i, 1, n) cin >> a[i];
	rep (i, 1, n) cin >> b[i];
	if (q == 0) return 0;
	while (q --> 0) {
		int oa, ob;
		cin >> oa >> ob;
		if (n == 0) {
			if (oa == 0 && ob == 0) cout << "Bob" << endl;
			else if (oa == 0 || ob == 0) cout << "Alice" << endl;
			else if (oa == 1 && ob == 1) cout << "Bob" << endl;
			else if (oa == 1 || ob == 1) cout << "Alice" << endl;
			else cout << "Bob" << endl;
		}
	}
	return 0; 
}
