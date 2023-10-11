#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=255;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int T,s[N][N],tp[N],s2[N][N],tp2[N];
bool over,vis[N];
int head[N],to[N<<1],nxt[N<<1],tot;
void add(int u,int v){to[++tot]=v,nxt[tot]=head[u],head[u]=tot;}
void clean(){
	tot=0;
	memset(tp,0,sizeof tp);
	memset(head,0,sizeof head);
	memset(to,0,sizeof to);
	memset(nxt,0,sizeof nxt);
}
void dfs(int u,int f,int t,int id){
	if(u==t){
		over=1;
		s[id][++tp[id]]=u;
		return;
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v!=f) dfs(v,u,t,id);
		if(over){
			s[id][++tp[id]]=u;
			return;
		} 
	}
	return;
}
signed main(){
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	T=read();
	while(T--){
		clean();
		int n=read();
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			add(u,v);
			add(v,u);
		}
		int m=read();
		for(int i=1;i<=m;i++){
			int p=read(),q=read();
			over=0;
			dfs(p,-1,q,i);
		}	
		bool ans=1;
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				int res=0;
				for(int k=2;k<tp[i];k++)
					if(s[i][k]==s[j][1]) res++;
				for(int k=2;k<tp[j];k++)
					if(s[j][k]==s[i][1]) res++;	
				if(res==2){
					ans=0;
					j=i=m+1;
				}			
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++) vis[j]=0;
			for(int j=2;j<tp[i];j++) vis[s[i][j]]=1;
			for(int j=1;j<=m;j++){
				if(i==j) continue;
				int sum=0;
				for(int k=1;k<=tp[j];k++)
					if(vis[s[j][k]]) sum++;
				if(sum==tp[j]){
					ans=0;
					j=i=m+1;
				}
 			}
		}		
		if(ans) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}
