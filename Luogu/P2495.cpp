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



int main() {
	cout << "🤣🤣👇👇👇👇👇👇👇👇👇🤣🤣\n🤣👉🤣👇👇👇👇👇👇👇🤣👈🤣\n🤣👉👉🤣👇👇👇👇👇🤣👈👈🤣\n🤣👉👉👉🤣👇👇👇🤣👈👈👈🤣\n🤣👉👉👉👉🤣👇🤣👈👈👈👈🤣\n🤣👉👉👉👉👉🤡👈👈👈👈👈🤣\n🤣👉👉👉👉🤣👆🤣👈👈👈👈🤣\n🤣👉👉👉🤣👆👆👆🤣👈👈👈🤣\n🤣👉👉🤣👆👆👆👆👆🤣👈👈🤣\n🤣👉🤣👆👆👆👆👆👆👆🤣👈🤣\n🤣🤣👆👆👆👆👆👆👆👆👆🤣🤣";
	return 0;
}
