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

ll n, pd, id = 1, x = 1, y = 1;
ll a[100][100];
int main() {
	n = read();
	rep(i, 1, n) {
		a[0][i] = 1;
		a[i][0] = 1;
		a[n + 1][i] = 1;
		a[i][n + 1] = 1;
	}
	rep (i, 1, n) {
		rep (j, 1, n) {
			a[x][y] = id;
			id++;
			if (pd == 0) y++;
			if (pd == 1) y--;
			if (pd == 2) x++;
			if (pd == 3) x--;
			if (a[x][y] > 0) {
				if (pd == 0) {
					y--, pd = 2, x++;
					continue;
				}
				if (pd == 1) {
					y++, pd = 3, x--;
					continue;
				}
				if (pd == 2) {
					x--, pd = 1, y--;
					continue;
				}
				if (pd == 3) {
					x++, pd = 0, y++;
					continue;
				}
			}
		}
	}
	rep (i, 1, n) {
		rep (j, 1, n) {
			if ((n + 1) / 2 == i && (n + 1) / 2 == j)
				cout << "T" << " ";
			else cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
