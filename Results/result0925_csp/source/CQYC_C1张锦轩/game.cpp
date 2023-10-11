#include <bits/stdc++.h>
using namespace std;

int t, n, k;
char s[100002];
int sum[100002], nxt[100002], prv[100002];

int solve1() {
	int tot = 0;
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + (s[i] == '1');
		tot += s[i] == '1';
	}
	for (int i = k; i <= n; ++i) {
		if (sum[i] - sum[i - k] == tot) return 0; 
	}
	for (int i = 1; i <= n; ++i) {
		prv[i] = prv[i - 1];
		if (s[i] == '1') prv[i] = i;
	}
	for (int i = n; i >= 1; --i) {
		nxt[i] = nxt[i + 1]; 
		if (s[i] == '1') nxt[i] = i;
	}
	int yl = nxt[1], yr = prv[n];
	bool lose = 1;
	for (int i = k; i <= n && lose; ++i) {
		int l = i - k + 1, r = i;
		if (sum[r] - sum[l - 1] == 0) {
			if (yr - yl + 1 <= k); 
			else lose = 0;
		} else {
			int nl = nxt[l], nr = prv[r];
			if (nr < yl || nl > nr)
				assert(0);
			else if (nl > yl && nr < yr) { 
				if (yr - yl + 1 <= k) ;
				else lose = 0;
			} else {
				if (nl == yl) {
					int yl = nxt[nr + 1];
					if (yr - yl + 1 <= k) ; 
					else lose = 0;
				} else if (nr == yr) {
					int yr = prv[nl - 1];
					if (yr - yl + 1 <= k); 
					else lose = 0;
				} else assert(0);
			}
		}
	}
	if (lose) return -1;
	else return 1;
}

void solve() {
	scanf("%d%d%s", &n, &k, s + 1);
	int c = solve1();
	for (int i = 1; i <= n; ++i) s[i] = (s[i] == '1') ? '0' : '1';
	int d = solve1();
	if (c == 0 || d == 0) {
		puts("win");
	} else if (c == 1 || d == 1) {
		puts("tie");
	} else puts("lose");
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d", &t);
	while(t--) solve();
}
