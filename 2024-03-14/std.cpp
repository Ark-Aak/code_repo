#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)*2)
#define rs(x) ((x)*2+1)
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
#define Copy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=1e6+5,Mod=998244353;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline void chmx(int &x,int y){(x<y)&&(x=y);}
inline void chmn(int &x,int y){(x>y)&&(x=y);}
//inline void Add(int &x,int y){(x=x+y+Mod)%Mod;}
typedef __int128_t i128;
i128 _base=1;
inline int mol(int x){return x-Mod*(_base*x>>64);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return f?-x:x;
}
int n,m,k;
int ans[N];
int sum=0;
struct KMP{
	int nxt[N];
	int a[N],v[N];
	int gg[N];
	char s[N],t[N],p[N];
	inline int init(){
		int j=0;
		For(i,2,k){
			while(j&&p[j+1]!=p[i]) j=nxt[j];
			if(p[j+1]==p[i]) j++;
			nxt[i]=j;
		}
		j=0;
		For(i,1,m){
			while (j==k||(j&&p[j+1]!=t[i])) j=nxt[j];
			if(p[j+1]==t[i])j++;
			if(j==k)++sum;
		}
		return j;
	}
	inline void cal(int o){
		For(i,1,k) a[i]=a[nxt[i]]+v[k-i];
		//~ For(i,1,k) cout<<a[i]<<" ";
		//~ cout<<endl;
		int j=0,res=0;
		For(i,0,n){
			while (j==k||(j&&p[j+1]!=s[i])) j=nxt[j];
			if(p[j+1]==s[i])j++;
			if(j==k) ++res;
			gg[i]=j;
			if(o==0)ans[i]+=res+a[j];
			else ans[n-i]+=res+a[j];
		}
		//~ cout<<endl;
	}
}A,B;
char s[N],t[N],p[N];
int tr[N];
int nxt[N];
int dfn[N],ed[N],cnt;
bool vis[N];
vector<int>q1[N],q2[N];
vector<pair<int,int> > e[N];
inline int lowbit(int x){return x&(-x);}
inline void add(int x,int y){while(x<=cnt){tr[x]+=y;x+=lowbit(x);}}
inline int qry(int x){int res=0;while(x){res+=tr[x];x-=lowbit(x);}return res;}
void dfs(int x) {
	dfn[x]=++cnt;
	for(auto y:q2[x]) dfs(y);
	ed[x]=cnt;
}
inline void dfs2(int x){
bool flag=0;
	//~ cout<<x<<" ";
	if(x&&vis[x+m]&&k-(x+m)){
		//~ cout<<k-(x+m);
		//~ cout<<dfn[k-(x+m)]<<" "<<ed[k-(x+m)]<<" ";
		add(dfn[k-(x+m)],1);
		add(ed[k-(x+m)]+1,-1);flag=1;
	}
	for(auto E:e[x]) ans[E.second]+=qry(dfn[E.first]);
	for(auto y:q1[x])dfs2(y);
	if(flag){
		add(dfn[k-(x+m)],-1);
		add(ed[k-(x+m)]+1,1);
	}
}
signed main(){
	_base=(_base<<64)/Mod;
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(0); cout.tie(0);
	scanf("%s",s+1);
	scanf("%s",t+1);
	scanf("%s",p+1);
	n=strlen(s+1);m=strlen(t+1);k=strlen(p+1);
	Copy(A.s,s);Copy(A.t,t);Copy(A.p,p);
	reverse(s+1,s+n+1);
	reverse(t+1,t+m+1);
	reverse(p+1,p+k+1);
	Copy(B.s,s);Copy(B.t,t);Copy(B.p,p);
	//~ For(i,1,n) cout<<B.s[i];
	int ii=A.init(),jj=B.init();
	sum/=2;
	if(ii==k) ii=A.nxt[ii];
	while(ii){
		++B.v[ii];
		ii=A.nxt[ii];
	}
	if(jj==k) jj=B.nxt[jj];
	while(jj){
		++A.v[jj];
		jj=B.nxt[jj];
	}
	A.cal(0);B.cal(1);
	if(m<k){//´¦ÀíA+T+B
		int j=0;
		For(i,2,m){
			while(j&&A.t[j+1]!=A.t[i])j=nxt[j];
			if(A.t[j+1]==A.t[i])j++;
			nxt[i]=j;
		}
		j=0;
		For(i,1,k){
			while(j==m||(j&&A.t[j+1]!=A.p[i])) j=nxt[j];
			if(A.t[j+1]==A.p[i])j++;
			if(j==m) vis[i]=1;
		}
		For(i,1,k){
			q1[A.nxt[i]].push_back(i);
			q2[B.nxt[i]].push_back(i);
		}
		dfs(0);
		//~ For(i,0,k) cout<<dfn[i]<<" "<<ed[i]<<endl;
		For(i,0,n){
			int l=A.gg[i],r=B.gg[n-i];
			if(l&&r) e[l].push_back({r,i});
		}
		dfs2(0);
	}
	int l=0,r=0,maxx=0,num=0;
	For(i,0,n){
		if(ans[i]>maxx){
			l=i;r=i;
			maxx=ans[i];
			num=0;
		}
		if(ans[i]==maxx) num++,r=i;
		//~ cout<<ans[i]<<" ";
	}
	//~ if(maxx==0&&!sum) l=r=num=0;
	printf("%lld %lld %lld %lld\n",maxx+sum,num,l,r);
#ifdef LOCAL
    Debug("\nMy Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}
