#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,f[1000005][6],a[1000005],maxn=0,ans[1000005];
struct node {
	int l,r,id;
}Q[1000005];
const int mod=4294967296;
bool cmp(node x,node y) {
	return x.r<y.r;
}
signed main() {
	freopen("milky.in","r",stdin);
	freopen("milky.out","w",stdout);
	string s;
	cin>>s;
	n=s.size();
	s=" "+s;
	cin>>q;
	for(int i=1; i<=n; i++) {
		if(s[i]=='m') a[i]=1;
		else if(s[i]=='i') a[i]=2;
		else if(s[i]=='l') a[i]=3;
		else if(s[i]=='k') a[i]=4;
		else if(s[i]=='y') a[i]=5;
	}
	for(int i=1; i<=q; i++) {
		cin>>Q[i].l>>Q[i].r;
		Q[i].id=i;
		maxn=max(maxn,Q[i].l);
	}
	if(maxn>1) {
		for(int i=1; i<=q; i++) {
			int l,r,cnt=0;
			l=Q[i].l,r=Q[i].r;
			memset(f,0,sizeof f);
			for(int j=r; j>=l; j--) {
				f[j][a[j]]=(f[j][a[j]]+f[j+1][a[j]+1])%mod;
				for(int k=1; k<=5; k++) f[j][k]=(f[j][k]+f[j+1][k])%mod;
				if(a[j]==5) f[j][a[j]]=(f[j][a[j]]+1)%mod;
			}
			for(int j=l; j<=r; j++) {
				if(a[j]==1) {
					cnt=(cnt+f[j][a[j]])%mod;
					break;
				}
			}
			printf("%lld\n",cnt);
		}
	} else {
		sort(Q+1,Q+q+1,cmp);
		for(int j=1; j<=n; j++) {
			f[j][a[j]]=(f[j][a[j]]+f[j-1][a[j]-1])%mod;
			for(int k=1; k<=5; k++) f[j][k]=(f[j][k]+f[j-1][k])%mod;
			if(a[j]==1) f[j][a[j]]=(f[j][a[j]]+1)%mod;
		}
		int k=1;
		for(int i=1;i<=q;i++) {
			int l=Q[i].l,r=Q[i].r;
			for(int j=k;j<=r;j++) {
				if(a[j]==5) k=j;
			}
			ans[Q[i].id]=f[k][5];
		}
		for(int i=1;i<=q;i++) {
			printf("%lld\n",ans[i]);
		}
	}
	return 0;
}

