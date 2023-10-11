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
#define N 4005
#define Mod 998244353
#define int long long
int n,m,ans;
int ks[10];
char a[N][N];
int mod(int x){
	if(x>=Mod)x-=Mod;
	return x;
}
int ksm(int a,int b){
    int res=1;
    while(b){
        if(b&1)res=res*a%Mod;
        a=a*a%Mod;
        b>>=1;
    }return res;
}
int calc(int x,int y,int z){
    int xy=a[x][y]+a[y][x];
    int xz=a[x][z]+a[z][x];
    int yz=a[y][z]+a[z][y];
    int s,t=xy+xz+yz;
//    cout<<x<<" "<<y<<' '<<z<<":"<<' '<<s<<' '<<t<<" ";
    if(a[x][y]&&a[z][y])return 0;
    if(a[y][x]&&a[z][x])return 0;
    if(a[x][z]&&a[y][z])return 0;
    if(a[x][y]&&a[x][z])return 0;
    if(a[y][x]&&a[y][z])return 0;
    if(a[z][x]&&a[z][y])return 0;
    if(!t)s=2;else s=1;
//    cout<<s*ksm(2,m-(3-t));
    return ks[m-(3-t)+(s==2)-(m-3)];
}
signed main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
    read(n);
    For(i,1,n)
        scanf("%s",a[i]+1);
    For(i,1,n)
    For(j,1,n)
        a[i][j]-='0',
        m+=a[i][j];
    m=n*(n-1)/2-m;
//    cout<<1;
    For(i,m-3,m+1)ks[i-(m-3)]=ksm(2,i);
//    cout<<1;
    For(i,1,n)
    For(j,i+1,n)
    For(k,j+1,n){
        if(n<=500)ans=(ans+calc(i,j,k))%Mod;
        else ans=mod(ans+calc(i,j,k));
//        cout<<endl;
    }
//    cout<<m<<endl;
    write(ans);
    return 0;
}
/*
4
0100
0010
0000
1000

3
000
000
000

4
0000
0000
0000
0000

6
011111
001111
000111
000011
000001
000000

5
00000
00000
00000
00000
00000

6
000000
000000
000000
000000
000000
000000
*/
