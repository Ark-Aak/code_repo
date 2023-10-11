#include<bits/stdc++.h>
using namespace std;

#define F(i, a, b) for(int i = a; i <= b; i++)

inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while (c <= '9' && c>='0') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

const int N=2e5+5;

int n, Q, f[N], head[N], nxt[N], to[N], tot, dep[N], x, y, a[N], opt;

inline void AddEdge(int u, int v) {
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}

inline void dfs(int u,int v) {
	//cout << u <<endl;
	f[u] = v;
	dep[u] = dep[v] + 1;
	for (int i = head[u]; i; i = nxt[i]) {
		if(to[i]==f[u]) continue;
		dfs(to[i],u);
	}
}

signed main() {
	freopen("loser.in","r",stdin);
	freopen("loser.out","w",stdout);
	n=read(),Q=read();
	for (int i = 1, u, v; i < n; i++) {
		u=read(), v=read();
		AddEdge(u,v);
		AddEdge(v,u);
	}
	dfs(1,0);
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	while(Q--) {
		opt = read(), x = read(), y = read();
		int x1 = x, y1 = y;
		if ( opt == 1 ) {
			while(x!=y) {
				if(dep[x]<dep[y]) swap(x,y);
				if(a[x]==0) a[x]=1;
				else a[x]=0;
				x=f[x];
			}
			a[x]=(!a[x]);
		//	a[f[x]]=!a[f[x]];
	//		F(i,1,n) cout<<a[i]<<" ";
	//		cout<<endl;
		} else {
			stack<int> s,ans;
			queue<int> q;
			int Ans=0;
			while(x!=y) {
				if(dep[x]<dep[y]) {
					s.push(a[y]);
					y=f[y];
				} else {
					q.push(a[x]);
					x=f[x];
				}
			}
			q.push(a[x]);
			while(!q.empty()) {
			//	cout<<q.front();
				int yy = q.front();
				q.pop();
				if(!ans.size()) {
					ans.push(yy);
					continue;
				} else if(yy==1&&ans.top()==0) ans.pop(),Ans++;
				else ans.push(yy);
				
			}
			while(!s.empty()){
			//	cout<<s.top()<<endl;
				int yy=s.top();
				s.pop();
				if(!ans.size()){
					ans.push(yy);
					continue;
				}else if(yy==1&&ans.top()==0) ans.pop(),Ans++;
				else ans.push(yy);
			}
			while(!ans.empty()) ans.pop();
			cout<<Ans*2<<endl;
		}
	}
	return 0;
}
