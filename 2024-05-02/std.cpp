
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
const int block=900;
const int B=10000;
const int INF=(1e9)+10;
int n,m,tot,head[maxn],nxt[maxn],to[maxn];
int q,x[maxn],y[maxn],op[maxn];
bitset<B+100> dp[maxn];
int f[maxn/block+10][maxn];
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
int bel[maxn],cnt,vis[maxn],top,st[maxn],lst[maxn];
int L,R,ans[maxn],res,l,r;
void dfs(int u,int *d,int id) {
	if (vis[u]==tot) return;
	vis[u]=tot;
	d[u]=y[id],lst[u]=id;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		dfs(v,d,id);
	}
}
bool VIS[maxn];
int val[maxn];
void init(int u) {
	if (VIS[u]) return; VIS[u]=1;
	dp[u].reset();
	if (L<=u&&u<=R) dp[u][u-L+1]=1;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		init(v);
		dp[u]|=dp[v];
	}
}
bool cmp(int a,int b) { return y[a]<y[b]; }
int main() {
	freopen("dag.in","r",stdin);
	freopen("dag.out","w",stdout);
	read(n),read(m),read(q);
	while (m--) { int x,y; read(x),read(y); add(x,y); }
	tot=0;
	for (int i=1;i<=q;i++) {
		read(op[i]),read(x[i]);
		if (op[i]<3) read(y[i]);
	}
	for (int i=1;i<=q;i+=block) {
		cnt++;
		for (int j=1;j<=n;j++) f[cnt][j]=INF;
		top=0;
		for (int j=i;j<=min(q,i+block-1);j++) {
			bel[j]=cnt;
			if (op[j]==2) st[++top]=j;
		}
		sort(st+1,st+top+1,cmp);
		tot++;
		for (int j=1;j<=top;j++) {
			dfs(x[st[j]],f[cnt],st[j]);
		}
	}
	for (L=1;L<=n;L+=B) {
		top=0;
		R=min(n,L+B-1);
		for (int i=1;i<=n;i++) val[i]=lst[i]=VIS[i]=0;
		for (int i=1;i<=n;i++) init(i);
		for (int i=1;i<=q;i++) {
			if (op[i]==1) {
				st[++top]=i;
				if (top==block) {
					tot++;
					while (top) dfs(x[st[top]],val,st[top]),top--;
				}
			} else if (op[i]==3&&L<=x[i]&&x[i]<=R) {
				res=val[x[i]]; l=lst[x[i]]+1; r=i-1;
				for (int j=top;j>=1;j--) if (dp[x[st[j]]][x[i]-L+1]) { l=st[j]+1; res=y[st[j]]; break; }
				if (l<=r) {
					if (bel[l]==bel[r]) {
						for (int j=l;j<=r;j++) if (op[j]==2&&dp[x[j]][x[i]-L+1]) res=min(res,y[j]);
					} else {
						for (int j=l;j<=r&&bel[j]==bel[l];j++) if (op[j]==2&&dp[x[j]][x[i]-L+1]) res=min(res,y[j]);
						for (int j=r;j>=l&&bel[j]==bel[r];j--) if (op[j]==2&&dp[x[j]][x[i]-L+1]) res=min(res,y[j]);
						for (int j=bel[l]+1;j<bel[r];j++) res=min(res,f[j][x[i]]);
					}
				}
				ans[i]=res;
			}
		}
	}
	for (int i=1;i<=q;i++) if (op[i]==3) {
		printf("%d\n",ans[i]);
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?

  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?

  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?

  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/
