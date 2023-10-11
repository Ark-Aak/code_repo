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
#define N 2005
#define Mod 1000000007
#define int long long
int n,m;
int ans[N][N];
int calc(int x,int y){
	int g=__gcd(x,y);
	x/=g,y/=g;
	return (x+x+y+y-3)/2;
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	For(i,1,1000)
	For(j,1,1000){
		ans[i][j]=calc(i,j)%Mod;
		ans[i][j]+=(ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]+Mod)%Mod;
		ans[i][j]%=Mod;
	}
	int T;
	read(T);
	while(T--){
		int x,y;
		read(x),read(y);
		write(ans[x][y]);
		puts("");
	}
	return 0;
}
/*
1 2 3 4 5 6 7
2 1 5 2 5 3
3 5 1 5 6 2
4 2 5 1 7
5 5 6 7
6 3 2
7
*/
