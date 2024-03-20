#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,b) for(int i=1;i<=b;i++)
using namespace std;
char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N=2e5+5;
int n,m,k;
int ans;
struct node{
	int w,a;
}z[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
priority_queue<pii,vector<pii>,greater<pii> > q;

signed main(){
    n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++){
        z[i]={read(),read()};
		z[i].a=min(z[i].a,m);
	}
	sort(z+1,z+n+1,cmp);
	q.push({-1e16,m});
	for(int i=1;i<=n;i++){
		int now=0;
		while(!q.empty()){
			int x=q.top().first,y=q.top().second;
            if(x+k>z[i].w) break;
			q.pop();
			int g=min(z[i].a-now,y);
			now+=g,ans+=g;
			if(y-g>0)q.push({x,y-g});
			if(now==z[i].a) break;
		}
		if(now) q.push({z[i].w,now});
	}
    cout<<ans;
	return 0;
}
