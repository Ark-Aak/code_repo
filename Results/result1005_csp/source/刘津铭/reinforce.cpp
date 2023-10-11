#include<bits/stdc++.h>
using namespace std;
int n, ans = 1;
string s;
bool f[40];
signed main() {
	freopen("reinforce.in", "r", stdin);
	freopen("reinforce.out", "w", stdout);
	cin >> s;
	n = s.length();
	s = " " + s;
	for(int i = 1; i <= n; i++) {
		if(f[s[i] - 'a' + 1] == 1) {
			ans++;
			for(int j = 1; j <= 26; j++) f[j] = 0;
		}
		f[s[i] - 'a' + 1] = 1;
	} 
	cout << ans;
	return 0;
}

