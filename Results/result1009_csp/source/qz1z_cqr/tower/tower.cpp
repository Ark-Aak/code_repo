//100
#include<bits/stdc++.h>
#define MN 50005
#define MK 55
#define INF 5014514
using namespace std;
int n,k,res=5014514,col[MN],f[MK][MN],g[MK][MN],h[MK],p[MK];
bool c[MK][MK];
char str[MK];
signed main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&col[i]);
	for(int i=1;i<=k;i++){
		scanf("%s",str);
		for(int j=1;j<=k;j++)
			c[i][j]=(str[j-1]=='1');
	}
	memset(f,0x3f,sizeof(f));
	f[0][1]=0; 
	for(int i=1;i<=k;i++){
	for(int j=1;j<=n;j++){
		g[i][j]=c[col[j]][i];
		//cout<<g[i][j]<<' ';
	}/*cout<<'\n';*/}
	for(int o=1;o<=k;o++){
		if(o&1){
			for(int i=1;i<=k;i++){
				p[i]=INF;h[i]=0;}
			for(int j=1;j<=n;j++){
				int cr=col[j];
				//cout<<j<<' '<<cr<<":\n";
				while(h[cr]<j){
					h[cr]++;//cout<<h[cr];
					if(g[cr][h[cr]])
						p[cr]=min(p[cr],f[o-1][h[cr]]+n-h[cr]);
				}//cout<<'\n';
				f[o][j]=min(f[o-1][j],p[cr]-n+j);
			}
		}else{
			for(int i=1;i<=k;i++){
				p[i]=INF;h[i]=n+1;}
			for(int j=n;j>=1;j--){
				int cr=col[j];
				while(h[cr]>j){
					h[cr]--;
					if(g[cr][h[cr]])
						p[cr]=min(p[cr],f[o-1][h[cr]]+h[cr]-1);
				}
				f[o][j]=min(f[o-1][j],p[cr]-j+1);
			}
		}
		//for(int j=1;j<=n;j++){cout<<setw(12)<<f[o][j];}cout<<'\n';
		res=min(res,f[o][n]);
	} 
	if(res>n*k) printf("-1\n");
	else printf("%d\n",res);
	return 0;
} 
