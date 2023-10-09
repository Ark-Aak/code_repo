#include<bits/stdc++.h>

using namespace std;
#define int long long
#define F(i,a,b) for(int i=a;i<=b;i++)

const int Maxn=5e5+5;

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f*=-1;c=getchar();}
	while(c<='9'&&c>='0'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

int len,n,m,a[Maxn],TreeMax[4*Maxn],TreeMin[4*Maxn],ans[Maxn],tot1,tot2,opt,x,y,vis[70*Maxn],Ans;

inline void Solve(int num) {
	TreeMax[num]=max(TreeMax[num<<1],TreeMax[num<<1|1]);
	TreeMin[num]=min(TreeMin[num<<1],TreeMin[num<<1|1]);
	return;
}

inline void Build(int num,int l,int r) {
	if(l==r) {
		TreeMin[num]=a[l];
		TreeMax[num]=a[l];
		return;
	}
	int mid = (l + r) >>1;
	Build(num<<1,l,mid);
	Build(num<<1|1,mid+1,r);
	Solve(num);
}

struct node {
	int l,r,id,t,cnt;
} Q[Maxn],R[Maxn];

void Add(int num){
    if(vis[num]==0) Ans++;
    vis[num]++;
    return;
}
void Del(int num){
    if(vis[num]==1) Ans--;
    vis[num]--;
    return;
}
void Change(int w,int t){
    if(Q[w].l<=R[t].l&&R[t].l<=Q[w].r){
        Del(a[R[t].l]);
        Add(R[t].r);
    }
    swap(a[R[t].l],R[t].r);
    return;
}


inline void Modify(int num,int l,int r,int x,int y) {
	if(r<x||l>x) return;
	if(l==r&&x==l) {
		TreeMax[num]=TreeMin[num]=y;
		return;
	}
	int mid = (l+r) >>1;
	Modify(num<<1,l,mid,x,y);
	Modify(num<<1|1,mid+1,r,x,y);
	Solve(num);
}

inline int QueryMax(int num,int l,int r,int l1,int r1) {
	if(l1 <= l && r <= r1) return TreeMax[num];
	if (l1 > r || r1 < l) return -INT_MAX;
	int mid = (l+r) >>1;
	return max(QueryMax(num<<1,l,mid,l1,r1),QueryMax(num<<1|1,mid+1,r,l1,r1));
}

inline int QueryMin(int num,int l,int r,int l1,int r1) {
	if(l1 <= l && r <= r1) return TreeMin[num];
	if(l1 > r || r1 < l) return INT_MAX;
	int mid=(l+r)>>1;
	return min(QueryMin((num<<1),l,mid,l1,r1),QueryMin(num<<1|1,mid+1,r,l1,r1));
}
bool cmp (node a,node b) {
return a.l / len == b.l / len ? a.r / len == b.r / len ? a.t < b.t : a.r < b.r : a.l < b.l;
}

signed main() {
// 	freopen("P3792_7.in","r",stdin);
// 	freopen("P3792.out","w",stdout);
	n=read(),m=read();
	len=sqrt(n);
	F(i,1,n) a[i]=read();
	Build(1,1,n);
	F(i,1,m) {
		opt=read(),x=read(),y=read();
		if(opt==1) {
			tot2++;
			R[tot2].l=x;
			R[tot2].r=y;
			Modify(1,1,n,x,y);
		}
		if(opt==2) {
			tot1++;
			Q[tot1].id=tot1;
			Q[tot1].l=x,Q[tot1].r=y;
			Q[tot1].t=tot2;
			Q[tot1].cnt=QueryMax(1,1,n,x,y)-QueryMin(1,1,n,x,y)+1;
		}
	}
	sort(Q+1,Q+tot1+1,cmp);
	int curl=1,curr=0,curt=0;
	F(i,1,tot1) {
		int l1=Q[i].l,r1=Q[i].r,t1=Q[i].t;
		while(curl>l1) Add(a[--curl]);
	//	cout<<"Ok1"<<curl<<" "<<l1<<endl;
		while(curl<l1) Del(a[curl++]);
		while(curr>r1) Del(a[curr--]);
		while(curr<r1) Add(a[++curr]);
		while(curt<t1) Change(i,++curt);
		while(curt>t1) Change(i,curt--);
		ans[Q[i].id]=(Ans==Q[i].cnt);
		if(Q[i].cnt!=r1-l1+1) ans[Q[i].id]=0;
	}
	F(i,1,tot1) if(ans[i])printf("damushen\n");else printf("yuanxing\n"); 
	return 0;
}
