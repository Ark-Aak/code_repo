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
int n,k;
const int mod = 1e9 + 7;
struct Tree{
	int to,nxt;
}tree[5010];
int head[5010],tot;
void add(int x,int y){
	tree[++tot].to = y;
	tree[tot].nxt = head[x];
	head[x] = tot;
}
int vis[5010],cnt;
int ans,s;
void dfs(int x,int l,int r){
	if(s >= mod) s -= mod;
	vis[x] = cnt;
	for(int i = head[x] ; i ; i = tree[i].nxt){
		int to = tree[i].to;
		if(to >= l && to <= r && !vis[to]) dfs(to,l,r);
	}
}
signed main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
    read(n);read(k);
    for(int i = 1 ; i < n ; i++){
    	int x,y;
    	read(x);read(y);
    	add(x,y);add(y,x);
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = i ; j <= n ; j++){
			memset(vis,0,sizeof vis);
			cnt = 0;
			for(int k = i ; k <= j ; k++)
				if(!vis[k]) cnt++,dfs(k,i,j);
			if(k == 2) ans = (ans + (cnt * cnt) % mod) % mod;
			else ans = (ans + cnt) % mod;
		}
	}
	cout << ans << endl;
	return 0;
}

