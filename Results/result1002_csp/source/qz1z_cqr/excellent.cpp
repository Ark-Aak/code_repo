#include<bits/stdc++.h>
using namespace std;
int T,n,p,c,ans,cntl[3005],cntr[3005];
string s;
bool cmp(char x,char y){
	if(x=='?') return true;
	if(y=='?') return true;
	if(x==y) return true;
	return false;
}
signed main(){
	freopen("excellent.in","r",stdin);
	freopen("excellent.out","w",stdout); 
	cin>>T;
	while(T--){
		cin>>s;n=s.size();s=" "+s;
		memset(cntl,0,sizeof(cntl));
		memset(cntr,0,sizeof(cntr));
		for(int i=1;i<=(n>>1);i++){
			p=1;c=0;
			while(p+i<=n){
				if(cmp(s[p],s[p+i])){c++;}
				else{c=0;}
				if(c==i){
					cntl[p+i]++;
					cntr[p-i+1]++;
					c--;
				}p++;
			}
		}ans=0;
		for(int i=1;i<n;i++)
			ans+=(cntl[i]*cntr[i+1]);
		cout<<ans<<'\n';
	}
	return 0;
} 
