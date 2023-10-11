#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005][5];
int f[200005];
int gg[200005];
struct XXX{
	int c,id;
}z[200005];
bool cmp(XXX x,XXX y){
	return x.c<y.c;
}
int find(int fa){
	if(f[fa]==fa) return fa;
	return f[fa]=find(f[fa]);
}
signed main() {
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++){
		f[i]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d%d",&z[i].c,&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
		z[i].id=i;
		for(int j=1;j<=4;j++){
			if(gg[a[i][j]]>0)
				f[find(gg[a[i][j]])]=find(f[(i-1)*2+(j-1)/2+1]);
			else
				gg[a[i][j]]=(i-1)*2+(j-1)/2+1;
		}
	}
	/*for(int i=1;i<=n;i++){
		cout<<find(f[2*i-1])<<" "<<find(f[i*2])<<endl;
	}*/
	sort(z+1,z+n+1,cmp);
	for(int i=1;i<=n;i++){
		int l=(z[i].id-1)*2+1,r=(z[i].id-1)*2+2;
		if(find(l)!=find(r)){
			ans+=z[i].c;
			f[find(r)]=find(l);
		} 
	} 
	cout<<ans;
	return 0;
}//ÒªÓÃprintf£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 
