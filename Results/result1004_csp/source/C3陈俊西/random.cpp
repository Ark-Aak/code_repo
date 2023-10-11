#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e3+5,mod=998244353;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m,ans,p2[1000005];
bool dis[N][N];
void add(int &a,int b){if((a+=b)>=mod) a-=mod,cout;}
void pre(){
	p2[0]=1;
	for(int i=1;i<=1000000;i++)
		p2[i]=(p2[i-1]*2)%mod;
	return;
}
signed main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	n=read(),m=n*(n-1)/2;
	pre();
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		s=' '+s;
		for(int j=1;j<=n;j++)
			if(s[j]=='1') dis[i][j]=1,m--; 
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if((!dis[j][i])&&(!dis[k][j])&&(!dis[i][k])){
					add(ans,p2[m-(!dis[i][j])-(!dis[j][k])-(!dis[k][i])]);
				} 
				if((!dis[i][j])&&(!dis[j][k])&&(!dis[k][i])){
					add(ans,p2[m-(!dis[j][i])-(!dis[k][j])-(!dis[i][k])]);
				} 
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
