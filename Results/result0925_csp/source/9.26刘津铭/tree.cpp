#include<bits/stdc++.h>
#define N 400005
#define mod 1000000007
using namespace std;
int n, k;
long long cnt; 
vector<int>p[N];
int fa[N];
int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void join(int x, int y) {
	int fx = find(x), fy = find(y);
	if(fx != fy) fa[fx] = fy;
}
int b[N];
/*int g(int n) {
	int S = 0;
	for(int len = 1; len <= n; len++) { //Ã¶¾Ù³¤¶È 
		int num = n - len + 1;
		if(k == 1) S = (S + num * len) % mod;
		else S = (S + num * len * len) % mod;
	}
	return S;
}*/
signed main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		p[u].push_back(v);
		p[v].push_back(u);
	}
	/*if(n > 5000) {
		int x = 0;
		for(int i = 1; i <= n; i++) 
		    if(p[i].size() == n - 1) {
		    	x = i;
		    	break;
			}
		cnt = x * (n - x + 1) % mod;
		cnt = (cnt + g(x - 1)) % mod;
		cnt = (cnt + g(n - x)) % mod;
		cout << cnt;
		return 0;
	}*/
	for(int i = 1; i <= n; i++) {           
		for(int j = 1; j <= n; j++) fa[j] = j; 
		long long ans = 0;
		for(int j = i; j <= n; j++) {
			int tot = 0;
			bool flag = 1;
			for(int k = 0; k < p[j].size(); k++) {
				int y = p[j][k];
				if(i <= y && y <= j) {
					b[++tot] = find(j);
					join(y, j);
					flag = 0; 
				}
			}
			if(flag) {
				ans++;
				cnt = (cnt + ans * ans) % mod;
				continue;
			}
			sort(b + 1, b + tot + 1);
			int dif = 0;
			for(int k = 1; k <= tot; k++)
			    if(k == 1 || b[k] != b[k - 1]) dif++;
			ans -= (dif - 1);
			cnt = (cnt + ans * ans) % mod;
		}
	}
	cout << cnt;
	return 0;
} 

/*
5 2
3 1
3 2 
3 4
3 5
*/

