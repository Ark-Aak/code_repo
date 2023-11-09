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

vector <int> grid[15][3];

int main() {
	rep (i, 1, 9) {
		rep (j, 1, 9) {
			int c;
			cin >> c;
			int ps = (i - 1) / 3;
			ps *= 3;
			ps += (j - 1) / 3 + 1;
			grid[ps][0].emplace_back(c);
			grid[i][1].emplace_back(c);
			grid[j][2].emplace_back(c);
		}
	}
	rep (i, 0, 2) rep (j, 1, 9) sort(grid[j][i].begin(), grid[j][i].end());
	rep (i, 1, 9) {
		rep (k, 0, 2)
			rep (j, 1, grid[i][k].size() - 1) if (grid[i][k][j] == grid[i][k][j - 1]) {
				cout << "No";
				return 0;
			}
	}
	cout << "Yes";
	return 0;
}
