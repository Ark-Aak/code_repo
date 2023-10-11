#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Maxn=3e5+7;
ll n,a[Maxn],res,R[Maxn],pos[Maxn];
ll cnt[Maxn],qcnt,sq,ans;
struct ques{
	ll l,r;
}q[Maxn];
inline bool cmp(ques x,ques y){
	return x.l/sq==y.l/sq?x.r<y.r:x.l<y.r;
}
inline void add(ll x){
	res-=max(cnt[a[x]]-1,0ll);
	cnt[a[x]]++;
	res+=max(cnt[a[x]]-1,0ll);
}
inline void del(ll x){
	res-=max(cnt[a[x]]-1,0ll);
	cnt[a[x]]--;
	res+=max(cnt[a[x]]-1,0ll);
}
int main(){
	freopen("gather.in","r",stdin);
	freopen("gather.out","w",stdout);
	scanf("%lld",&n);
	sq=sqrt(n)+1;
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(ll i=n;i;i--){
		if(!pos[a[i]]) R[i]=n;
		else R[i]=pos[a[i]];
		pos[a[i]]=i;
		ans+=(n-R[i]);
		q[++qcnt]=(ques){i,R[i]};
	}
	sort(q+1,q+qcnt+1,cmp);
	ll l=1,r=0;
	for(ll i=1;i<=qcnt;i++){
		while(r<q[i].r) add(++r);
		while(r>q[i].r) del(r--);
		while(l<q[i].l) del(l++);
		while(l>q[i].l)	add(--l);
		ans+=res;
	}
	printf("%lld",(n-1)*n/2-ans);
	return 0;
}
/*
7
1 2 3 4 3 2 5 

10
2 2 2 3 3 4 4 4 5 5
*/
