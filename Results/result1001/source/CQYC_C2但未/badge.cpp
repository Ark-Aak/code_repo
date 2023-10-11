#include<bits/stdc++.h>
using namespace std;
const int Maxn=5e5+5;
int n,q;
int cnt,cnt2;
int dfn[Maxn*3];//30
struct node{int l,r,ls,rs;}s[Maxn*3];
bool cmp(node a,node b){return a.l==b.l?a.r>b.r:a.l<b.l;}
int f[Maxn*3],si[Maxn*3];
inline void read(int&x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
void dfs(int u,int v){
	if(!u)return;
	f[u]=v;
	if(u<=n&&!dfn[u])dfn[u]=++cnt2;
	if(u<=n)si[u]=1;
	dfs(s[u].ls,u);
	dfs(s[u].rs,u);
	si[u]+=si[s[u].ls]+si[s[u].rs];
}
struct Tree{
	int ls,rs,data;
}t[Maxn<<1];
int cnt3=0;
int build(int l,int r){
	int x=++cnt3;
	if(l==r)return x;
	int mid=l+r>>1;
	t[x].ls=build(l,mid);
	t[x].rs=build(mid+1,r);
}
int add[Maxn<<1];
inline void spread(int x,int l,int r){
	if(!add[x])return;
	int mid=l+r>>1;
	t[t[x].ls].data=mid-l+1-t[t[x].ls].data;
	t[t[x].rs].data=r-mid-t[t[x].rs].data;
	add[t[x].ls]^=1;
	add[t[x].rs]^=1;
	add[x]=0;
}
inline void update(int x){
	t[x].data=t[t[x].ls].data+t[t[x].rs].data;
}
void change(int x,int l,int r,int L,int R){
	if(L<=l&&r<=R){t[x].data=r-l+1-t[x].data;add[x]^=1;return;}
	int mid=l+r>>1;
	spread(x,l,r);
	if(L<=mid)change(t[x].ls,l,mid,L,R);
	if(mid<R)change(t[x].rs,mid+1,r,L,R);
	update(x);
}
vector<int>vis[Maxn];
int x[Maxn];
int ans[Maxn];
inline void solve40(){
	for(int i=1;i<=n;i++)
		for(int j=s[i].l;j<=s[i].r;j++)
			vis[j].push_back(i);
	while(q--){
		int m,cnt=0;
		read(m);
		for(int k=1;k<=m;k++){
			read(x[k]);
			for(int i=0;i<vis[x[k]].size();i++){
				ans[vis[x[k]][i]]++;
				if(ans[vis[x[k]][i]]&1)cnt++;
				else cnt--;
			}
		}
		printf("%d\n",cnt);
		for(int k=1;k<=m;k++)
			for(int i=0;i<vis[x[k]].size();i++)
				ans[vis[x[k]][i]]=0;
	}
} 
int main(){
	freopen("badge.in","r",stdin);
	freopen("badge.out","w",stdout);
	read(n);read(q);
	for(int i=1;i<=n;i++)
		read(s[i].l),read(s[i].r);
	//sort(s+1,s+1+n,cmp);
	int root=build(1,n);
	solve40();
	return 0;
}
	//int m=n,w=1;
//	while(m>1){
//		int cnt1=cnt;
//		for(int i=0;i<m-1;i++){
//			if(s[i+w].r>=s[i+w+1].l){
//				s[++cnt].l=s[i+1+w].l;
//				s[cnt].r=s[i+w].r;
//				s[cnt].ls=i+w;s[cnt].rs=i+w+1;
//			}
//		}
//		m=cnt-cnt1;w=cnt1+1;
//	}
