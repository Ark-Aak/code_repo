#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=2e5+5;
int n,a[Maxn];
int L[Maxn],R[Maxn];
int vis[Maxn];
ll t[Maxn];
inline void add(int x){
	while(x<=n){t[x]++;x+=x&-x;}
}
inline ll query(int x){
	ll res=0;
	while(x){res+=t[x];x-=x&-x;}
	return res;
}
ll ans;
struct node{int l,r,id;}s[Maxn];
bool cmp(node a,node b){return a.l>b.l;}
int main(){
	freopen("gather.in","r",stdin);
	freopen("gather.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		R[i]=n;
		L[i]=vis[a[i]]+1;
		R[vis[a[i]]]=i-1;
		vis[a[i]]=i;
		s[i]={L[i],R[i],i};
	}
	if(n<=5005){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(R[i]>=j&&L[j]<=i)ans++;
	}
	else{
		sort(s+1,s+1+n,cmp);
		int w=n;
		for(int i=1;i<=n;i++){
			while(s[i].l<=w){add(R[w]);w--;}
			ans+=query(n)-query(s[i].id-1)-1ll;
		}
		ans-=1ll*n*(n-1)/2;
	}
	printf("%lld",ans);
	return 0;
}

