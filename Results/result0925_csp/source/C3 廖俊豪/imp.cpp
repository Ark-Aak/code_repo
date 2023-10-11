#include<bits/stdc++.h>
#define int long long 
#define mid ((l+r)/2)
#define ls (x<<1)
#define rs ((x<<1)|1)
using namespace std;
const int Inf=1000000000000000000;
int n,tot;
int ans=0;
int res=0;
struct node{
	int x,y,c;
}p[250005];
bool cmp(node A,node B){
	if(max(A.x,A.y)!=max(B.x,B.y))return max(A.x,A.y)<max(B.x,B.y);
	else return min(A.x,A.y)<min(B.x,B.y);
}
int d[500005];
int w[500005];
map<int,int>m;
int tree[4000005],tag[4000005];
void update(int x){
	tree[x]=max(tree[ls],tree[rs]);
}
void push_down(int x){
	tree[ls]+=tag[x];
	tag[ls]+=tag[x];
	tree[rs]+=tag[x];
	tag[rs]+=tag[x];
	tag[x]=0;
}
void modify(int x,int l,int r,int L,int R,int V){
	push_down(x);
	if(L<=l&&r<=R){
		tree[x]+=V;
		tag[x]+=V;
		return;
	}
	if(r<L||R<l)return;
	modify(ls,l,mid,L,R,V);
	modify(rs,mid+1,r,L,R,V);
	update(x);
}
int q(int x,int l,int r,int L,int R){
	push_down(x);
	if(L<=l&&r<=R){
		return tree[x];
	}
	if(r<L||R<l)return -Inf;
	return max(q(ls,l,mid,L,R),q(rs,mid+1,r,L,R));
}
int ask(int L,int R){
	return q(1,1,tot,L,R);
}
signed main(){
	freopen("imp.in","r",stdin);
	freopen("imp.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld %lld",&p[i].x,&p[i].y,&p[i].c);
		d[++tot]=p[i].x;
		d[++tot]=p[i].y;
	}
	sort(p+1,p+n+1,cmp);
	sort(d+1,d+tot+1);
	tot=0;
	m[d[1]]=++tot;
	w[tot]=d[1];
	for(int i=2;i<=2*n;i++)
		if(d[i]!=d[i-1]){
			m[d[i]]=++tot;
			w[tot]=d[i];
		}
	for(int i=1;i<=n;i++){
		p[i].x=m[p[i].x];
		p[i].y=m[p[i].y];
//		cout<<p[i].x<<" "<<p[i].y<<endl;
	}
	int last=max(p[1].x,p[1].y);
	int now=0;
	for(int i=1;i<=n;i++){
		while(now<tot&&now+1<=max(p[i].x,p[i].y)){
			now++;
			modify(1,1,tot,0,now-1,w[now-1]-w[now]);
		}
		modify(1,1,tot,1,min(p[i].x,p[i].y),p[i].c);
//		cout<<p[i].x<<" "<<p[i].y<<" "<<p[i].c<<endl;
		if(max(p[i].x,p[i].y)!=max(p[i+1].x,p[i+1].y)){
//			modify(1,1,tot,1,last,w[last]-w[max(p[i].x,p[i].y)]);
//			last=max(p[i].x,p[i].y);
//			cout<<"change"<<endl;
//			for(int i=1;i<=tot;i++){
//				cout<<i<<" ";
//			}cout<<endl;
//			for(int i=1;i<=tot;i++){
//				cout<<ask(i,i)<<" ";
//			}cout<<endl;
//			cout<<tree[1]<<endl;
//			cout<<"----------------------"<<endl;
			ans=max(ans,tree[1]);
		}
//		for(int i=1;i<=tot;i++){
//			cout<<i<<" ";
//		}cout<<endl;
//		for(int i=1;i<=tot;i++){
//			cout<<ask(i,i)<<" ";
//		}cout<<endl;
//		cout<<"----------------------"<<endl;
	}
	cout<<ans<<endl;
	return 0;
}/*
6
2 3 4
1 4 -4
0 0 2
1 0 -5
3 1 -1
1 1 3
*/
/*
5
3 3 0
0 2 -1
3 1 3
0 0 -2
3 3 -3

*/
/*
	d[++tot]=max(p[1].x,p[1].y);
	s[tot]=p[1].c;
	for(int i=2;i<=n;i++){
		if(max(p[i].x,p[i].y)!=max(p[i-1].x,p[i-1].y)){
			d[++tot]=max(p[i].x,p[i].y);
		}
		s[tot]+=p[i].c;
	}
	ans=s[1];
	res=s[1];
	
	for(int i=2;i<=tot;i++){
		int sum=s[i]-d[i]+d[i-1];
		res+=sum;
		res=max(res,s[i]);
		cout<<d[i]<<" "<<res<<endl;
		ans=max(ans,res);
	}
	printf("%d",ans);
*/
