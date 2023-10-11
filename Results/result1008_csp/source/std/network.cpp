#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int ans,n,q,lst,a[N];
vector<int>g[N];
inline void add(int x,int y){g[x].push_back(y);}
void dfs(int x,int fa){
	a[x]=x;
	if(fa) a[x]=min(a[x],a[fa]);
	for(auto y:g[x])
		if(y!=fa) dfs(y,x);
}
char opt[15];

inline int read(void){
	int res,f=1;
	char c;
	while((c=getchar())<'0'||c>'9')
		if(c=='-') f=-1;
	res=c-48;
	while((c=getchar())>='0'&&c<='9')
		res=res*10+c-48;
	return res*f;
}

void print(int x){
	if(x>9) print(x/10);
	putchar(x%10+'0');
	return;
}

char fir;

inline void rc(void){
	for(fir=getchar();fir!='J'&&fir!='Q';fir=getchar()) ;
	for(;getchar()!=' ';);
}

signed main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
//	cin>>n>>q;
	n=read(),q=read();
	for(int x,y,i=1;i<n;++i)
		x=read(),y=read(),add(x,y),add(y,x);
	int x;
	rc(),x=read();
	dfs(x,0),ans=x;
	while(--q){
		rc(),opt[0]=fir,x=read();
		if(opt[0]=='J') ans=min(ans,a[x]);
		else print(lst=min(ans,a[x])),puts("");
	}
}
