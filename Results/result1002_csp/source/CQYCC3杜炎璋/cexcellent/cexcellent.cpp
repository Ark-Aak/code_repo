#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
bool check(int x,int y,int k) {
	for(int i=x;i<x+k/2;i++) {
		if(s[i]!=s[i+k/2] && s[i]!='?' && s[i+k/2]!='?')
			return 0;
	}
	int K=(y-x+1)-k;	
	for(int i=x+k;i<x+k+K/2;i++) {
		if(s[i]!=s[i+K/2] && s[i]!='?' && s[i+K/2]!='?')
			return 0;
	}
	return 1;
}
signed main(){
	freopen("cexcellent.in","r",stdin);
	freopen("cexcellent.out","w",stdout);
	int t;
	scanf("%lld",&t);
	while(t--) {
		int ans=0;
		cin>>s;
		int n=s.size();
		s=" "+s;
		int flag=1;
		for(int i=1;i<=n;i++) if(s[i]!='?') flag=0;
		if(flag==1) {
			for(int i=4;i<=n;i+=2) ans+=(i/2-1)*(n-i+1);
			printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++) {
			for(int j=i+3;j<=n;j+=2) {
				for(int k=2;k<=j;k+=2) {
					if((j-i+1)>k) ans+=check(i,j,k); 
					else break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

