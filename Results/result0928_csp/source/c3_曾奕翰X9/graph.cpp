#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,a[N],ans,GG[N];
int l[N],r[N],tot; 
struct XXX {
	int a,b;
} z[N],gg[N];
bool cmp(XXX x,XXX y){
	if(x.a==y.a) return x.b<y.b;
	return x.a<y.a;
}
bool cmb(XXX x,XXX y){
	if(x.b==y.b) return x.a<y.a;
	return x.b<y.b;
}
int fa[N];
int find(int f){
	if(fa[f]==f) return f;
	return fa[f]=find(fa[f]);
}
signed main(){
	ios::sync_with_stdio(0);
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) {
		z[i].a=read(),z[i].b=read();
		fa[i]=i;
	}
	sort(z+1,z+n+1,cmp);
	int p=0;
	for(int i=1;i<=n;i++){
		if(z[i].a!=z[i-1].a)++p;
		z[i].a=p;
	}
	sort(z+1,z+n+1,cmb);
	p=0; 
	for(int i=1;i<=n;i++){
		if(z[i].b!=z[i-1].b)++p;
		z[i].b=p;
	}
	sort(z+1,z+n+1,cmp);
	tot=1;
	l[1]=1;
	for(int i=2;i<=n;i++)
		if(z[i].a!=z[i-1].a){
			r[tot]=i-1;
			l[++tot]=i;
		}
	r[tot]=n;
	/*for(int i=1;i<=n;i++){
		a[i]=gg[i].b;
		qzh[i]=min(qzh[i-1],gg[i].a);
		
	}*/ 
	GG[0]=-1;
	int pop=0;
	for(int i=tot;i>=1;i--){
		if(z[l[i]].b<=GG[pop]){
			pop--;	
		}
		if(z[l[i]].b>GG[pop]){
			pop++;
		}
		GG[pop]=max(GG[pop],z[r[i]].b);
	}
	cout<<pop;
	return 0;
}

//也就是说，如果前面没有点，就可以往后面找。 
