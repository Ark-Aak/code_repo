//50-
#include<bits/stdc++.h>
#define MX 4005
#define int long long
using namespace std;
string str;
int n,ans,es,da,db,dc,mod=998244353;bool p[MX][MX]; 
void add(int x){ans=(ans+x)%mod;}
int qm(int b){
	if(b<0) return 0;
	int c=2,d=1;
	while(b){
		if(b&1) d=(d*c)%mod;
		c=(c*c)%mod;b>>=1;
	}return d;
}
signed main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	cin>>n;es=n*(n-1)/2;
	for(int i=1;i<=n;i++){
		cin>>str;
		for(int j=1;j<=n;j++){
			p[i][j]=(str[j-1]=='1');
			es-=p[i][j];
		}
	}//cout<<es<<'\n';
	da=qm(es);db=qm(es-1);dc=qm(es-2);
	//cout<<da<<' '<<db<<' '<<dc<<'\n';
	for(int i=1;i<n;i++){
	for(int j=i+1;j<n;j++){
	for(int k=j+1;k<=n;k++){
		int a=(p[i][j]?1:(p[j][i]?2:0));
		int b=(p[j][k]?1:(p[k][j]?2:0));
		int c=(p[k][i]?1:(p[i][k]?2:0));
		if(a==1 && b==2){continue;}
		if(b==1 && c==2){continue;}
		if(c==1 && a==2){continue;}
		if(a==2 && b==1){continue;}
		if(b==2 && c==1){continue;}
		if(c==2 && a==1){continue;}
		a=!!a;b=!!b;c=!!c;a=a+b+c;//cout<<a;
		if(a<=1){add(dc);/*cout<<"(-2)\n";*/}
		if(a==2){add(db);/*cout<<"(-1)\n";*/}
		if(a==3){add(da);/*cout<<"(-0)\n";*/}
	}}}cout<<ans;
	return 0;
} 
