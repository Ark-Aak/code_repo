#include<bits/stdc++.h>
#define int long long
#define N 1000006
#define mod 1000000007
#define inv 500000004
using namespace std;
int T, n, m, k, ans, ans2;
int X[N], Y[N], hang[N], lie[N], cnt1, cnt2;
bool vis[2010][2010];
bool x[N], y[N];
int sum1[N], sum2[N];
int B1[N], B2[N];
int walk[7][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dis[2010][2010];
struct node {
	int x, y;
};
void bfs(int sx, int sy) {
	queue<node>Q;
	for(int i = 1; i <= cnt1; i++)
	for(int j = 1; j <= cnt2; j++) dis[i][j] = -1;
	Q.push((node){sx, sy});
	dis[sx][sy] = 0;
	while(!Q.empty()) {
		node cmp = Q.front();
		Q.pop();
		for(int i = 0; i < 4; i++) {
			int dx = cmp.x + walk[i][0], dy = cmp.y + walk[i][1];
			if(dx < 1 || dx > cnt1 || dy < 1 || dy > cnt2 || dis[dx][dy] != -1 || vis[dx][dy]) continue;
			dis[dx][dy] = dis[cmp.x][cmp.y] + 1;
			Q.push((node){dx, dy});
		}
	}
	for(int i = 1; i <= cnt1; i++)
	for(int j = 1; j <= cnt2; j++)
		if(dis[i][j] != -1) {
			int now = B1[sx] * B2[sy] % mod;
			now = now * B1[i] % mod * B2[j] % mod;
			ans2 += dis[i][j] * now % mod;
			ans2 %= mod;
		}
}

void Sol() {
	cnt1 = cnt2 = ans = ans2 = 0;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) x[i] = hang[i] = sum1[i] = 0;
	for(int i = 1; i <= m; i++) y[i] = lie[i] = sum2[i] = 0;
	for(int i = 1; i <= k; i++) {
		cin >> X[i] >> Y[i];
		x[X[i]] = y[Y[i]] = 1;
		sum1[X[i]]++; sum2[Y[i]]++;
	}
	for(int i = 1; i <= n; i++) sum1[i] += sum1[i - 1];
	for(int i = 1; i <= m; i++) sum2[i] += sum2[i - 1];
	for(int i = 1; i <= n; ) {
		if(x[i]) {
			hang[i] = ++cnt1;
			i++;
			B1[cnt1] = 1;
		}
		else {
			hang[i] = ++cnt1;

			int j = i - 1;
			while(!x[j + 1] && j < n) j++;
			B1[cnt1] = j - i + 1;
			for(int z = i; z <= j - 1; z++)
				ans = (ans + (z * m % mod - sum1[z] + mod) % mod * ((n - z) * m % mod - (sum1[n] - sum1[z]) + mod) % mod) % mod;
			i = j + 1;
		}
	}

	for(int i = 1; i <= m; ) {
		if(y[i]) {
			lie[i] = ++cnt2;
			i++;
			B2[cnt2] = 1;
		}
		else {
			lie[i] = ++cnt2;
			int j = i - 1;
			while(!y[j + 1] && j < m) j++;
			B2[cnt2] = j - i + 1;
			for(int z = i; z <= j - 1; z++)
				ans = (ans + (z * n % mod - sum2[z] + mod) % mod * ((m - z) * n % mod - (sum2[m] - sum2[z]) + mod) % mod) % mod;
			i = j + 1;
		}
	}
	for(int i = 1; i <= cnt1; i++)
	for(int j = 1; j <= cnt2; j++) vis[i][j] = 0;
	for(int i = 1; i <= k; i++) vis[hang[X[i]]][lie[Y[i]]] = 1;

	for(int i = 1; i <= cnt1; i++)
	for(int j = 1; j <= cnt2; j++)
		if(!vis[i][j]) bfs(i, j);
	cout << (ans + ans2 * inv % mod) % mod << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--) Sol();
	return 0;
}
