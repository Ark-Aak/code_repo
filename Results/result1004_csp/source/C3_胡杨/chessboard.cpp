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
int n,m;
int a[2010][2010];
int main() {
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	read(n);
	read(m);
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= m ; j++) {
			char x;
			cin >> x;
			if(x == '0') a[i][j] = 0;
			else if(x == '1') a[i][j] = 1;
			else a[i][j] = -2;
		}
	}
	for(int i = 1 ; i <= n ; i++) a[i][0] = a[i][m + 1] = 1e9;
	for(int i = 1 ; i <= m ; i++) a[0][i] = a[n + 1][i] = 1e9;
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= m ; j++) {
//			for(int x = 1 ; x <= n ; x ++) {
//				for(int y = 1 ; y <= m ; y++)
//					cout << a[x][y];
//				cout << endl;
//			}
//			cout<<"-----------"<<endl;
			if(a[i][j] + a[i + 1][j] == 1 && a[i][j] + a[i][j + 1] == 1 && (a[i][j] + a[i + 1][j + 1] == 0 ||a[i][j] + a[i + 1][j + 1] == 2)) {
				cout << "No" << endl;
				return 0;
			}
			if(a[i][j] == -2) {
				if(i > 1 && j > 1) {
					if(a[i - 1][j] == 1 && a[i][j - 1] == 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1)
						a[i][j] = 1;
					else if(a[i - 1][j] == 0 && a[i][j - 1] == 0 && a[i + 1][j] == 0 && a[i][j + 1] == 0)
						a[i][j] = 0;
					else if(a[i - 1][j] == 1 && a[i][j - 1] == 1 && a[i + 1][j] == 0 && a[i][j + 1] == 0 && a[i - 1][j - 1] == 0 && a[i + 1][j + 1] == 1) {
						cout << "No" << endl;
						return 0;
					} else if(a[i - 1][j] == 0 && a[i][j - 1] == 0 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i - 1][j - 1] == 1 && a[i + 1][j + 1] == 0) {
						cout << "No" << endl;
						return 0;
					} else if(a[i - 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j] == 0 && a[i][j - 1] == 0 && a[i - 1][j + 1] == 0 && a[i + 1][j - 1] == 1) {
						cout << "No" << endl;
						return 0;
					} else if(a[i - 1][j] == 0 && a[i][j + 1] == 0 && a[i + 1][j] == 1 && a[i][j - 1] == 1 && a[i - 1][j + 1] == 1 && a[i + 1][j - 1] == 0) {
						cout << "No" << endl;
						return 0;
					}
				} 
				if(i > 1 && j > 1 && a[i - 1][j] == a[i][j - 1] && (a[i][j] == a[i - 1][j - 1] || a[i - 1][j - 1] != a[i - 1][j])) a[i][j] = a[i - 1][j];
				if(i > 1 && j < m && a[i - 1][j] == a[i][j + 1] && (a[i][j] == a[i - 1][j + 1] || a[i - 1][j + 1] != a[i - 1][j])) a[i][j] = a[i - 1][j];
				if(i < n && j > 1 && a[i][j - 1] == a[i + 1][j] && (a[i][j] == a[i + 1][j - 1] || a[i + 1][j - 1] != a[i + 1][j])) a[i][j] = a[i + 1][j];
				if(i < n && j < m && a[i + 1][j] == a[i][j + 1] && a[i][j] == a[i + 1][j + 1]) a[i][j] = a[i + 1][j];
			}
		}
	}
	cout << "Yes" << endl;
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= m ; j++) {
			if(a[i][j] != -2) cout << a[i][j];
			else cout << 1;
		}
		cout << endl;
	}
	return 0;
}
/*
3 3
0?0
?0?
0?0
*/
