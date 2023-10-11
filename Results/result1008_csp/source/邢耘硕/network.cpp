#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector <int> e[N];
int n,de[N],q,f[N][20],mn[N][20],st[N][20],u,v,logn,len,jc[N],mnn=1145141919,sz[N],mr=-1145141919,ml=1145141919;
bool vis[N];
void dfs(int u,int fa){
	sz[u]=1;
	for(int i = 0;i < e[u].size();i++){
		int v=e[u][i];
		if(v==fa)continue;
		de[v]=de[u]+1;
		f[v][0]=mn[v][0]=u;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
int lca(int x,int y){
	if(de[x]<de[y])swap(x,y);
	int ans1=1145141919,ans2=1145141919;
	for(int i = 0,p=de[x]-de[y];p;p>>=1,i++){
		if(p&1){
			ans1=min(ans1,mn[x][i]);
			x=f[x][i];
		}
	}
	if(x==y)return ans1;
	for(int i =logn;i >= 0;i--){
		if(f[x][i]!=f[y][i]){
			ans1=min(ans1,mn[x][i]);
			x=f[x][i];
			ans2=min(ans2,mn[y][i]);
			y=f[y][i];
		}
	}
	return min(ans1,min(ans2,min(mn[x][0],mn[y][0])));
}
char x[10];
bool check(){
	for(int i = 1;i <= n;i++)
		if(sz[i]!=n-i+1)
			return false;
	return true;
}
void work(int x){
	int temp=mnn;
	for(int i = 1;i <= len;i++){
		//cout << "work" << "\n";
		temp=min(temp,lca(x,jc[i]));
	}
	cout << temp << "\n";
}
void init(){
	for(int i = 1;i <= n;i++)st[i][0]=i;
	for(int j = 1;j <= logn;j++)
		for(int i = 1;i+(1<<j)-1<=n;j++)
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int query(int l,int r){
	int logx=log2(r-l+1);
	return min(st[l][logx],st[r-(1<<logx)+1][logx]);
}
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	memset(mn,0x3f,sizeof(mn));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	logn=log2(n);
	for(int i = 1;i < n;i++){
		cin>> u >> v;
		e[u].push_back(v);
		e[v].push_back(u); 
	}
	dfs(1,0);
	bool bj=check();
	for(int j = 1;j <= logn;j++){
		for(int i = 1;i <= n;i++){
			f[i][j]=f[f[i][j-1]][j-1];
			mn[i][j]=min(mn[i][j-1],mn[f[i][j-1]][j-1]);
		}
	}
	init();
	for(int i = 1;i <= q;i++){
		int val,op;
		cin >> x; 
		if(x[0]=='J')op=1;
		else op=0;
		cin >> val;
		if(op==1){
			if(!vis[val]){
				vis[val]=1;
				jc[++len]=val;
				mnn=min(val,mnn);
				ml=min(ml,val);
				mr=max(mr,val);
			}
		}
		else{
			if(!bj)work(val);
			else cout << query(min(ml,val),max(mr,val)) << "\n";
		} 
	}
	return 0;
} 
