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



int main() {
	char s1, s2, t1, t2;
	s1 = getchar();
	while (!isalpha(s1)) s1 = getchar();
	s2 = getchar();
	while (!isalpha(s2)) s2 = getchar();
	t1 = getchar();
	while (!isalpha(t1)) t1 = getchar();
	t2 = getchar();
	while (!isalpha(t2)) t2 = getchar();
	if (s2 < s1) swap(s1, s2);
	if (t2 < t1) swap(t1, t2);
	while (s1 > 'A') s1--, s2--;
	while (t1 > 'A') t1--, t2--;
	int len1, len2;
	if (s2 == 'B' || s2 == 'E') len1 = 1;
	else if (s2 == 'C' || s2 == 'D') len1 = 2;
	if (t2 == 'B' || t2 == 'E') len2 = 1;
	else if (t2 == 'C' || t2 == 'D') len2 = 2;
	if (len1 == len2) puts("Yes");
	else puts("No");
	return 0;
}
