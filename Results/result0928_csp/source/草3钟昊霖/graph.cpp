#include<bits/stdc++.h>
using namespace std;

#define int long long 

#define F(i,a,b) for(int i=a;i<=b;i++)

const int N=5e5+5;

int n,a[N],b[N],f[N];

bitset <N> vim; 

inline int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}



inline void Subtask1(){
	F(i,1,n) f[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]>=a[j]&&b[i]>=b[j]) f[find(j)]=find(i);
			if(a[i]<=a[j]&&b[i]<=b[j]) f[find(j)]=find(i);
		}
	}
	int ans = 0;
	F(i,1,n) {
		if(find(i)==i) ans++;
	}
	cout<<ans;
	return;
}

inline void Subtask2(){
	F(i,1,n) f[i]=i;
	for(int i=1;i<=n;i++){
		if(vim[i]) continue;
		vim[i]=1;
		for(int j=i+1;j<=n;j++){
			if(vim[j]) continue;
			if(a[i]>=a[j]&&b[i]>=b[j]) vim[j]=1,f[find(j)]=find(i);
			if(a[i]<=a[j]&&b[i]<=b[j]) vim[j]=1,f[find(j)]=find(i);
		}
	}
	int ans = 0;
	F(i,1,n) {
		if(find(i)==i) ans++;
	}
	cout<<ans;
//	queue<int> Q;
//	for(int i=1;i<=n;i++) Q.push(i);
//	int ans = 0;
//	queue<int> Q1;
//	while(!Q.empty()){
//		int t=Q.front();
//		ans++;
//		Q.pop();
//		while(!Q.empty()){
//			int t1=Q.front();
//			Q.pop();
//			if(a[t]>=a[t1]&&b[t]>=b[t1]){a[t]=min(a[t],a[t1]),b[t]=min(b[t],b[t1]);}
//			else if(a[t]<=a[t1]&&b[t]<=b[t1]){a[t]=min(a[t],a[t1]),b[t]=min(b[t],b[t1]);}
//			else Q1.push(t1);
//		}
//		Q=Q1;
//		while(!Q1.empty()) Q1.pop();
//	}
//	cout<<ans;
	return;
}

signed main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%lld",&n);
	F(i,1,n){
		scanf("%lld%lld",&a[i],&b[i]);
	}
	if(n<=5000) Subtask1();
	else {
		Subtask2();
	}
	return 0;
}
