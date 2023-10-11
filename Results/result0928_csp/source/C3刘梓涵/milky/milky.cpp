#include<bits/stdc++.h>
#define int long long
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
#define Mod (1<<32)
int n,q,l,r;
int f[N][5];
int g[5];
string s;
int mod(int x){
	if(x>=Mod)x-=Mod;
	return x;
}
signed main(){
	freopen("milky.in","r",stdin);
	freopen("milky.out","w",stdout);
    cin>>s;s=' '+s;
    n=s.size()-1;
    cin>>q;
    if(n<=1000&&q<=1000){
    	while(q--){
    		mem(g,0);
    		read(l),read(r);
    		For(i,l,r){
    			if(s[i]=='m')g[0]++,g[0]=mod(g[0]);
    			if(s[i]=='i')g[1]+=g[0],g[1]=mod(g[1]);
    			if(s[i]=='l')g[2]+=g[1],g[2]=mod(g[2]);
    			if(s[i]=='k')g[3]+=g[2],g[3]=mod(g[3]);
    			if(s[i]=='y')g[4]+=g[3],g[4]=mod(g[4]);
			}printf("%lld\n",g[4]);
		}
	}else{
		For(i,1,n){
			For(j,0,4)f[i][j]=f[i-1][j];
			if(s[i]=='m')f[i][0]++,f[i][0]=mod(f[i][0]);
    		if(s[i]=='i')f[i][1]+=f[i-1][0],f[i][1]=mod(f[i][1]);
    		if(s[i]=='l')f[i][2]+=f[i-1][1],f[i][2]=mod(f[i][2]);
    		if(s[i]=='k')f[i][3]+=f[i-1][2],f[i][3]=mod(f[i][3]);
    		if(s[i]=='y')f[i][4]+=f[i-1][3],f[i][4]=mod(f[i][4]);
		}while(q--){
			read(l),read(r);
			printf("%lld\n",f[r][4]);
		}
	}
    
    return 0;
}
