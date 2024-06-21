#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)*2)
#define rs(x) ((x)*2+1)
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=1e6+5,Mod=998244353;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline void chmx(int &x,int y){(x<y)&&(x=y);}
inline void chmn(int &x,int y){(x>y)&&(x=y);}
//typedef __int128_t i128;
//i128 _base=1;
//inline int mol(int x){return x-Mod*(_base*x>>64);}
//inline void Add(int &x,int y){x=mol(x+y+Mod);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return f?-x:x;
}
inline int ksm(int a,int b){int res=1;while(b){if(b&1)res=res*a%Mod;a=a*a%Mod;b>>=1;}return res;}
int n,m,s,t;
int x[N],y[N];
int p,fm;
bool vis[N];
int in[N],out[N];
vector<int>q[N];
inline bool topo(){
	queue<int>Q;
	int k=0;
	if(in[s]!=0) return 0;
	if(out[t]!=0) return 0;
	For(i,1,n){
		if(vis[i]) continue;
		if(in[i]==0&&i!=s) return 0;
		if(out[i]==0&&i!=t) return 0;
	}

	For(i,1,n){
		if(!vis[i]) k++;
		if(in[i]==0&&!vis[i]){
			Q.push(i);
		}
	}
	int res=0;
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		res++;
		for(auto v:q[u]){
			if(!(--in[v])&&!vis[v]) Q.push(v);
		}
	}
	return (res==k);
}
inline int bian(int tot){
	For(i,0,(1<<tot)-1){
		For(j,1,n) q[j].clear(),in[j]=0,out[j]=0;
		For(j,1,tot){
			if(i&(1<<(j-1)))
				q[x[j]].push_back(y[j]),in[y[j]]++,out[x[j]]++;
			else q[y[j]].push_back(x[j]),in[x[j]]++,out[y[j]]++;
		}
		if(topo())return i;
	}
	return 0;
}
int U,V,ED;
inline void solve1(){
	bool flag=0;
	For(i,1,n){
		For(j,1,n){
			x[m+1]=i;
			y[m+1]=j;
			int k=bian(m+1);
			p+=(bool)(k);
			if(!flag&&k){
				flag=1;
				U=i;V=j;
				ED=k;
			}
		}
	}
}
inline void solve2(){
	int ans=1e16,p=0;
	For(i,0,(1<<n)-1){
		int res=0;
		bool flg=0;
		For(j,1,n){
			if(i&(1<<(j-1))){
				vis[j]=1;res++;
				if(j==s||j==t) flg=1;
			}
			else vis[j]=0;
		}
		if(flg) continue;
		if(!bian(m)){
			continue;
		}
		if(ans>res){
			ans=res;
			p=i;
		}
	}
	printf("%lld\n",ans);
	For(j,1,n){
		if(p&(1<<(j-1))) printf("%lld ",j);
	}
}
inline void solve(){
	n=read(),m=read(),s=read(),t=read();
	fm=ksm(n*n,Mod-2);
	For(i,1,m) x[i]=read(),y[i]=read();
	solve1();
	printf("%lld\n",p*fm%Mod);
	if(p){
		if(ED&(1<<m))cout<<U<<" "<<V<<endl;
		else cout<<V<<" "<<U<<endl;
		For(i,1,m){
			if(ED&(1<<(i-1))) printf("0");
			else printf("1");
		}
		return;
	}
	solve2();
}
signed main(){
	//_base=(_base<<64)/Mod;
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(0); cout.tie(0);
	int T=1;
	while(T--){solve();}
#ifdef LOCAL
    Debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}
