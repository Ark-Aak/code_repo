#include<bits/stdc++.h>
using namespace std;

#define int long long
#define F(i,a,b) for(int i=a;i<=b;i++)
#define Debug(x) cerr<<"------------"<<x<<"---------------"<<endl

const int N = 3e5 + 5;

inline int read();

int T = 1, n, m, a[N],b[N],ans[N];

struct node{
	int opt,id,x,u,v;
}Q[N];

struct number{
	int num,id;
}Num[N];

inline void Solve(int x){
	int ans = 0;
	F(i,1,n) b[i]=(a[i]>=x);
	for(int i=1,l=0,r=0;i<=n+1;i++){
		if(b[i]) {if(!l) l=i;r=i;}
		else{
			if(l==0||r==0) continue;
			ans++;
			l=0,r=0;
		}
	}
	cout<<ans<<endl;
	return;
}

inline void Subtask1() {
	for (int i = 1, opt, u, v; i <= m; i++) {
		opt=read();
		if (opt == 1) {
			u=read();
			Solve(u);
		}
		if (opt == 2) {
			u=read(),v=read();
			a[u]=v;	
		}
	}
}

inline bool cmp(node a,node b){
	return a.x>b.x;
}

inline bool cmb(number a,number b){
	return a.num<b.num;
}


inline void Subtask2() {
	F(i,1,n) Num[i].num=a[i],Num[i].id=i;
	sort(Q+1,Q+m+1,cmp);//把大小从大到小排序，如果一个点左右两边都是点 ans ++
	//点可以通过排序单调性维护
	sort(Num+1,Num+n+1,cmb);
	int l=n,Ans=0;
	F(i,1,m){
		while(Num[l].num>=Q[i].x){
			if(!b[Num[l].id-1]&&!b[Num[l].id+1]) Ans++;
			if(b[Num[l].id-1]&&b[Num[l].id+1]) Ans--;
			b[Num[l].id]=1;
			l--;
		}
		ans[Q[i].id]=Ans;
	}
	F(i,1,m) cout<<ans[i]<<endl;
	return;
}

inline void Subtask3() {

}

inline void SubtaskOther(){
	int de=0;
	for(int i=1;i<=m;i++){
		Q[i].opt=read();
		if(Q[i].opt==1){
			Q[i].x=read();
		}
		if(Q[i].opt==2){
			de=1;
			Q[i].u=read(),Q[i].v=read();
		}
		Q[i].id=i;
	}
	if(!de) Subtask2();
	else Subtask3();
	return;
}


signed main() {
	freopen("gaze.in","r",stdin);
	freopen("gaze.out","w",stdout);
	while (T--) {
		n=read(),m=read();
		F(i, 1, n) a[i]=read();
		if (n <= 2000 && m <= 2000) {
			Subtask1();
			return 0;
		}
		SubtaskOther();
	}
	return 0;
}

inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f *= -1;
		c = getchar();
	}
	while (c <= '9' && c >= '0') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
