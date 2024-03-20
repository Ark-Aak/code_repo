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

int n, h[1000005];
int ans1[1000005], ans2[1000005];
stack <pair <int, int> > s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	read(n);
	rep (i, 1, n)  read(h[i]);
	rep (i, 1, n) ans2[i] = n + 1;
	rep (i, 1, n) {
		while (s.size() && s.top().first <= h[i]) s.pop();
		if (s.size()) ans1[i] = s.top().second;
		s.push({h[i], i});
	}
	while (s.size()) s.pop();
	_rep (i, n, 1) {
		while (s.size() && s.top().first <= h[i]) s.pop();
		if (s.size()) ans2[i] = s.top().second;
		s.push({h[i], i});
	}
	rep (i, 1, n) print(ans2[i] - ans1[i] - 2), putchar(10);
	return 0; 
}
