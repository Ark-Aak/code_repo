#include<bits/stdc++.h>
#define mid (l+r>>1)
#define ll long long
using namespace std;
const int N=1e6+5;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
int n,m,k,a[N],l[N],r[N];
int mx[N*4],mi[N*4];
ll S,sum[N];
inline int Max(int x,int y){return sum[x]<0?y:(sum[y]<0?x:(sum[x]>sum[y]?x:y));}
inline int Min(int x,int y){return sum[x]<0?y:(sum[y]<0?x:(sum[x]<sum[y]?x:y));}
inline void push_up(int p){
	mx[p]=Max(mx[2*p],mx[2*p+1]);
	mi[p]=Min(mi[2*p],mi[2*p+1]);
}
void build(int p,int l,int r){
	if(l==r){
		mx[p]=mi[p]=l;
		return;
	}
	build(2*p,l,mid);
	build(2*p+1,mid+1,r);
	push_up(p);
}
void change(int p,int l,int r,int x,ll v){
	if(l==r){
		sum[l]=v;
		return;
	}
	if(x<=mid) change(2*p,l,mid,x,v);
	else change(2*p+1,mid+1,r,x,v);
	push_up(p);
}
inline void sub1(){
	sort(a+1,a+n+1);
	printf("%lld\n",S-a[n/2+1]);
}
int b[N],cnt,ls;
inline void del(int x){
	r[l[x]]=r[x];
	l[r[x]]=l[x];
}
inline void sub2(){
	m=n-k+1;
	ll s=0;
	for(int i=n;i>m;--i) s+=a[i];
	for(int i=m;i;i--) s+=a[i]-a[i+k],sum[i]=s;
	build(1,1,m);int x,cnt,cnt2;
	for(int i=1;i<=n;i++) l[i]=i-1,r[i]=i+1;
	for(int c=n/k,o=1,rt,lt;c;--c,o^=1){
		x=o?mi[1]:mx[1];
		rt=x;
		for(int j=k;j;--j,rt=r[rt]) change(1,1,m,rt,-1),del(rt);
		cnt=0;s=0;ls=1;
		for(;rt<=n&&cnt<k-1;rt=r[rt])
			b[++cnt]=a[rt],s+=a[rt];
		lt=l[x];
		for(int i=1;i<=cnt/2;i++) swap(b[i],b[cnt-i+1]);
		for(int cnt2=1;lt&&cnt2<k;lt=l[lt],++cnt2){
			s+=a[lt],b[++cnt]=a[lt];
			if(cnt<k) change(1,1,m,lt,-1),del(lt);
			else{
				change(1,1,m,lt,s);
				s-=b[ls++];
			}
		}
	}
	printf("%lld",S-a[mx[1]]);
}
int main(){
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
	read(n),read(k);
	for(int i=1;i<=n;i++) read(a[i]),S+=a[i];
	if(k==1) sub1();
	else sub2();
	return 0;
}

