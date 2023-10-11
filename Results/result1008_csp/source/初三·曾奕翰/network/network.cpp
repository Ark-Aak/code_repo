#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,Q;
int a[N],tot,g[N],st[N][21],lg[N],p[N];
vector<int>q[N];
bool flag=1;
signed main() {
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d%d",&n,&Q);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		q[u].push_back(v);
		q[v].push_back(u);
		p[u]++;
		p[v]++;
		if(p[u]>2||p[v]>2) flag=0;
	}
	if(flag==1){
		for(int i=1;i<=n;i++){
			if(p[i]==1){
				a[++tot]=i;
				break;
			}
		}
		g[a[1]]=1;
		int now=a[1],fa=0;
		while(tot<n){
			for(auto v:q[now]){
				if(fa!=v) a[++tot]=v;
			}
			fa=now;
			now=a[tot];
			g[a[tot]]=tot;
		}
		for(int i=2;i<=n;i++){
			lg[i]=lg[i/2]+1;
		}
		for(int i=1;i<=n;i++){
			st[i][0]=a[i];
		}
		for(int i=1;i<=20;i++){
			for(int j=1;j<=n;j++){
				st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
			}
		}
		int l=n,r=0;
		string S;
		int x;
		while(Q--){
			cin>>S;
			scanf("%d",&x);
			if(S[0]=='J'){
				l=min(l,g[x]);
				r=max(r,g[x]);
			}else{
				int ll=min(l,x),rr=max(r,x);
				int lgg=lg[rr-ll+1]-1;
				printf("%d\n",min(st[ll][lgg],st[rr-(1<<lgg)][lgg]));
			}
		}
		return 0;
	}
	return 0;
}//ÒªÓÃprintf£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡

