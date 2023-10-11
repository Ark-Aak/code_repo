#include<bits/stdc++.h>
#define db doub
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
}
#define N 100005
#define Mod 1000000007
struct Node{
	int x,y,c;
}a[N];
int n,ans;
signed main(){
	freopen("imp.in","r",stdin);
	freopen("imp.out","w",stdout);
    read(n);
    For(i,1,n)read(a[i].x),read(a[i].y),read(a[i].c);
    For(i,1,n){
    	int c=abs(a[i].x-a[i].y);
    	int s=min(a[i].x,a[i].y);
    	int t=max(a[i].x,a[i].y);
    	int sum=0;
    	For(j,1,n){
    		if(s<=a[j].x&&a[j].x<=t&&
			   s<=a[j].y&&a[j].y<=t)
			   sum+=a[j].c;
		}ans=max(ans,sum-c);
	}cout<<ans;
    return 0;
}
/*
6
2 3 4
1 4 -4
0 0 2
1 0 -5
3 1 -1
1 1 3
*/
