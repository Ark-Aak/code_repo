#include<bits/stdc++.h>
using namespace std;
int n, m, a[2005][2005];
bool check(int x, int y) {
	if(a[x][y - 1] == 1&& a[x - 1][y] == 1&& a[x - 1][y - 1] == 0)	return true;
	if(a[x][y - 1] == 1&& a[x + 1][y] == 1&& a[x + 1][y - 1] == 0)	return true;
	if(a[x][y + 1] == 1&& a[x - 1][y] == 1&& a[x - 1][y + 1] == 0)	return true;
	if(a[x][y + 1] == 1&& a[x + 1][y] == 1&& a[x + 1][y + 1] == 0)	return true;
	return false;
}
bool check2(int x, int y) {
	if(a[x][y] == 1&&a[x - 1][y] == 0&& a[x][y - 1] == 0&& a[x - 1][y - 1] == 1)	return true;
	if(a[x][y] == 1&&a[x + 1][y] == 0&& a[x][y - 1] == 0&& a[x + 1][y - 1] == 1)	return true;
	if(a[x][y] == 1&&a[x - 1][y] == 0&& a[x][y + 1] == 0&& a[x - 1][y + 1] == 1)	return true;
	if(a[x][y] == 1&&a[x + 1][y] == 0&& a[x][y + 1] == 0&& a[x + 1][y + 1] == 1)	return true;
	return false;
}
int main() {
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			char ch;
			cin>>ch;
			if(ch != '?') {
				a[i][j] = ch - '0';
			}
			else {
				a[i][j] = -1;
			}
		}
	}
	for(int i = 1; i <= n ; ++i) {
		for(int j = 1; j <= m;j++) {
			if(a[i][j] == -1) {
				if(check(i, j)) {
					a[i][j] = 1;
				}
				else {
					a[i][j] = 0;
				}
			}
		}
	}
	for(int i = 1; i < n; ++i) {
		for(int j = 1; j < m; ++j) {
			if(check2(i, j)) {
				cout<<"No";
				return 0;
			}
		} 
	}
	cout<<"Yes"<<endl;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}
