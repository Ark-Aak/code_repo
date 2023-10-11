#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
struct Node{
	double x;
	friend bool operator<(Node a,Node b){
		return a.x>b.x;
	}
};
priority_queue<Node>q;
const int N=1e6+5;
double a[N];
int n;
signed main(){
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),q.push((Node){a[i]});
	while(q.size()>1){
		double a=q.top().x;
		q.pop();
		double b=q.top().x;
		q.pop();
		double ans=((a+b)/2);
		q.push((Node){ans});
	}
	printf("%.6lf",q.top().x);
	return 0;
}


