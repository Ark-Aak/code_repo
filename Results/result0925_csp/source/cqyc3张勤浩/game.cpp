#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=1e5+7;
int T,n,k,sum0[Maxn];
string s;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		cin>>s;
		memset(sum0,0,sizeof sum0);
		int cnt0=0;
		bool flg=0;
		for(int i=1;i<=n;i++) if(s[i-1]=='0') sum0[i]=1,cnt0++;
		for(int i=1;i<=n;i++) sum0[i]+=sum0[i-1];
		for(int i=k;i<=n;i++){
			if(sum0[i]-sum0[i-k]==cnt0) flg=1;
			if(k-(sum0[i]-sum0[i-k])==n-cnt0) flg=1;
		}
		if(flg){
			printf("win\n");
			continue;
		}
		flg=0;
		int l=0,r=n-1;
		while(s[l]!='0') ++l;
		while(s[r]!='0') --r;
		flg|=(r-l-1>=k);
		
		l=1,r=n-1;
		while(s[l]!='1') ++l;
		while(s[r]!='1') --r;
		flg|=(r-l-1>=k);
		if(flg){
			printf("tie\n");
		}
		else{
			printf("lose\n");
		}
	}
	return 0;
}
