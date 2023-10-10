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

string T;
const int MAXN = 1e6 + 5;
int Q, b[MAXN];

template <typename _Tp> class Matrix {
public:
	_Tp res[6][6];

	Matrix() {
		memset(res, 0, sizeof res);
	}
	
	_Tp* operator [] (int x) {
		return res[x];
	}

	friend Matrix operator * (Matrix x, Matrix y) {
		Matrix z;
		rep (i, 0, 5) rep (j, 0, 5) {
			if (x[i][j]) {
				rep (k, 0, 5) z[i][k] += x[i][j] * y[j][k];
			}
		}
		return z;
	}
};

Matrix <unsigned> pref[MAXN], inv_pref[MAXN];

int main() {
	cin >> T;
	int n = T.length();
	rep (i, 1, T.length()) {
		if (T[i - 1] == 'm') b[i] = 1;
		if (T[i - 1] == 'i') b[i] = 2;
		if (T[i - 1] == 'l') b[i] = 3;
		if (T[i - 1] == 'k') b[i] = 4;
		if (T[i - 1] == 'y') b[i] = 5;
	}
	Matrix <unsigned> I;
	rep (i, 0, 5) I[i][i] = 1;
	pref[0] = inv_pref[0] = I;
	rep (i, 1, n) {
		Matrix <unsigned> a = I;
		a[b[i] - 1][b[i]] = 1;
		pref[i] = pref[i - 1] * a;
		a = I, a[b[i] - 1][b[i]] = -1;
		inv_pref[i] = a * inv_pref[i - 1];
	}
	cin >> Q;
	while (Q --> 0) {
		int l, r;
		cin >> l >> r;
		Matrix <unsigned> ans = inv_pref[l - 1] * pref[r];
		cout << ans[0][5] << endl;
	}
	return 0; 
}
