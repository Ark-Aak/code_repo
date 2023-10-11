#include<bits/stdc++.h>
using namespace std;
namespace fastio {
	struct {
		template<typename T>operator T() {
			T x=0;
			char f=0,c=getchar();
			while(c<'0'||c>'9') {
				if(c=='-')f=1;
				c=getchar();
			}
			while(c>='0'&&c<='9') {
				x=x*10+(c^48);
				c=getchar();
			}
			return f?-x:x;
		}
	} in;
	int stk[40],tp;
	template<typename T>void out(T x,char c=0) {
		if(x<0)putchar('-'),x=-x;
		do stk[++tp]=x%10,x/=10;
		while(x);
		while(tp)putchar(stk[tp--]^48);
		if(c)putchar(c);
	}
} using fastio::in;
using fastio::out;
string s[55];
int a[1000005],dis[100005],b[50005][55][5];
int tot[55],u[55][50005];
int main() {
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	int n,m,w,t;
	n=in,m=in;
	for(int i=1; i<=n; i++) {
		int x=in;
		a[i]=x;
		u[x][++tot[x]]=i;
	}
	for(int i=1; i<=m; i++) sort(u[i]+1,u[i]+tot[i]+1);
	for(int i=1; i<=m; i++)  cin>>s[i];
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m ; j++) {
			if(s[a[i]][j-1]=='0') continue; 
			int l1=lower_bound(u[j],u[j]+tot[j],a[i])-u[j];
			int l2=l1-1;
			if(l1>0 && l1<=tot[j]) b[i][j][0]=tot[j];
			else l1=0;
			if(l2>0 && l2<=tot[j]) b[i][j][1]=1;
			else l2=0;
		}
	}
	for(int i=1;i<=n;i++) if(s[a[i]][a[1]-1]=='1') b[i][a[1]][2]=1;
	for(int i=1;i<=n;i++) if(s[a[i]][a[n]-1]=='1') b[i][a[n]][3]=tot[a[n]];
	if(n<=1000) {
		memset(dis,0x3f,sizeof dis);
		dis[1]=0;
		for(int i=1; i<=m; i++) {
			for(int j=1; j<=n; j++) {
				for(int k=1; k<=n; k++) {
					if(s[a[j]][a[k]-1]=='1') {
						dis[k]=min(dis[k],dis[j]+abs(j-k));
					}
				}
			}
		}
		printf("%d",dis[n]);
	} else {
		memset(dis,0x3f,sizeof dis);
		dis[1]=0;
		for(int i=1; i<=m; i++) {
			for(int j=1; j<=n ;j++) {
				for(int k=1;k<=m;k++) {
					if(s[a[j]][k-1]=='0') continue;
					for(int w=0;w<=3;w++) {
						if(b[j][k][w]) {
							dis[u[k][b[j][k][w]]]=min(dis[u[k][b[j][k][w]]],dis[j]+abs(u[k][b[j][k][w]]-j));
						}
					}
				}
			}
		}
	}
	printf("%d",dis[n]);
	return 0;
}
/*
5 4
1 4 2 3 4
1010
0001
0110
0100

*/

