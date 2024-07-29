#include<bits/stdc++.h>

#define rep(i, a, b) for (auto i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (auto i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int read() {
	int x = 0, w = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') w = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = x * 10 + (c ^ 48);
		c = getchar();
	}
	return  x * w;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}

string str;
int n, ans;
set <string> s;

void dfs(string str, int len) {
	if (s.find(str) != s.end()) return;
	s.insert(str);
	rep (i, 1, len - 1) {
		string nxt = " ";
		if (str[i] == str[i + 1]) {
			rep (j, 1, i - 1) nxt += str[j];
			rep (j, i + 2, len) nxt += str[j];
			dfs(nxt, len - 2);
		}
		else if (str[i] == 'B' && str[i + 1] == 'A') {
			rep (j, 1, i - 1) nxt += str[j];
			rep (j, i + 2, len) nxt += str[j];
			dfs(nxt, len - 2);
		}
	}
}

signed main() {
#ifndef LOCAL
	freopen("song.in", "r", stdin);
	freopen("song.out", "w", stdout);
#endif
	cin >> str;
	n = str.size();
	str = ' ' + str;
	if (n <= 20) {
		dfs(str, n);
		print(s.size()), puts("");
	}
	else {
		if (str[1] == 'A') {
			if (str[n] == 'A') {
				print(n / 2), puts("");
			}
			else {
				print(n / 2 - 1), puts("");
			}
		}
		else {
			if (str[n] == 'A') {
				print(n / 2), puts("");
			}
			else {
				print(n / 2), puts("");
			}
		}
	}
	return 0;
}
