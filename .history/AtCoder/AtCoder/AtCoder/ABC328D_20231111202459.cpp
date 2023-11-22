#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _tp>
void read(_tp& first) {
	_tp x = 0, f = 1; char c = getchar();
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

template <typename _tp>
void print(_tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

string s;
int tp = 0;
char stk[200005];

int main() {
	cin >> s;
	for (auto c : s) {
		stk[++tp] = c;
		if (tp >= 3 && stk[tp] == 'C' && stk[tp - 1] == 'B' && stk[tp - 2] == 'A') tp -= 3;
	}
	rep (i, 1, tp) putchar(stk[i]);
	return 0;
}