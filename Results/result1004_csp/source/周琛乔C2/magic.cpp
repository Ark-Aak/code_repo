#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while((c<'0'||'9'<c)&&c^-'-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
int n,c[N],a[N][4],f[N<<1],id[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline bool cmp(int x,int y){return c[x]<c[y];}
long long ans;
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	read(n);
	for(int i=1;i<=n*2;i++) f[i]=i;
	for(int i=1;i<=n;i++){
		read(c[i]);
		for(int j=0;j<4;j++) read(a[i][j]);
		f[find(a[i][0])]=find(a[i][1]);
		f[find(a[i][2])]=find(a[i][3]);
		id[i]=i;
	}
	sort(id+1,id+n+1,cmp);
	for(int i=1,j;i<=n;i++){
		j=id[i];
		if(find(a[j][0])^find(a[j][2])){
			f[f[a[j][0]]]=f[a[j][2]];
			ans+=c[j];
		}
	}
	printf("%lld",ans);
	return 0;
}

