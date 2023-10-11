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
#define N 500005
#define Mod 998244353
struct Node{
	int i,f;
};
int n,m;
int h[N],t[N],ans[N];
queue<Node>q;
void bfs(int X,int anss,int now){
	int c=q.empty();
	while(c--){
		int kkk=0;
		Node x=q.front();q.pop();
		if(!x.f){
			while(h[x.i+1]<X&&x.i+1<=n){
				x.i++;
				if(x.i==q.front().i){
					kkk=1;break;
				}
			}	
		}else while(h[x.i-1]<X&&x.i-1>0)x.i--;
		q.push(x);
		if(kkk)q.pop(),q.pop(),anss--,c--;
	}ans[now]=anss;
}
signed main(){
	freopen("gaze.in","r",stdin);
	freopen("gaze.out","w",stdout);
    read(n),read(m);
    For(i,1,n)read(h[i]);
//    if(n<=2000){
	    while(m--){
	    	int opt,x,y;
	    	cin>>opt>>x;
	    	if(opt==1){
	    		int l=0,r=n+1,ans=1;
	    		while(l+1<=n&&h[l+1]<x)l++;
	    		while(r-1>0&&h[r-1]<x)r--;
	    		if(l>r){
	    			printf("0\n");
	    			continue;
				}
	    		For(i,l+1,r-1)
	    			if(h[i]<x&&h[i-1]>=x)
					ans++;
				printf("%lld\n",ans);
			}else{
				cin>>y;
				h[x]=y;
			}
		}	
//	}else{
//		int opt;
//		For(i,1,m)read(opt),read(t[i]);
//		sort(t+1,t+1+m);
//		reverse(t+1,t+1+m);
//		int x=t[1],l=0,r=n+1,s=1;
//		while(l+1<=n&&h[l+1]<x)l++;
//		while(r-1>0&&h[r-1]<x)r--;
//		if(l>r){
//			For(i,1,m)printf("0\n");
//			return 0;
//		}
//		q.push((Node){l,0});
//		For(i,l+1,r-1){
//			if(h[i]<x&&h[i-1]>=x)s++,q.push((Node){i,1});
//			if(h[i]<x&&h[i+1]>=x)q.push((Node){i,0});	
//		}ans[1]=s;q.push((Node){r,1});
//		For(i,2,m){
//			bfs(t[i],ans[i-1],i);
//		}
//		For(i,1,m)printf("%lld\n",ans[i]);
//	}
    return 0;
}
/*
5 4
8
6
3
5
4
1 7
1 6
1 5
1 4
*/
