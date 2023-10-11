#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int Mod=147744151;
int n,k,ans=0;

int log(int x){
	int p=0;
	while(x){
		p++;
		x/=2;
	}
	return p;
}
int solve(int x){
	int l=0,r=(int)sqrt(x)*10,p;
	while(l<=r){
		int mid=(l+r)>>1;
		if(mid*(mid+1)/2<=x) l=mid+1,p=mid;
		else r=mid-1;
	}
	if(p*(p+1)/2!=n) p++;
	return p;
}
signed main() {
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	if(k==1){
		cout<<n;
		return 0;
	}
	if(k==2){
		int l=0,r=(int)sqrt(n)*10,p;
		while(l<=r){
			int mid=(l+r)>>1;
			if(mid*(mid+1)/2<=n) l=mid+1,p=mid;
			else r=mid-1;
		}
		if(p*(p+1)/2!=n) p++;
		cout<<p%Mod;
		return 0;
	}
	/*if(k>=147744151){
		int p=0,x=n;
		while(x!=1){
			int tt=x;
			int gg=(int)(sqrt(x));
			if(gg*gg!=x) x=gg+1;
			else x=gg;
			if(tt==x) break;
			p+=gg;
			//cout<<x<<" ";
		}
		cout<<p%Mod;
		return 0;
	}*/
	if(log(n)<=k){
		cout<<log(n);
		return 0;
	}
	int x=n,gg=0;
	while(x!=1&&k!=1){
		k--;
		int p=solve(x);
		int pp=solve(p);
		if(pp*(pp+1)/2==p){
			gg+=1;
			x=p;
		} 
		else{
			gg+=p-(pp-1)*pp/2-1;
			x=(pp-1)*pp/2;
		}
		gg+=1;
		gg%=Mod;
		
	}
	if(x>1) gg+=x;
	cout<<gg%Mod;//福摩斯尔：盲生，你发现了华点。 
	return 0;
}
