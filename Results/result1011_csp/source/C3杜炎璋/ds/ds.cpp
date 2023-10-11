#include<bits/stdc++.h>
using namespace std;
namespace fastio{
    struct{template<typename T>operator T(){
        T x=0;char f=0,c=getchar();
        while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
        while(c>='0'&&c<='9'){x=x*10+(c^48);c=getchar();}
        return f?-x:x;
    }}in;int stk[40],tp;
    template<typename T>void out(T x,char c=0){
        if(x<0)putchar('-'),x=-x;
        do stk[++tp]=x%10,x/=10;while(x);
        while(tp)putchar(stk[tp--]^48);
        if(c)putchar(c);
    }
}using fastio::in;using fastio::out;
int n,Q,cnt[1000005];
struct node {
	int x,y;
}a[1000005];
vector<int> q[1000005];
int main(){
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	n=in,Q=in;
	for(int i=1;i<=n;i++) a[i].x=in;
	for(int i=1;i<=n;i++) {
		a[i].y=in;
		q[a[i].x].push_back(a[i].y);
	}
	for(int i=1;i<=n;i++) sort(q[i].begin(),q[i].end());
	while(Q	--) {
		int u,r,d,l,sum=0;
		u=in,r=in,d=in,l=in;
		int y=l;
		for(int i=u;i>=d;i--) {
			int maxn=0;
			for(int j=0;j<q[i].size();j++) {
				if(q[i][j]>=y && q[i][j]<=r) maxn=max(maxn,q[i][j]),sum++;
				if(q[i][j]>r) break;
			}
			y=max(y,maxn);
		}
		printf("%d\n",sum);
	}

	return 0;
}

