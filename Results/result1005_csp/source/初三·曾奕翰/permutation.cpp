#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,ans;
int a[100005],b[100005]; 
int jla[100005],jlb[100005]; 
int gg[100005];
int main() {
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),jla[i]=a[i];
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]),jlb[i]=b[i];
	if((ll)m*n<=10000000){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				gg[a[j]]=b[j];
			}
			swap(a,b);
			swap(gg,b);
		}
		for(int i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		return 0;
	}
	int gg_bound=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			gg[a[j]]=b[j];
		}
		swap(a,b);
		swap(gg,b);
		bool flag=1;
		for(int j=1;j<=n;j++){
			if(jla[j]!=a[j]){
				flag=0;break;
			}
			if(jlb[j]!=b[j]){
				flag=0;break;
			}
		}
		if(flag==1){
			gg_bound=i;
			break;
		}
	}
	for(int i=1;i<=m%gg_bound;i++){
		for(int j=1;j<=n;j++){
			gg[a[j]]=b[j];
		}
		swap(a,b);
		swap(gg,b);
	}
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}//ÒªÓÃprintf£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡

