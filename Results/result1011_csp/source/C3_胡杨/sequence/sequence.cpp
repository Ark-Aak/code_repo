#include<bits/stdc++.h>
#define int long long
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
const int mod = 998244353;
int n, m;
int f[2010][2010][2];
int s[2010];
struct node {
	int x, y;
} a[20010];
int tot;
signed main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	for(int i = 1 ; i <= m ; i++)
		for(int j = 1 ; j <= m ; j++)
			if(i > j && i % j == 0) a[++tot].x = i, a[tot].y = j;
	for(int i = 1 ; i <= m ; i++) f[1][i][0] = 1;
	for(int i = 1 ; i < n ; i++) {
		memset(s, 0, sizeof s);
		for(int j = 1 ; j <= m ; j++) s[j] = (s[j - 1] + f[i][j][0] + f[i][j][1]) % mod;
		for(int j = 1 ; j <= m ; j++) f[i + 1][j][0] = (f[i + 1][j][0] + s[j]) % mod;
		memset(s, 0, sizeof s);
		for(int j = m ; j >= 1 ; j--) s[j] = (s[j + 1] + f[i][j][0] + f[i][j][1]) % mod;
		for(int j = 1 ; j <= m ; j++) f[i + 1][j][1] = (f[i + 1][j][1] + s[j + 1]) % mod;
		for(int j = 1 ; j <= tot ; j++) {
			int x = a[j].x, y = a[j].y;
			f[i + 1][y][1] = (f[i + 1][y][1] - f[i][x][0] + mod - f[i][x][1] + mod) % mod;
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= m ; i++) ans = (ans + f[n][i][0] + f[n][i][1]) % mod;
	printf("%lld\n", ans);
	return 0;
}
