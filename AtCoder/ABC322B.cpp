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
string s, t;

int main() {
	cin >> n >> m;
	cin >> s >> t;
	string sub1, sub2;
	sub1 = t.substr(0, n);
	sub2 = t.substr(m - n);
	if (sub1 == s && sub2 == s) cout << 0;
	else if (sub1 == s) cout << 1;
	else if (sub2 == s) cout << 2;
	else cout << 3;
	return 0; 
}
