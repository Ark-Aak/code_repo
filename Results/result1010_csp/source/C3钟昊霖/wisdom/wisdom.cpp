//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define F(i,a,b) for(int i=a;i<=b;i++)
//const int N = 1e6+5,Mod=1e9+7;
//
//inline int ksm(int a,int b) {
//	int aa=1;
//	while(b) {
//		if(b&1) aa*=a,aa%=Mod;
//		a*=a;
//		a%=Mod;
//		b>>=1;
//	}
//	return aa;
//}
//struct node {
//	int id,k;
//};
//bool cmp(node a,node b) {
//	return a.id<b.id;
//}
//vector<node> l,r;
//int ans,n,m,t,L[N],R[N],Lk[N],Rk[N];
//char c;
//signed main() {
//	F(i,1,1000000) Lk[i]=Rk[i]=1;
//	cin>>n>>m>>t;
//	int inv=ksm(2,Mod-2);
//	ans=(n*m+1)*(n*m)*inv;
//	ans=(ans+Mod)%Mod;
//	for(int i=1,u,v; i<=t; i++) {
//		cin>>c;
//		cin>>u>>v;
//		if(c=='R') l.push_back((node) {
//			u,v
//		});
//		if(c=='S') r.push_back((node) {
//			u,v
//		});
//	}
//	F(i,1,n) L[i]=((i-1)*m+1+i*m)%Mod*m*inv%Mod;
//	F(i,1,m) R[i]=(i+(n-1)*m+i)*n%Mod*inv%Mod;
//	if(l.size()!=0) sort(l.begin(),l.end(),cmp);
//	if(r.size()!=0)sort(r.begin(),r.end(),cmp);
//	if(l.size()!=0) {
//		F(i,0,l.size()-1) {
//			ans-=L[l[i].id];
//			L[l[i].id]*=l[i].k;
//			L[l[i].id]=(L[l[i].id]+Mod)%Mod;
//			ans+=L[l[i].id];
//			Lk[l[i].id]*=l[i].k,Lk[l[i].id]%=Mod;
//			ans%=Mod;
//		}
//	}
//	if(r.size()!=0) {
//		F(i,0,r.size()-1) {
//			ans-=R[r[i].id];
//			R[r[i].id]*=r[i].k;
//			ans+=R[r[i].id];
//		}	
//	}
//	cout<<ans%Mod;
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define F(i,a,b) for(int i=a;i<=b;i++)
const int N=1e3+5,Mod=1e9+7;

int n,m,k,a[N][N];
char c;
signed main(){
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	cin>>n>>m>>k;
	F(i,1,n)
	F(j,1,m)
	a[i][j]=(i-1)*m+j;
	for(int i=1,u,v;i<=k;i++){
		cin>>c;cin>>u>>v;
		if(c=='R') for(int j=1;j<=m;j++) a[u][j]*=v,a[u][j]%=Mod;
		if(c=='S') for(int j=1;j<=n;j++) a[j][u]*=v,a[u][j]%=Mod;
	}
	int ans=0;
	F(i,1,n) F(j,1,m) ans+=a[i][j],ans%=Mod;
	cout<<(ans+Mod)%Mod;
	return 0;
} 
