#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
	x = 0;
	char ch = getchar();
	int f = 1;
	while (!isdigit(ch) && ch ^ '-') ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
	x *= f;
}
int n, tt;
int s[5], a[1000010], b[1000010];
int f[1000010][11];
int f1[1000010][11];
signed main() {
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	read(n);
	for(int i =  1 ; i <= n ; i++) {
		char x;
		cin >> x;
		a[i] = x - '0';
	}
	for(int i = 1 ; i <= n ; i++) {
		char x;
		cin >> x;
		if(x == 'y') b[i] = 1;
		if(b[i] != b[i - 1] && i > 1) tt = 1;
	}
	if(!tt) {
		int aa = 0;
		for(int i = 1 ; i <= n ; i++)
			if(a[i] != 0) aa = 1, i = n + 1;
		if((aa == 0 && b[1] == 0) || b[1] == 1) {
			cout << "yoimiya";
			return 0;
		} else {
			cout << "oimiya";
			return 0;
		}
	}
	f[1][0] = f[1][b[1]] = 1;
	for(int i = 1 ; i < n ; i++) {
		for(int j = 0 ; j < 10 ; j++) {
			if(!f[i][j]) continue;
			if((j * 10) % 11 || b[i]) f[i + 1][(j * 10) % 11] = f[i][j];
			if((j * 10 + a[i]) % 11 || b[i]) f[i + 1][(j * 10 + a[i]) % 11] = f[i][j];
		}
	}
	if(b[n] && f[n][0]) {
		cout << "yoimiya";
		return 0;
	}
	cout << "oimiya";
	return 0;
}
