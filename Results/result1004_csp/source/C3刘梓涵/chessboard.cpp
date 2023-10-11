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
#define N 3005
#define Mod 998244353
#define int long long
int n,m;
char a[N][N];
bool check(int x,int y){
    if((a[x][y]==a[x+1][y+1]&&a[x+1][y]==a[x][y+1]&&a[x+1][y]!=a[x][y]&&a[x][y]!='?'&&a[x+1][y]!='?')||
       (a[x][y]==a[x-1][y-1]&&a[x-1][y]==a[x][y-1]&&a[x-1][y]!=a[x][y]&&a[x][y]!='?'&&a[x-1][y]!='?')||
       (a[x][y]==a[x+1][y-1]&&a[x+1][y]==a[x][y-1]&&a[x+1][y]!=a[x][y]&&a[x][y]!='?'&&a[x+1][y]!='?')||
       (a[x][y]==a[x-1][y+1]&&a[x-1][y]==a[x][y+1]&&a[x-1][y]!=a[x][y]&&a[x][y]!='?'&&a[x-1][y]!='?'))
        return 1;
    return 0;
}
void End(){puts("No"),exit(0);}
signed main(){
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
    read(n),read(m);
    For(i,1,n)cin>>a[i]+1;
    For(i,1,n)
    For(j,1,n)
    if(check(i,j))
        End();
    For(i,1,n)
    For(j,1,n){
        if(a[i][j]=='?'){
            int aa=0,b=0;
            a[i][j]='1';
            if(check(i,j))aa=1;
            a[i][j]='0';
            if(check(i,j))b=1;
            if(aa&&b)End();
            if(aa)a[i][j]='0';
            else a[i][j]='1';
            if(i==2&&j==2)cout<<aa<<' '<<b<<endl;
        }
    }
    For(i,1,n)
    For(j,1,n)
    if(check(i,j))
        End();
    puts("Yes");
    For(i,1,n){
        For(j,1,n)
        printf("%c",a[i][j]);
        puts("");
    }
    return 0;
}
