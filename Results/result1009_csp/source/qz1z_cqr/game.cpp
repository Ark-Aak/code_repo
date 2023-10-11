//60
#include<bits/stdc++.h>
#define MX 1000
using namespace std;
int res[MX+5][MX+5],T,n,m,mod=1000000007;
int gmod(int yc){return ((yc%mod)+mod)%mod;}
int bgcd(int a,int b){
	if(!b) return a;
	return bgcd(b,a%b);
} 
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	for(int i=1;i<=MX;i++)
	for(int j=1;j<=MX;j++)
		res[i][j]=(i+j)/bgcd(i,j)-2;
	for(int i=1;i<=MX;i++)
	for(int j=1;j<=MX;j++)
		res[i][j]=gmod(res[i][j]+res[i-1][j]+res[i][j-1]-res[i-1][j-1]);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		printf("%d\n",res[n][m]);
	}
	/*cout<<"     |";for(int i=1;i<=12;i++){cout<<setw(5)<<i;}cout<<'\n';
	for(int i=1;i<=12;i++){
		cout<<setw(5)<<i;cout<<'|';
		for(int j=1;j<=12;j++)
			cout<<setw(5)<<(i+j)/__gcd(i,j)-2;
		cout<<'\n';
	}
	cout<<"\n     |";for(int i=1;i<=12;i++){cout<<setw(5)<<i;}cout<<'\n';
	for(int i=1;i<=12;i++){
		cout<<setw(5)<<i;cout<<'|';
	for(int j=1;j<=12;j++){d=0;
	for(int ii=1;ii<=i;ii++){
	for(int jj=1;jj<=j;jj++){
		d+=res[ii][jj];
	}}cout<<setw(5)<<d;
	}cout<<'\n';}*/
	return 0;
} 
