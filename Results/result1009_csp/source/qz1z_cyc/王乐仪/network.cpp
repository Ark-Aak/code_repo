#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;char c=getchar();
	while(c<48||c>57) {if(c=='-') w=-1;c=getchar();}
	while(c>=48&&c<=57) s=(s<<1)+(s<<3)+c-48,c=getchar();
	return s*w;
}
vector<int>e[1000006];
int d[1000006];
//int b[1000006][22],s[1000006][22];
//int f[1000006];
//void dfs(int x,int fa){
//	b[x][0]=fa;
//	d[x]=d[fa]+1;
//	s[x][0]=min(x,fa);
////	cout<<x<<":"<<b[x][0]<<" ";
//	for(int i=1;i<=20;i++){
//		b[x][i]=b[b[x][i-1]][i-1];
////		if(b[x][i])cout<<b[x][i]<<" ";
//		if(b[x][i])s[x][i]=min(s[x][i-1],s[b[x][i-1]][i-1]);
//	}
////	cout<<"\n";
//	for(int i=0;i<e[x].size();i++){
//		if(e[x][i]!=fa){
//			dfs(e[x][i],x);
//		}
//	}
//}
//int lca(int x,int y){
//	if(x==y)return x;
//	int ans=999999999;
//	if(d[x]>d[y])swap(x,y);
//	for(int i=20;i>=0;i--){
//		if(d[b[y][i]]>=d[x]){
//			ans=min(ans,s[y][i]);
//			y=b[y][i];
////			cout<<y<<"\n";
//		}
//	}
////	cout<<x<<" "<<y<<"\n";
//	if(x==y)return ans;
//	for(int i=20;i>=0;i--){
//		if(b[y][i]!=b[x][i]){
//			ans=min(ans,min(s[y][i],s[x][i]));
//			y=b[y][i];
//			x=b[x][i];
////			cout<<x<<" "<<y<<"\n";
//		}
//	}
//	return min(ans,min(s[x][0],s[x][0]));
//}
void dfs(int x,int f){
	d[x]=min(d[f],x);
	for(int i=0;i<e[x].size();i++){
		if(f!=e[x][i]){
			dfs(e[x][i],x);
		}
	}
}
int main() {
//	freopen("network.in","r",stdin);
//	freopen("network.out","w",stdout);
	int n,q;
	n=read();
	q=read();
	for(int i=1;i<=n-1;i++){
		int x,y;
		x=read(),y=read();
		e[x].push_back(y);
		e[y].push_back(x);
	}
//	dfs(1,0);
	int jc1=0;
	string o;
	int x,ans=99999999;
	cin>>o;
	x=read();
//	jc1=x;
	d[0]=99999999;
	dfs(x,0);
	for(int i=1;i<q;i++){
		cin>>o;
		x=read();
		if(o=="Query"){
//			cout<<min(lca(x,jc1),ans)<<"\n";
			cout<<min(d[x],ans);
		}
		else{
//			ans=min(ans,lca(x,jc1));
			ans=min(ans,d[x]);
		}
	}
	return 0;
}


