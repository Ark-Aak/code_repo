#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int f[N][20], vis[N][20];
int n, cnto = 0, cnty = 0;
string s, t;
void solve() {
	f[0][s[0] - '0'] = 1;
	if(t[0] == 'o') vis[0][s[0] - '0'] = 1;
	f[0][0] = 1;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= 10; j++) {
			int p = (j - (s[i] - '0') + 11) % 11;
			if(f[i - 1][j] && f[i - 1][p]) {
				if(vis[i - 1][j] && !vis[i - 1][p] && t[i] == 'o') vis[i][j] = 1;
				vis[i][j] = (vis[i - 1][j] && vis[i - 1][p]);
			} else if(f[i - 1][j]) vis[i][j] = vis[i - 1][j];
			else if(f[i - 1][p]) {
				vis[i][j] = vis[i - 1][p];
				if(t[i] == 'o') vis[i][j] = 1;
			}
			f[i][j] |= f[i - 1][j];
			f[i][j] |= f[i - 1][p];
		}
	}
	if(f[n - 1][0] && !vis[n - 1][0]) cout << "yoimiya";
	else cout << "oimiya";
}
int main() {
	
	freopen("yo.in", "r", stdin);
	freopen("yo.out", "w", stdout);
	cin >> n;
	cin >> s >> t;
	for(int i = 0; i < n; i++) {
		if(t[i] == 'y') ++cnty;
		if(t[i] == 'o') ++cnto;
	}
	if(cnty == n) {
		f[0][0] = 1;
		f[0][s[0] - '0'] = 1;
		for(int i = 1; i < n; i++) {
			for(int j = 0; j <= 10; j++) {
				int p = (j - (s[i] - '0') + 11) % 11;
				f[i][j] |= f[i - 1][j];
				f[i][j] |= f[i - 1][p];
			}
		}
		if(f[n - 1][0]) cout << "yoimiya";
		else cout << "oimiya";
	} else if(cnto == n) cout << "oimiya";
	else {
		solve();
	}
}
