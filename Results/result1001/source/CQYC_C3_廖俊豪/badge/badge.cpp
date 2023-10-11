#include<bits/stdc++.h>
using namespace std;
int n,m,q,len;
struct node{
	int l,r;
}p[300005];
bool cmp(node A,node B){
	if(A.l/len!=B.l/len)return A.l/len<B.l/len;
	else return A.r<B.r; 
}
int s[300005];
int l=0,r=0,now=0;
void w(int x){
	now=(s[x]==q);
	return;
}
signed main(){
	freopen("badge.in","r",stdin);
	freopen("badge.out","w",stdout);
	scanf("%d %d",&n,&q);
	len=sqrt(n);
	for(int i=1;i<=n;i++)scanf("%d %d",&p[i].l,&p[i].r);
	sort(p+1,p+n+1,cmp);
	while(q--){
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			int x;
			scanf("%d",&x);
			s[x]=q;
		}
		int ans=0;
		l=0,r=0,now=0;
		for(int i=1;i<=n;i++){
			while(p[i].l<l)w(--l);
			while(p[i].l>l)w(l++);
			while(p[i].r>r)w(++r);
			while(p[i].r<r)w(r--);
			ans+=now;
		}
		printf("%d\n",ans);
	}
}/*
5 2
4 5
3 5
2 4
2 3
5 5
2
2 5
3
1 2 5


*/ 
