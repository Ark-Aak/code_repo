#include<bits/stdc++.h>
using namespace std;
int f[4005][2005][2];
int a[2005],b[2005];
struct node {
	int id,x,to;
}w[4005];
bool cmp(node u,node v) {
	return u.x<v.x;
}
int main(){
	freopen("seal.in","r",stdin);
	freopen("seal.out","w",stdout);
	int n,t,m,tot=0;
	scanf("%d %d %d",&n,&t,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d %d",&a[i],&b[i]);
		w[++tot].x=a[i],w[tot].id=0;
		w[++tot].x=b[i],w[tot].id=1;
	}
	sort(w+1,w+tot+1,cmp);
	memset(f,-0x3f,sizeof f);
	f[tot+1][0][1]=t-w[tot].x;
	f[tot+1][0][0]=0;
	for(int i=tot;i>=1;i--) {
		for(int j=0;j<=m;j++) {
			if(!w[i].id) {
				if(w[i+1].id==0) {
					f[i][j][1]=max(f[i][j][1],max(f[i+1][j][0],f[i+1][j][1])+(w[i+1].x-w[i].x));
					f[i][j][0]=max(f[i][j][0],max(f[i+1][j][0],f[i+1][j][1]));
				} else {
					f[i][j][0]=max(f[i][j][0],max(f[i+1][j][1],f[i+1][j][0]));
					if(j>0) f[i][j][1]=max(f[i][j][1],max(f[i+1][j][1],f[i+1][j][0]));
				}
			} else {
				if(w[i+1].id==0) {
					f[i][j+1][1]=max(f[i][j+1][1],max(f[i+1][j][1],f[i+1][j][0])+(w[i+1].x-w[i].x));
					f[i][j][0]=max(f[i][j][0],max(f[i+1][j][1],f[i+1][j][0]));
				} else {
					f[i][j][0]=max(f[i][j][0],max(f[i+1][j][1],f[i+1][j][0]));
					if(j>0) f[i][j+1][1]=max(f[i][j+1][1],max(f[i+1][j][1]+(w[i+1].x-w[i].x),f[i+1][j][0]));
				}
				if(w[i-1].id==0 && i>1) f[i][j+1][1]=max(f[i][j+1][1],max(f[i+1][j][0],f[i+1][j][1])+(w[i].x-w[i-1].x+1));
			}
		}
	}
	printf("%d",max(f[1][m][1],f[1][m][0]));
	return 0;
}

