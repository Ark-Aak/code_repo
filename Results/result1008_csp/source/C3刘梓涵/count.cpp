#include<bits/stdc++.h>
#define inf LONG_LONG_MAX
#define fir first
#define sec second
#define ls (x<<1)
#define rs (x<<1|1)
#define mid ((l+r)>>1)
#define Pr(i,j) pair<i,j>
#define PB(i) push_back(i)
#define MP(i,j) make_pair(i,j)
#define Fo(i,j) for(auto i:j)
#define mem(i,j) memset(i,j,sizeof(i))
#define FO(i,j,k) for(int i=j;i;i=k)
#define FFF(i,j,k) for(auto i=j;i!=k;++i)
#define For(i,j,k) for(int i=j;i<=k;++i)
#define FoR(i,j,k) for(int i=j;i^k;++i)
#define FOR(i,j,k) for(int i=j;i>=k;--i)
using namespace std;
template <typename _Tp>void read(_Tp& first) {
    _Tp x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
    first = x * f;
}inline void write(int x){
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
#define N 5005
#define Mod 998244353
#define int long long
int n,m,ans,inv[100005];
int a[N],f[N][N];
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%Mod;
		a=a*a%Mod;
		b>>=1;
	}return res;
}
signed main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	read(n),read(m);
	For(i,0,m+1)inv[i]=ksm(i,Mod-2);
	For(i,1,m){
		int x;
		read(x);
		a[x]++;
	}FOR(i,n,1)a[i]+=a[i+1];
//	For(i,1,n)cout<<a[i]<<" ";
	f[1][1]=m;f[2][2]=a[2];
	For(i,2,n){
		For(j,1,n){
			int s=f[i-1][j]*(m-1)%Mod;
			f[i][1]=(f[i][1]+s)%Mod;
			if(j==1)f[i+1][2]+=s*(a[2])%Mod*ksm(a[1],Mod-2)%Mod;
			else{
				int k=f[i-1][j]*inv[a[j]]%Mod;
				f[i+1][2]+=k*(m-a[j])%Mod*(a[2]-a[j])%Mod*inv[m-a[j]]%Mod;
				f[i+1][2]%=Mod;
//				cout<<i+1<<" "<<j<<":"<<endl;
//				cout<<f[i+1][2]<<' '<<k<<endl;
				f[i+1][2]+=max(0ll,k*(a[j]-1)%Mod*(a[j])%Mod);
//				cout<<f[i+1][2]<<endl;
			}f[i+1][2]%=Mod;
		}
		For(j,3,n){
			if(a[j]==a[j-1])f[i][j]+=f[i-1][j-1];
			else if(a[j]&&f[i-1][j-1])
				f[i][j]+=f[i-1][j-1]*(a[j])%Mod*ksm(a[j-1],Mod-2)%Mod;
//				f[i][j]+=f[i-1][j-1]*(a[j])/a[j-1]%Mod;
			f[i][j]%=Mod;
		}
	}
	For(i,1,n)ans=(ans+f[n][i])%Mod;
	write(ans);
//	cout<<endl;For(i,1,n)cout<<a[i]<<" ";cout<<endl;
//	cout<<endl;For(j,1,n){
//		For(i,1,n)cout<<f[j][i]<<' ';
//		cout<<endl;
//	}
    return 0;
}
/*
4 4
1 2 3 4
*/
