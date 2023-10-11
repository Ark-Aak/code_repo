#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pt printf
#define For(i,a,b) for(int i=a;i<=b;++i)
#define Rof(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int Mxn=5e5+5;
int N,M,Q,Ans,P[Mxn],L[Mxn],R[Mxn],S[Mxn],X[Mxn];
vector<int> V[Mxn];
int _() {
	int x=0,f=0;char ch=gc();
	while(ch<'0'||ch>'9') f|=(ch=='-'),ch=gc();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	return f?-x:x;
}
void __(int x) {
	int stk[30],tp=0;
	if(x<0) x=-x,pc('-');
	do stk[++tp]=x%10,x/=10;while(x);
	while(tp) pc(stk[tp--]^48);
}
void Task1() {
	while(Q--) {
		M=_(),Ans=0;
		For(i,1,N) P[i]=0;
		For(i,1,M) P[_()]++;
		For(i,1,N) P[i]+=P[i-1];
		For(i,1,N) Ans+=(P[R[i]]-P[L[i]-1])&1;
		__(Ans),pc('\n');
	}
}
void Task2() {
	while(Q--) {
		M=_(),Ans=0;
		For(i,1,M) {
			X[i]=_();
			for(int k:V[X[i]]) {
				S[k]++;
				if(S[k]&1) ++Ans;
				else --Ans;
			}
		}
		For(i,1,M) {
			for(int k:V[X[i]]) {
				S[k]--;
			}
		}
		__(Ans),pc('\n');
	}
}
signed main() {
	freopen("badge.in","r",stdin);
	freopen("badge.out","w",stdout);
	N=_(),Q=_();
	bool Flag=1;
	For(i,1,N) {
		L[i]=_(),R[i]=_();
		if(R[i]-L[i]<=5) For(k,L[i],R[i]) {
			V[k].push_back(i);
		}
		else Flag=0;
	}
	if(Flag) Task2();
	else Task1();
	return 0;
}
