#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct XXX{
	int a,b;
}z[100005],gg[100005];
struct XX{
	int a,b,c;
}qwq[100005];
bool vis[100005];
bool viss[100005];
bool cmp(XXX x,XXX y){
	return x.a>y.a;
}
bool cmb(XX x,XX y){
	return x.a<y.a;
}
signed main() {
	freopen("seal.in","r",stdin);
	freopen("seal.out","w",stdout);
	scanf("%lld%lld%lld",&n,&k,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld%lld",&z[i].a,&z[i].b);
	}
	for(int i=1;i<=n;i++){
		qwq[2*i-1].a=z[i].a;
		qwq[2*i-1].b=i;
		qwq[2*i-1].c=0;
		qwq[2*i].a=z[i].b;
		qwq[2*i].b=i;
		qwq[2*i].c=1;
	}
	sort(qwq+1,qwq+2*n+1,cmb);
	for(int j=1;j<=m;j++){
		for(int i=1;i<=2*n;i++){
			if(qwq[i+1].c==1&&qwq[i].c==0&&vis[qwq[i].b]){
				if(!viss[qwq[i+1].b]){
					gg[qwq[i+1].b].a+=qwq[i+1].a-qwq[i].a;
					viss[qwq[i+1].b]=1;
				}
			}
			if(qwq[i].c==0){
				gg[qwq[i].b].a+=qwq[i+1].a-qwq[i].a;
			}
			if(qwq[i].c==1&&qwq[i+1].c==1){
				gg[qwq[i+1].b].a+=qwq[i+1].a-qwq[i].a;
			}
			gg[i].b=i;
		} 
		int maxx=0,p=0;
		for(int i=1;i<=n;i++){
			if(vis[gg[i].b]) continue;
			if(gg[i].a>maxx){
				maxx=gg[i].a;
				p=i;
			}
		}
		vis[gg[p].b]=1;
	}/*
	sort(gg+1,gg+n+1,cmp);
	for(int i=1;i<=m;i++){
		vis[gg[i].b]=1;
	}*/
	
	for(int i=1;i<=2*n;i++){
		if(qwq[i].c==0){
			if(vis[qwq[i].b]){
				if(qwq[i+1].c==1&&!vis[qwq[i+1].b]){
					k-=qwq[i+1].a-qwq[i].a;
				}
			}
			else{
				k-=qwq[i+1].a-qwq[i].a;
			}
		}
		else{
			if(qwq[i+1].c==1&&!vis[qwq[i+1].b]){
				k-=qwq[i+1].a-qwq[i].a;
			}
		}
	}
	cout<<k;
	return 0;
}//ÒªÓÃprintf£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 

