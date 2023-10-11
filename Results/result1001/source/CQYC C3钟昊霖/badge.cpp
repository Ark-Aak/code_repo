#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=a;i<=b;i++)
#define ls(x) x<<1
#define rs(x) x<<1|1

const int N=5e5+5;

inline int read();

int n,m,Q,a[N],BL[N],Bl[N],Br[N],B[N];

int vis[N],vis1[N];

struct node{
	int l,r;
}z[N]; 

struct SegTree{
	int Tree[N<<2],tag[N<<2];
	void Merge(int x){
		Tree[x]=Tree[x<<1]+Tree[x<<1|1];
	}
	void Push_up(int x){
		if(tag[x]==0) return;
		tag[x<<1]=tag[x<<1|1]=1;
		Tree[x<<1|1]=0,Tree[x<<1]=0;
		tag[x]=0;
		return; 
	}
	void Update(int x,int l,int r,int L,int R,int y){
		if(l>L||r<L) return;
		if(l==r&&l==L){
			Tree[x]+=y;
			return;
		}
		Push_up(x);
		int mid = (l+r)>>1;
		Update(ls(x),l,mid,L,R,y),Update(rs(x),mid+1,r,L,R,y);
		Merge(x);
	}
	inline int Query(int x,int l,int r,int L,int R){
		Push_up(x);
		if(l>R||r<L) return 0;
		if(L<=l&&r<=R) return Tree[x];
		int mid =(l+r)>>1;
		return Query(ls(x),l,mid,L,R)+Query(rs(x),mid+1,r,L,R);
	}
	
}Tree;	

void Subtask1(){
	while(Q--){
		m=read();
		for(int i=1,u;i<=m;i++){u=read();Tree.Update(1,1,n,u,u,1);}
		int ans=0;
		F(i,1,n) ans=ans+(Tree.Query(1,1,n,z[i].l,z[i].r)&1);
		printf("%d\n",ans);
		Tree.tag[1]=1;
		Tree.Tree[1]=0;
	}	
}

int len;

bool cmp(node a,node b)
{
	if(a.l/len==b.l/len){
		if((a.l/len)&1) return a.r<b.r;
		else return a.r>b.r;
	}
	return a.l<b.l;
}

int ans1;

inline void Add(int x){//加点 
	ans1+=a[x];
}
inline void Add1(int x){//加块 
	ans1+=B[Bl[x]];
}
inline void Del(int x){//-点 
	ans1-=a[x];
}
inline void Del1(int x){//-块 
	ans1-=B[Bl[x]];
}

void Subtask2(){//Bl i的块的编号 Br  块是 i 的右端点  BL 左边 
	len=sqrt(n);
	memset(BL,0x3f,sizeof BL);
	F(i,1,n) Bl[i]=i/len+1,Br[Bl[i]]=i,BL[Bl[i]]=min(BL[Bl[i]],i); 
	sort(z+1,z+n+1,cmp);
	while(Q--){
	// vis 单块 i vis1 大块 i 
		m=read();
		for(int i=1,u;i<=m;i++){
			u=read();
			if(vis[u]!=Q) a[u]=0,a[u]++,vis[u]=Q;
			if(vis1[Bl[u]]!=Q) B[Bl[u]]=0,B[Bl[u]]++,vis1[Bl[u]]=Q;
		}
		int l=1,r=0;
		int ans=0;
		ans1=0;
		F(i,1,n){
			while(l<z[i].l)  {
				if(l!=BL[l]||Br[l]<z[i].l) Del(l++);
				if(l==BL[l]&&Br[l]<z[i].l){Del1(l),l=Br[l]+1;}
			}
			while(l>z[i].l){
				if(l!=Br[r]||Bl[l]<z[i].l) Add(--l);
				if(l==Br[r]&&Bl[l]>z[i].l) l=Bl[i]-1,Add1(l); 
			}
			while(r<z[i].r)  {
				if(r!=BL[r]||Br[r]<z[i].r) Add(++r);
				if(r==BL[r]&&Br[r]<z[i].r){r=Br[r]+1;Add(r);}
			}
			while(r>z[i].r){
				if(r!=Br[r]||Bl[l]<z[i].r) Del(r--);
				if(r==Br[r]&&Bl[l]>z[i].r) Del1(r),r=Bl[r]-1; 
			}
			if(ans1&1) ans++;
		}
		cout<<ans<<endl;		
	}
}

signed main(){
	freopen("badge.in","r",stdin);
	freopen("badge.out","w",stdout);
	n=read(),Q=read();
	F(i,1,n) z[i].l=read(),z[i].r=read();
  	if(n<=200000)Subtask1();
  	else Subtask2();
	return 0;
}

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f*=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}

