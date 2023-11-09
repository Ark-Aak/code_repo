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

namespace Subtask1 {
	int cmpcnt = 0;

	void sort(vector <int> a, int n) {
		if (n <= 1) return;
		int pivot = a[ceil(a.size() / 2)];
		vector <int> al, ag;
		al.emplace_back(0), ag.emplace_back(0);
		rep (i, 1, n) {
			cmpcnt = cmpcnt + 1;
			if (a[i] < pivot) al.emplace_back(a[i]);
			if (a[i] > pivot) ag.emplace_back(a[i]);
		}
		sort(al, al.size() - 1), sort(ag, ag.size() - 1);
	}
}

int n;
vector <int> tt;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
#endif
#endif
	read(n);
	tt.emplace_back(0);
	rep (i, 1, n) {
		int c;
		read(c);
		tt.emplace_back(c);
	}
	Subtask1::sort(tt, n);
	print(Subtask1::cmpcnt);
	return 0;
}
