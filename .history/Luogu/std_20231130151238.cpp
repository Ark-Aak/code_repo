#include <bits/stdc++.h>
using namespace std;

inline int read(){
	register int x=0;
	register bool f=0;
	register char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=50005;
int len=0;
const int inf=2147483647;
struct seg{
	int v,ls,rs;
}t[maxn*100];
int rt[maxn],n,m,tot,tem[maxn],tmp[maxn],cnt,num;
int lsh[maxn<<1],a[maxn];
struct cz{
	int a,b,c,d;
}q[maxn];
int lb(int x){
	return x&(-x);
}
void pushup(int o){
	t[o].v=t[t[o].ls].v+t[t[o].rs].v;
}
void change(int &o,int l,int r,int k,int v){
	if(!o) o=++tot;
	if(l==r){
		t[o].v+=v;
		return ;
	}
	int mid=l+r>>1;
	if(k<=mid) change(t[o].ls,l,mid,k,v);
	else change(t[o].rs,mid+1,r,k,v);
	pushup(o);
}
void add(int o,int v){
	for(int i=o;i<=n;i+=lb(i)) change(rt[i],1,len,a[o],v);
} 
int query_num(int l,int r,int k){
	if(l==r) {
		return l;
	}
	int mid=l+r>>1,sum=0;
	for(int i=1;i<=cnt;i++) sum+=t[t[tem[i]].ls].v;
	for(int i=1;i<=num;i++) sum-=t[t[tmp[i]].ls].v;
	if(k<=sum){
		for(int i=1;i<=cnt;i++) tem[i]=t[tem[i]].ls;
		for(int i=1;i<=num;i++) tmp[i]=t[tmp[i]].ls;
		return query_num(l,mid,k);
	}
	else{
		for(int i=1;i<=cnt;i++) tem[i]=t[tem[i]].rs;
		for(int i=1;i<=num;i++) tmp[i]=t[tmp[i]].rs;
		return query_num(mid+1,r,k-sum);
	}
}
int find_num(int l,int r,int k){
	cnt=num=0;
	for(int i=r;i;i-=lb(i)){
		tem[++cnt]=rt[i];
	}
	for(int i=l-1;i;i-=lb(i)){
		tmp[++num]=rt[i];
	}
	return query_num(1,len,k);
} 
int query_rnk(int l,int r,int k){
	if(l==r) {
		return 0;
	}
	int mid=l+r>>1,sum=0;
	
	if(k<=mid){
		for(int i=1;i<=cnt;i++) tem[i]=t[tem[i]].ls;
		for(int i=1;i<=num;i++) tmp[i]=t[tmp[i]].ls;
		return query_rnk(l,mid,k);
	}
	else{
		for(int i=1;i<=cnt;i++) sum+=t[t[tem[i]].ls].v,tem[i]=t[tem[i]].rs;
		for(int i=1;i<=num;i++) sum-=t[t[tmp[i]].ls].v,tmp[i]=t[tmp[i]].rs;
		return sum+query_rnk(mid+1,r,k);
	}
}
int find_rnk(int l,int r,int k){
	cnt=num=0;
	for(int i=r;i;i-=lb(i)){
		tem[++cnt]=rt[i];
	}
	for(int i=l-1;i;i-=lb(i)){
		tmp[++num]=rt[i];
	}
	return query_rnk(1,len,k)+1;
}
int find_pri(int l,int r,int k){
	int rk=find_rnk(l,r,k)-1;
	if(rk==0) return 0;
	return find_num(l,r,rk);
}
int find_nxt(int l,int r,int k){
	if(k==len) return len+1;
	int rk=find_rnk(l,r,k+1);
	if(rk==r-l+2) return len+1;
	return find_num(l,r,rk);
}
signed main(){
	freopen("test.in","r",stdin);
		n=read();m=read();
		tot=cnt=num=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			lsh[++len]=a[i];
		}
		for(int i=1;i<=m;i++){
			q[i].a=read();q[i].b=read();q[i].c=read();
			if(q[i].a!=3) q[i].d=read();
			else lsh[++len]=q[i].c;
			if(q[i].a==4 || q[i].a==5) lsh[++len]=q[i].d;
		}
		sort(lsh+1,lsh+len+1);
		len=unique(lsh+1,lsh+len+1)-lsh-1;//离散化
		for(int i=1;i<=n;i++){
			a[i]=lower_bound(lsh+1,lsh+1+len,a[i])-lsh;
			add(i,1);
		}
		lsh[0]=-inf;
		lsh[len+1]=inf;
        	//为了前驱和后继用。
		for(int i=1;i<=m;i++){
			if(q[i].a==3){
				add(q[i].b,-1);
				a[q[i].b]=lower_bound(lsh+1,lsh+1+len,q[i].c)-lsh;
				add(q[i].b,1);
			}
			if(q[i].a==1){
				q[i].d=lower_bound(lsh+1,lsh+1+len,q[i].d)-lsh;
				printf("%d\n",find_rnk(q[i].b,q[i].c,q[i].d));
			}
			if(q[i].a==2){
				printf("%d\n",lsh[find_num(q[i].b,q[i].c,q[i].d)]);
			}
			if(q[i].a==4){
				q[i].d=lower_bound(lsh+1,lsh+1+len,q[i].d)-lsh;
				printf("%d\n",lsh[find_pri(q[i].b,q[i].c,q[i].d)]);
			}
			if(q[i].a==5){
				q[i].d=lower_bound(lsh+1,lsh+1+len,q[i].d)-lsh;
				printf("%d\n",lsh[find_nxt(q[i].b,q[i].c,q[i].d)]);
			}
		}
	return 0;
}

