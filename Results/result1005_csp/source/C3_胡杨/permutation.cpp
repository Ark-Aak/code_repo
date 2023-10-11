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
int n,k,tot,l;
int f[5][100010];
int f1[600010][110];
int a[100010],b[100010];
int main() {
	freopen("permutation1.in","r",stdin);
	freopen("permutation1.out","w",stdout);
	read(n);
	read(k);
	for(int i = 1 ; i <= n ; i++) read(a[i]);
	for(int i = 1 ; i <= n ; i++) read(b[i]);
	if(n <= 100 && k >= 1000000) {
		for(int i = 1 ; i <= n ; i++)
			f1[0][i] = a[i], f1[1][i] = b[i];
		for(int x = 2 ; x <= 500000 ; x++) {
			for(int i = 1 ; i <= n ; i++)
				f1[x][f1[x - 2][i]] = f1[x - 1][i];
			int t = 0, t1 = 0;
			if(x > 2) {
				for(int i = 1 ; i <= n ; i++) {
					if(f1[x - 1][i] != a[i]) {
						t = 1;
						break;
					}
					if(f1[x][i] != b[i]) {
						t1 = 1;
						break;
					}
				}
				if(t1 == 0 && t == 0) {
					l = x - 1;
					break;
				}
			}
		}
		int x = k % l;
		for(int i = 1 ; i <= n ; i++)
			printf("%lld ",f1[x][i]);
		cout << endl;
		return 0;
	}
	for(int i = 1 ; i <= n ; i++)
		f[0][i] = a[i], f[1][i] = b[i];
	for(int x = 2 ; x <= k ; x++) {
		for(int i = 1 ; i <= n ; i++)
			f[2][f[0][i]] = f[1][i];
		for(int i = 1 ; i <= n ; i++)
			f[0][i] = f[1][i], f[1][i] = f[2][i];
	}
	for(int i = 1 ; i <= n ; i++)
		printf("%lld ",f[1][i]);
	cout << endl;
	return 0;
	return 0;
}
/*
5 98
4 5 1 2 3
3 2 1 5 4

3 2 1 5 4
*/

