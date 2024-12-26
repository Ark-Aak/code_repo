#include<bits/stdc++.h>
using namespace std;
namespace IO{
    char buff[1<<21],*p1=buff,*p2=buff;
    char getch(){
        return p1==p2&&(p2=((p1=buff)+fread(buff,1,1<<21,stdin)),p1==p2)?EOF:*p1++;
    }
    template<typename T>
    void read(T &x){
        char ch=getch();int fl=1;x=0;
        while(ch>'9'||ch<'0'){if(ch=='-')fl=-1;ch=getch();}
        while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getch();}
        x*=fl;
    }
    template<typename T,typename ...Args>
    void read(T &x,Args& ...args){
        read(x);read(args...);
    }
    char obuf[1<<21],*p3=obuf;
    void putch(char ch){
        if(p3-obuf<(1<<21))*p3++=ch;
        else fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=ch;
    }
    char ch[100];
    template<typename T>
    void write(T x){
        if(!x)return putch('0');
        if(x<0)putch('-'),x*=-1;
        int top=0;
        while(x)ch[++top]=x%10+48,x/=10;
        while(top)putch(ch[top]),top--;
    }
    template<typename T,typename ...Args>
    void write(T x,Args ...args){
        write(x);write(args...);
    }
    void flush(){fwrite(obuf,p3-obuf,1,stdout);}
}
#define ll long long
#define il inline 
#define rg register
#define pi pair<Line,ll> 
#define Inf 1e18
#define ls (x<<1)
#define rs ((x<<1)|1)
#define mid ((tree[x].l+tree[x].r)>>1)
bool st;
const int N=2e5+5;
struct Tree{
	struct Line{
		ll k,b;
		il ll f(ll x){return x*k+b;}
	};
	il pi calc(Line A,Line B){
		if(A.b<B.b)swap(A,B);
		return {A,(A.k<B.k)?(A.b-B.b)/(B.k-A.k):Inf};
	}
	struct node{
		int l,r;
		Line line;
		ll Nxt,tag;
	}tree[N<<2];
	il void update(int x){
		rg pi tmp=calc(tree[ls].line,tree[rs].line);
		tree[x].Nxt=min(tmp.second,min(tree[ls].Nxt,tree[rs].Nxt));
		tree[x].line=tmp.first;	
		return;
	}
	il void add(int x,ll w){
		tree[x].tag+=w;
		tree[x].line.b+=tree[x].line.k*w;
		tree[x].Nxt-=w;
		return;
	}
	il void push_down(int x){
		if(tree[x].tag)
			add(ls,tree[x].tag),
			add(rs,tree[x].tag),
			tree[x].tag=0;
		return;
	}
	il void build(int x,int l,int r,ll *k,ll *X){
		tree[x]={l,r};
		if(l==r){
			tree[x].line={k[l],k[l]*X[l]};
			tree[x].Nxt=Inf;
			return;
		}
		build(ls,l,mid,k,X);
		build(rs,mid+1,r,k,X);
		update(x);
		return; 
	}
	il void modify(int x,int l,int r,int w){
		if(l<=tree[x].l&&tree[x].r<=r&&w<=tree[x].Nxt)return add(x,w);
		push_down(x);
		if(l<=mid)modify(ls,l,r,w);
		if(r>mid)modify(rs,l,r,w);
		update(x);
		return;
	}
	il ll query(int x,int l,int r){
		if(l<=tree[x].l&&tree[x].r<=r)return tree[x].line.b;
		rg ll res=-Inf;
		push_down(x);
		if(l<=mid)res=max(res,query(ls,l,r));
		if(r>mid)res=max(res,query(rs,l,r));
		return res;
	}
}T1,T2;
using namespace IO;
int n,q;
ll a[N],b[N];
ll A[N],B[N];
int dfn[N],siz[N],tot;
vector<int>to[N];
il void dfs(int x,int fa){
	dfn[x]=++tot,siz[x]=1;
	a[x]+=a[fa],b[x]+=b[fa];
	for(auto y:to[x])dfs(y,x),siz[x]+=siz[y];
}
bool en;
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout); 
//	cerr<<(&en-&st)/1024/1024;
	read(n,q);
	for(int i=2;i<=n;i++){
		int x;
		read(x);
		to[x].push_back(i);
	}
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)read(b[i]);
	dfs(1,0);
	for(int i=1;i<=n;i++)b[i]=max(b[i],-b[i]);
	for(int i=1;i<=n;i++)A[dfn[i]]=a[i];
	for(int i=1;i<=n;i++)B[dfn[i]]=b[i];
	T1.build(1,1,n,B,A);
	for(int i=1;i<=n;i++)B[i]=-B[i];
	T2.build(1,1,n,B,A);
	while(q--){
		int ops;
		read(ops);
		if(ops==1){
			int x,w;
			read(x,w);
			T1.modify(1,dfn[x],dfn[x]+siz[x]-1,w);
			T2.modify(1,dfn[x],dfn[x]+siz[x]-1,w);
		}else{
			int x;
			read(x);
			write(max(T1.query(1,dfn[x],dfn[x]+siz[x]-1),T2.query(1,dfn[x],dfn[x]+siz[x]-1))),putch('\n');	
		}
	}
	flush();
	return 0;
}
