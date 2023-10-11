#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s, t;
int f[1000006][13];
bool dfs(int x, int sum) {
	if(f[x][sum] != -1) return f[x][sum];
	if(x == n + 1) {
		if(sum % 11 == 0) return 1;
		else return 0;
	}
	if(x < n) {
		int now, nxt;
		if(t[x] == 'y') now = 1;
		else now = 0;
		if(t[x + 1] == 'y') nxt = 1;
		else nxt = 0;

		bool num = dfs(x + 1, (sum * 10 + s[x] - '0') % 11);
		if(now == nxt && num == 1 || now != nxt && num == 0) return f[x][sum] = 1;
		num = dfs(x + 1, sum * 10 % 11);
		if(now == nxt && num == 1 || now != nxt && num == 0) return f[x][sum] = 1;
	}
	if(x == n) {
		int now;
		if(t[x] == 'y') now = 1;
		else now = 0;
	    bool num = dfs(x + 1, (sum * 10 + s[x] - '0') % 11);
	    if(num == 1 && now == 1) return f[x][sum] = 1;
	    num = dfs(x + 1, sum * 10 % 11);
	    if(num == 0 && now == 0) return f[x][sum] = 1; 
	}
	return f[x][sum] = 0;
}
signed main() {
	freopen("yo.in", "r", stdin);
    freopen("yo.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) 
    for(int j = 0; j <= 10; j++) f[i][j] = -1;
    cin >> s >> t;
    s = " " + s, t = " " + t;
    int y = 0, o = 0, l = 0;
    for(int i = 1; i <= n; i++) 
        if(t[i] == 'y') y++;
        else {
        	o++;
        	if(s[i] >= '1') l = 1;
		} 
    if(y == n) {
    	cout << "yoimiya";
    	return 0;
	}
	if(o == n) {
		if(l == 1) cout << "oimiya";
		else cout << "yoimiya";
		return 0;
	}

	bool num = dfs(1, 0);
	if(t[1] == 'y' && num == 1 || t[1] == 'o' && num == 0) cout << "yoimiya";
	else cout << "oimiya";
	return 0;

	return 0;
}

