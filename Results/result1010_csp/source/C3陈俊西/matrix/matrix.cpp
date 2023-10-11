#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=2e5+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m,minn=1e9;
bool s[25][M],mk[25];
int solve(){
	int res=0;
	for(int i=1;i<=m;i++){
		int s0=0,s1=0;
		for(int j=1;j<=n;j++){
			if(s[j][i]){
				if(mk[j]) s0++;
				else s1++;
			}
			else{
				if(mk[j]) s1++;
				else s0++;
			}
		}
		res=res+min(s0,s1);
		if(res>minn) return res;
	}
	return res;
}
signed main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		string c;
		cin>>c;
		for(int j=0;j<m;j++)
			s[i][j+1]=c[j]-48;
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=1;j<=n;j++) mk[j]=0;
		int j=0,x=i;
		while(x){
			j++;
			if(x&1) mk[j]=1;
			x>>=1;
		}
		minn=min(minn,solve());
	}
	printf("%lld",minn);
	return 0; 
}
