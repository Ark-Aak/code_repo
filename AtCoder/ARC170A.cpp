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

int n;
string s, t;
signed main(){
	cin >> n >> s >> t;
	s = ' ' + s, t = ' ' + t;
	int ops = 0, sum = 0, res = 0;
	int ans = 0;
	_rep (i, n, 1) {
		if (s[i] == 'B' && t[i] == 'A') {
			if (sum) {
				ops = 1, sum--, res = max(res - 1, 0);
			}
			else if(ops) {
				ans++;
			}
			else {
				cout << -1;
				return 0;
			}
		}
		else if (s[i] == 'B' && t[i] == 'B') {
			ops = 1;
		}
		else if (s[i] == 'A' && t[i] == 'B') {
			sum++, res++, ans++;
		}
		else if (s[i] == 'A' && t[i] == 'A') {
			res = 0;
		}
	}
	if (res) cout << -1;
	else cout << ans;
	return 0;
}
