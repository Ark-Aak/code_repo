#include <bits/stdc++.h>
using namespace std;

int n, m;
char s[23][200003];
unordered_map<string, bool> vis;
int ans = 1 << 30;

void dfs() {
	string str = "";
	for (int i = 1; i <= n; ++i) str += string(s[i] + 1);
	if (vis[str]) return;
	vis[str] = 1;
	int tmp = 0;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) tmp += (s[i][j] == '1');
	ans = min(ans, tmp);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			s[i][j] = (s[i][j] == '1' ? '0' : '1');
		}
		dfs();	
		for (int j = 1; j <= m; ++j) {
			s[i][j] = (s[i][j] == '1' ? '0' : '1');
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			s[j][i] = (s[j][i] == '1' ? '0' : '1');
		}
		dfs();
		for (int j = 1; j <= n; ++j) {
			s[j][i] = (s[j][i] == '1' ? '0' : '1');
		}
	}
}

bool update() { // 虽然我知道，这样做一分都不能得
	bool a = 0;
	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		for (int j = 1; j <= m; ++j) {
			if (s[i][j] == '1') ++cnt;
		}
		if (cnt >= m / 2) {
			a = 1;
			for (int j = 1; j <= m; ++j) {
				s[i][j] = (s[i][j] == '1' ? '0' : '1');
			}
		}
	}
	for (int i = 1; i <= m; ++i) {
		int cnt = 0;
		for (int j = 1; j <= n; ++j) {
			if (s[j][i] == '1') ++cnt;
		}
		if (cnt >= n / 2) {
			a = 1;
			for (int j = 1; j <= n; ++j) {
				s[j][i] = (s[j][i] == '1' ? '0' : '1');
			}
		}
	}
	return a;
}

int main() {
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out","w", stdout);
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
	}
	if (n <= 4 && m <= 4) dfs();
	else {
		int count = 300000000 / n / m;
		for (int i = 1; i <= count; ++i){
			if (!update()) break;
		}
		int tmp = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				tmp += (s[i][j] == '1');
			}
		}
		printf("%d\n", tmp);
		return 0;
	}
	printf("%d\n", ans);

}
