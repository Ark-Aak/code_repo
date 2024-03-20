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

ll n, q, o, p, x = 1, y = 0;
char c;
ll a[3000000][3], cnt;
int main() {
	cin >> n >> q;
	cnt = n;
	rep (i, 0, n - 1) a[i + 1][1] = n - i, a[i + 1][2] = 0;
	while (q --> 0) {
		cin >> o;
		if (o == 2) {
			ll id;
			cin >> id;
			cout << a[cnt - id + 1][1] << " " << a[cnt - id + 1][2] << endl;
		}
		else {
			cin >> c;
			if (c == 'R') x++;
			if (c == 'L') x--;
			if (c == 'U') y++;
			if (c == 'D') y--;
			cnt++;
			a[cnt][1] = x;
			a[cnt][2] = y;
		}
	}
}
