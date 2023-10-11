#include<bits/stdc++.h>
using namespace std;
const int N=1000,D=N+5;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while((c<'0'||'9'<c)&&c^'-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
int head[N],to[N*72],nxt[N*72],tot;
inline void add(int x,int y){
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int q,k,n,s[N],cnt,ans[N][D+5],dis[N];
bool e[N][N];
inline void Add(int s,int x){
	int b[20],cn=0;
	while(x) b[++cn]=x%10,x/=10;
	for(int i=1;i<=cn;i++)
	for(int j=i+1;j<=cn;j++)
	for(int k=j+1;k<=cn;k++)
		if(b[i]&&b[j]&&b[k]){
			e[s][b[i]*100+b[j]*10+b[k]]=1;
			e[s][b[i]*100+b[k]*10+b[j]]=1;
			e[s][b[j]*100+b[i]*10+b[k]]=1;
			e[s][b[j]*100+b[k]*10+b[i]]=1;
			e[s][b[k]*100+b[i]*10+b[j]]=1;
			e[s][b[k]*100+b[j]*10+b[i]]=1;
		}
}
inline bool san(int x){
	while(x){
		if(x%10==0) return 0;
		x/=10;
	}
	return 1;
}
queue<int> Q;
void bfs(int st){
	for(int i=1;i<=cnt;i++) dis[s[i]]=-1;
	dis[st]=0;
	Q.push(st);int u;
	while(!Q.empty()){
		u=Q.front(),Q.pop();
		for(int o=head[u],v;o;o=nxt[o]){
			v=to[o];
			if(dis[v]==-1){
				dis[v]=dis[u]+1;
				Q.push(v);
			}
		}
	}
	for(int i=1;i<=cnt;i++)
		if(dis[s[i]]!=-1) ++ans[st][dis[s[i]]];
	for(int i=1;i<=D;i++) ans[st][i]+=ans[st][i-1];
}
int main(){
	freopen("device.in","r",stdin);
	freopen("device.out","w",stdout);
	for(int i=111;i<=999;i++){
		if(!san(i)) continue;
		s[++cnt]=i;
		Add(i,i*13*11*7);
	}
	for(int i=1;i<=cnt;i++)
	for(int j=1;j<=cnt;j++)
		if(e[s[i]][s[j]]) add(s[i],s[j]);
	for(int i=1;i<=cnt;i++) bfs(s[i]);
	read(q);
	while(q--){
		read(k),read(n);
		printf("%d\n",ans[k][min(n,D)]);
	}
	return 0;
}
