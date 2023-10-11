#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n;
struct Node{
	int l,r;
}x[N];

unsigned long long ans;
bool cmp(Node a,Node b){return a.r>b.r;}
/*
int tr[3][N];
int lb(int x){return x&(-x);}
void add(int x,int k,int id){for(;x;x-=lb(x)) tr[id][x]+=k;}
int sum(int x,int id){int res=0;for(;x<=2*n;x+=lb(x)) res+=tr[id][x];return res;}
*/
signed main(){
	freopen("explorer.in","r",stdin);
	freopen("explorer.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		int a=read(),b=read();
		x[i].l=min(a,b);
		x[i].r=max(a,b);
	}
	sort(x+1,x+1+n,cmp);
	if(n<=500){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					int l1=x[i].l,l2=x[j].l,l3=x[k].l;
					int r1=x[i].r,r2=x[j].r,r3=x[k].r;
					if(l1>l2&&l2>l3&&l1<r3) ans++;				
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					int l1=x[i].l,l2=x[j].l,l3=x[k].l;
					int r1=x[i].r,r2=x[j].r,r3=x[k].r;
					if((l2>l1&&l3>l1&&l2>r3)||(l1>r2&&l2>r3)) ans++;
				}
			}
		}	
		printf("%lld",ans);		
	}
	else{
		if(n<=2){
			printf("0");
			return 0;
		}
		else{
			ans=1;
			for(int i=2;i<=n;i++) ans*=i;
			for(int i=2;i<=3;i++) ans/=i;
			for(int i=2;i<=n-3;i++) ans/=i;
			printf("%lld",ans);
		}
	}
	return 0;
}
