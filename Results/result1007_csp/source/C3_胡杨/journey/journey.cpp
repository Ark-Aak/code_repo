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
int n, m, q;
int l, r, s, t, tt;
vector<pair<int,int> > a[1010];
int vis[1010];
void dfs(int x,int tim) {
	vis[x] = 1;
	if(tim > r) return ;
    if(x == t && tim == r){
    	tt = 1;
    	return ;
	}
	if(tt == 1 || tim >= t) return ;
	for(int i = 0 ; i < a[x].size() ; i++){
		int to = a[x][i].first;
		if(!vis[to] && a[x][i].second >= tim) dfs(to, a[x][i].second);
	}
}
signed main() {
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	read(n);
	read(m);
	read(q);
	for(int i = 1 ; i <= m ; i++) {
		int u, v;
		read(u);
		read(v);
		a[u].push_back(make_pair(v,i));
		a[v].push_back(make_pair(u,i));
	}
	while(q--) {
		read(l);read(r);read(s);read(t);
		if(l == r) {
			if(s == t) cout << "Yes\n";
			else {
				int tt = 0;
				for(int i = 0 ; i < a[s].size() ; i++) {
					if(a[s][i].first == t && a[s][i].second == r) {
						tt = 1;
						break;
					}
				}
				if(tt == 1) cout << "Yes\n";
				else cout << "No\n";
			}
			continue;
		}
		tt = 0;
		memset(vis,0,sizeof vis);
		dfs(s,l);
		if(tt) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
