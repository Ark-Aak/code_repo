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
struct node {
	int x,y,v;
}b[500005];
bool cmp(node x,node y) {
	return x.v>y.v;
}
vector<int> q[200005];
int dis[200005][2];
int main(){
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	int n,m;
	n=in,m=in;
	for(int i=1;i<=m;i++) {
		int x,y,z;
		x=in,y=in,z=in;
		b[i].x=x;b[i].y=y;b[i].v=z;
	}
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=m;i++) {
		int minnx=dis[b[i].x][1],maxnx=dis[b[i].x][0];
		int minny=dis[b[i].y][1],maxny=dis[b[i].y][0];
		if(!dis[b[i].x][1]) dis[b[i].x][1]=maxny+1;
		else dis[b[i].x][1]=min(dis[b[i].x][1],maxny+1);
		dis[b[i].x][0]=max(dis[b[i].x][0],minny+1);
		if(!dis[b[i].y][1]) dis[b[i].y][1]=maxnx+1;
		else dis[b[i].y][1]=min(dis[b[i].y][1],maxnx+1);
		dis[b[i].y][0]=max(dis[b[i].y][0],minnx+1); 
	}
	for(int i=1;i<=n;i++) out(dis[i][0],' ');
	return 0;
}

