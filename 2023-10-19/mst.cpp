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

const int MAXN = 25, MAXM = 105;
int n, m;
vector <int> G[MAXN];

//我是废物，这道题都出不来。
//一伯四毫无优势
//别人都是好几伯分
//呜呜呜
//垫底了。

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("mst.in", "r", stdin);
	freopen("mst.out", "w", stdout);
#endif
#endif

	return 0;
}
