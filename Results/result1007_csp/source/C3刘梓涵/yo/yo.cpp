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
#define N 1000005
#define Mod 998244353
#define int long long
int n,ans,kkk,o,y;
char s[N],a[N];
signed main(){
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
//	For(i,100,200)cout<<i*11<<endl;
	read(n);
	scanf("%s %s",a+1,s+1);
	For(i,1,n)if(s[i]=='o')y=1;
	else o=1;
	if(!y)puts("yoimiya");
	if(!o) puts("oimiya");
	if(!y||!o)return 0;
	For(i,1,n){
		if(s[i]=='o'){
			if(ans){
				puts("oimiya");
				return 0;
			}
			kkk=1;
		}
		if(kkk)ans=ans*10+a[i]-'0',ans%=11;
		if(!ans)kkk=0;
	}
	if(ans)puts("oimiya");
	else puts("yoimiya");
    return 0;
}

