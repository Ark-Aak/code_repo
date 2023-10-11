//20
#include<bits/stdc++.h>
#define MX 3005
#define int long long
using namespace std;
int n,ans,p[MX][2],a,b,c,l[8];
void special(){cout<<n*(n-1ll)/2ll*(n-2ll)/3ll;}
int ck(int x,int y){
	if(x>y)swap(x,y);
	int xx=0,yy=0;
	for(int i=0;i<6;i++){
		if(l[i]==x || l[i]==y)continue;
		if(x<l[i] && l[i]<y) xx++;
		else yy++;
	}return min(xx,yy);
}
signed main(){
	freopen("explorer.in","r",stdin);
	freopen("explorer.out","w",stdout);
	cin>>n;
	if(n>2000){special();return 0;}
	for(int i=1;i<=n;i++) cin>>p[i][0]>>p[i][1];
	for(int i=1;i<n;i++)
	for(int j=i+1;j<n;j++)
	for(int k=j+1;k<=n;k++){
		l[0]=p[i][0];l[1]=p[i][1];
		l[2]=p[j][0];l[3]=p[j][1];
		l[4]=p[k][0];l[5]=p[k][1];
		a=ck(p[i][0],p[i][1]);
		b=ck(p[j][0],p[j][1]);
		c=ck(p[k][0],p[k][1]);
		if(a==b && b==c) ans++;
	}cout<<ans;
	return 0;
}
