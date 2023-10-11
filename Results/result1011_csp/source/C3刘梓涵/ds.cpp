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
struct Node{
	int x,y,i;
}a[N];
int n,Q,h,top,s[N];
vector<Node>x[N];
bool cmp(Node a,Node b){
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
signed main(){
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	read(n),read(Q);
	For(i,1,n)a[i].i=i;
	For(i,1,n)read(a[i].x);
	For(i,1,n)read(a[i].y);
	sort(a+1,a+1+n,cmp);
	For(i,1,n)
	For(j,i+1,n)
	if(a[i].x<a[j].x&&a[i].y<a[j].y){
		x[i].PB(a[j]);
	}
	while(Q--){
		int u,r,d,l,ans=0;
		read(u),read(r);
		read(d),read(l);
		For(i,1,n){
			if(a[i].x<d)continue;
			if(a[i].x>u)break;
			if(a[i].y<l||a[i].y>r)continue;
			int kkk=0;
			Fo(j,x[i]){
				if(j.x>u)break;
				if(j.y>r)continue;
				kkk=1;
				break;
			}if(!kkk)ans++;
		}
		write(ans);puts("");
	}
	return 0;
}
/*
6 5
3 4 1 4 5 5
1 2 3 4 5 1
3 5 3 2
4 5 3 2
5 5 3 1
5 3 1 1
5 5 1 1
*/
