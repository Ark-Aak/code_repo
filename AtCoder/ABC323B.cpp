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

int n;
string s;

struct node {
	int val, id;
} nd[105];

int main() {
	cin >> n;
	rep (i, 1, n) {
		cin >> s;
		int cnt = 0;
		rep (j, 0, s.size() - 1) {
			if (s[j] == 'o') cnt++;
		}
		nd[i].val = cnt;
		nd[i].id = i;
	}
	sort(nd + 1, nd + 1 + n, [](node a, node b) {
		return a.val == b.val ? a.id < b.id : a.val > b.val;
	});
	rep (i, 1, n) cout << nd[i].id << " ";
	return 0; 
}
