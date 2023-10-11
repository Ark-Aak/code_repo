#include<bits/stdc++.h>
#define int long long
#define ll long long
#define mid ((l+r)>>1)
#define FOR(i,a,b) for(ll i=(a); i<=(b); ++i)
#define ROF(i,a,b) for(ll i=(a); i>=(b); --i)
#define modj(x) ((x)-=((x)>=MOD)?MOD:0)
#define qmin(x,y) ((x)=min((x),(y)))
#define qmax(x,y) ((x)=max((x),(y)))
using namespace std;
const int MAXN=6e4;
inline ll read(){
	ll t=0,f=0;char v=getchar();
	while(!isdigit(v))f|=(v=='-'),v=getchar();
	while(isdigit(v))t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
inline void write(ll x){
	if(x<0){x*=-1; putchar('-');}
	if(x>9) write(x/10);
	putchar(x%10+'0');
	return;
}
int n,k,maxx=1e16;
int a[MAXN];
char s[105][105];
vector<int>q[MAXN];
int jy[MAXN];
int clk;
bool vis[MAXN];
void dfs(int x,int now,int jz){
//	cout<<x<<" "<<now<<" "<<jz<<endl;
	if(clk>=10000000) return;
	if(jz>=maxx) return;
	if(now==n){
		clk++;
		maxx=min(maxx,jz);
		return;
	}
	clk++;
	if(jy[now]<=jz) return;
	clk++;
	jy[now]=jz;
	for(int i=k;i>=1;i--)
		if(s[x][i]=='1'){
			clk++;
			for(auto j:q[i]){
				if(vis[j]) continue;
				vis[j]=1;
				clk++;
				dfs(i,j,jz+abs(now-j));
				clk++;
				vis[j]=0;
			}
		}
}
void dfs2(int x,int now,int jz){
//	cout<<x<<" "<<now<<" "<<jz<<endl;
	if(clk>=80000) return;
	if(jz>=maxx) return;
	if(now==n){
		clk++;
		maxx=min(maxx,jz);
		return;
	}
	clk++;
	if(jy[now]<=jz) return;
	clk++;
	jy[now]=jz;
	for(int i=1;i<=k;i++)
		if(s[x][i]=='1'){
			clk++;
			for(auto j:q[i]){
				if(vis[j]) continue;
				vis[j]=1;
				clk++;
				dfs(i,j,jz+abs(now-j));
				clk++;
				vis[j]=0;
			}
		}
}
signed main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	int T=1;
	while(T--){
		n=read();k=read();
		FOR(i,1,n) a[i]=read(),q[a[i]].push_back(i),clk++;
		FOR(i,1,k)
			FOR(j,1,k)
				cin>>s[i][j],clk++;
		memset(jy,0x3f,sizeof(jy));
		if(s[a[1]][a[n]]=='1'){
			cout<<n-1;
			return 0;
		}
		dfs(a[1],1,0);
		dfs2(a[1],1,0);
		if(maxx==1e16)cout<<-1;
		else cout<<maxx;
	}
	return 0;
}
/*
5 4
1 4 2 3 4
1010
0001
0110
0100
*/
