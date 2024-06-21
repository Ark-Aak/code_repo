#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const ll N=3e5+10,M=2e6+10;
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')
          f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)
	  write(x/10);
	putchar(x%10+'0');
}
struct Node{
	int l,r;
	int Min,Max;
	int tag;
}X[N<<2];
ll ans1,ans2;
int n,m,cnt;
int a[N],t[N];
int h[M];
inline void msort(int l,int r){
    if(l+1==r)
	  return;
    int mid=(l+r)>>1;
    msort(l,mid);
    msort(mid,r);
    int p=1;
    for(int i=l,j=mid;i<mid||j<r;){
        if(j==r||(i<mid&&a[i]<=a[j]))
          t[p++]=a[i++];
		else{
            ans1+=mid-i;
            ans2+=mid-i;
            t[p++]=a[j++];
        }
    }
    for(int i=1,j=l;i<p;)
      a[j++]=t[i++];
}
inline void pushup(int k){
	X[k].Min=min(X[k<<1].Min,X[k<<1|1].Min);
	X[k].Max=max(X[k<<1].Max,X[k<<1|1].Max);
}
inline void add(int k,int v){
	X[k].Min+=v;
	X[k].Max+=v;
	X[k].tag+=v;
}
inline void push_down(int k){
	if(X[k].tag){
		add(k<<1,X[k].tag);
		add(k<<1|1,X[k].tag);
		X[k].tag=0;
	}
}
inline void build(int k,int l,int r,bool f){
	X[k].l=l,X[k].r=r;
	X[k].tag=0;
	if(l==r){
		if(!f)
		  X[k].Max=X[k].Min=l;
		else
		  X[k].Max=X[k].Min=m-l;
		return ;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid,f);
	build(k<<1|1,mid+1,r,f);
	pushup(k);
}
inline void update(int k,int l,int r,int v){
	if(X[k].l==l&&r==X[k].r){
		add(k,v);
		return ;
	}
	push_down(k);
	int mid=(X[k].l+X[k].r)>>1;
	if(r<=mid)
	  update(k<<1,l,r,v);
	else if(l>mid)
	  update(k<<1|1,l,r,v);
	else{
		update(k<<1,l,mid,v);
		update(k<<1|1,mid+1,r,v);
	}
	pushup(k);
}
inline void solve(){
	build(1,0,m,0);
	for(int i=1;i<=n;i++){
		if(h[i-1])
		  update(1,0,h[i-1]-1,1);
		if(!h[i])
		  ans1+=X[1].Min;
		else
		  update(1,h[i],m,-1);
	}
	build(1,0,m,1);
	for(int i=n;i>=1;i--){
		if(h[i+1])
		  update(1,h[i+1],m,1);
		if(!h[i])
		  ans2+=X[1].Max;
		else
		  update(1,0,h[i]-1,-1);
	}
}
int main(){
//	freopen("A.in","r",stdin);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		a[i]=read();
		h[a[i]]=i;
	}
	msort(1,m+1);
	solve();
	write(ans1);
	putchar(' ');
	write(ans2+1ll*(n-m)*(n-m-1)/2);
	return 0;
}
