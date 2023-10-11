#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans,xm10[10000],s,t;
string L,R;
ll l,r;
inline ll f(ll i,ll j,ll x){
	return (x/xm10[n-j])%xm10[j-i+1];
}
inline ll getans(ll n,ll x){
	ll res=0;
	for(ll i=1;i<=n;i++){
		if(!f(i,i,x)) continue;
		for(ll j=i;j<=n;j++){
			
			if(f(i,j,x)>=l&&f(i,j,x)<=r)
				res++;
		}
	}
		
	return res;	
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>L>>R;
	scanf("%lld",&n);
	if(L.size()>7){
		printf("0\n");
		for(ll i=1;i<=n;i++) cout<<0;
		return 0;
	}
	for(ll i=0;i<L.size();i++) l=l*10+(L[i]-'0');
	for(ll i=0;i<R.size();i++){
		r=r*10+(R[i]-'0');
		if(r>=1e9) break;
	}
	xm10[0]=1;
	for(ll i=1;i<=10;i++) xm10[i]=xm10[i-1]*10;
	for(ll i=1;i<=n;i++) s=s*10+9;
	//cout<<getans(n,111104)<<endl;
	
	for(ll i1=0;i1<=9;i1++)
		for(ll i2=0;i2<=9;i2++)
			for(ll i3=0;i3<=9;i3++)
				for(ll i4=0;i4<=9;i4++)
					for(ll i5=0;i5<=9;i5++)
						for(ll i6=0;i6<=9;i6++){
								ll x=i1*100000+i2*10000+i3*1000+i4*100+i5*10+i6;
								ll res=getans(n,x);
								if(res>ans) s=x,ans=res;
							}
	ll p=s,cnt=0;
	while(p) p/=10,cnt++;
	cout<<ans<<endl;
	while(cnt<n) cnt++,cout<<0;
	cout<<s;
	return 0;
}
/*
104
125
6
*/
