#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000005];
int l[1000005],r[1000005];
int tp,sta[1000005];
signed main(){
	freopen("mountain.in","r",stdin);
	freopen("mountain.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;++i) {
		while(tp&&a[i]>a[sta[tp]])
			r[sta[tp--]] = i;
		sta[++tp]=i;
	}
	while(tp) r[sta[tp--]]=n+1;
	for(int i=n;i>=1;--i) {
		while(tp&&a[i]>a[sta[tp]])
			l[sta[tp--]]=i;
		sta[++tp]=i;
	}
	while(tp) l[sta[tp--]]=0;
	for(int i=1;i<=n;i++){
		cout<<r[i]-l[i]-2<<endl;
	}
	return 0;
}
