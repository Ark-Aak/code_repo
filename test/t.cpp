#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a); i <= b; i++)
#define _rep(i, a, b) for(int i = (a); i >= b; i--)

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

mt19937 rnd(time(0));

double get() {
	return abs((int) rnd()) % 6 + 1;
}

const double arr[4] = {95/648, 4/27, 5/27, 1/6};
int cnt1, cnt2;

int main() {
	while (1) {
		double a = get(), b = get(), c = get(), d = get();
		if (a < b && b > c && c < d) cnt2++;
		cnt1++;
		cout << (cnt2 / __gcd(cnt1, cnt2)) << " / " << (cnt1 / __gcd(cnt1, cnt2)) << endl;
	}
	return 0; 
}
