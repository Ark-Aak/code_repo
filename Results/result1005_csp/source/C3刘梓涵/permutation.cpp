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
#define N 100005
#define Mod 998244353
#define int long long
int n,m,k;
int p[N],q[N],f[N];
int pp[N],qq[N];
void out(int a[]){
	For(i,1,n)
		write(a[i]),
		putchar(' ');
	return ;
}
void Sub1(){
    For(j,2,k){
        For(i,1,n)f[p[i]]=q[i];
        For(i,1,n)p[i]=q[i];
        For(i,1,n)q[i]=f[i];
//        cout<<i<<':'<<endl;
//        For(i,1,n)cout<<f[i]<<' ';cout<<endl;
    }out(f);exit(0);
}
void Sub2(){
	int t=1;
	For(i,1,n)pp[i]=p[i];
	For(i,1,n)qq[i]=q[i];
	int jj=1;
	while(jj++){
//		cout<<j<<' ';
		For(i,1,n)f[p[i]]=q[i];
        For(i,1,n)p[i]=q[i];
        For(i,1,n)q[i]=f[i];
        if(k==jj)out(f),exit(0);
        int flg=1;
        For(i,1,n)
        	if(pp[i]!=f[i])
			flg=0;
        if(flg){t=jj;break;}
	}t=t*n;k%=t;
//	cout<<t<<' '<<k<<endl;
	if(k==0)out(pp),exit(0);
	if(k==1)out(qq),exit(0);
	For(i,1,n)p[i]=pp[i];
	For(i,1,n)q[i]=qq[i];
	For(j,2,k){
		For(i,1,n)f[p[i]]=q[i];
        For(i,1,n)p[i]=q[i];
        For(i,1,n)q[i]=f[i];
	}out(f),exit(0);
}
signed main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
    read(n),read(k);
    For(i,1,n)read(p[i]);
    For(i,1,n)read(q[i]);
    if(k==0)out(p),exit(0);
	if(k==1)out(q),exit(0);
    if(n<=1000&&k<=1000)Sub1();
	if(n<=100&&k>=1000)
		Sub2();
    return 0;
}
/*
5 15
4 5 1 2 3
3 2 1 5 4
*/
