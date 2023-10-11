#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[500005];
int tot,h[500005],v[500005],l=1;
int ans,s;
signed main(){
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]) h[++tot]=a[i];
		v[tot]++;
	}
	while(n){
		while(v[l]==0&&l<tot) l++;
		if(l==tot){
			if(v[l]%k!=0){
				ans+=(v[l]%k+v[l])*(v[l]/k+1)*(h[l]-1);
				break;
			}
			else{
				ans+=(k+v[l])*(v[l]/k)*(h[l]-1);
				break;
			}
		}
		if(v[l]>=k){
			if(v[l]%k==0){
				ans+=(n+n-v[l])*(v[l]/k+1)*(h[l]-1);
				n-=v[l];
				v[l]=0;
				continue;
			}
			else{
				ans+=(n+n-v[l]+v[l]%k)*(v[l]/k+1)*(h[l]-1);
				n-=v[l]-v[l]%k;
				v[l]%=k;
				continue;
			}
		}
		int r=min(k,v[l]);
		int w=k-r,s=h[l]-1,y=l;
		n-=r;
		v[l]-=r;
		for(int i=l+1;i<=tot&&k>0;i++){
			if(s*2*n>(n-min(w,v[i]))*(h[i]-1)*2){
				int p=min(w,v[i]);
				n-=p;
				w-=p;
				v[i]-=p;
				s=h[i]-1;
			}
		}
		ans+=s*2*(n+(k-w));
	}
	printf("%lld",ans);
	return 0;
}


