#include<bits/stdc++.h>
using namespace std;

#define int long long
#define F(i,a,b) for(int i=a;i<=(b);i++)

inline int read();

const int N=700005;

int n,k,a[N],b[N],c[N];

vector<int> v[N];

inline void Subtask1() {
	while(k--) {
		F(i,1,n) {
			c[a[i]]=b[i];
		}
		F(i,1,n) a[i]=b[i],b[i]=c[i];
	}
	F(i,1,n) cout<<a[i]<<" ";
}

inline void Subtask2() {
	int Kk=1e5;
	F(i,1,n) v[0].push_back(a[i]);
	F(j,1,Kk) {
		F(i,1,n) c[a[i]]=b[i];
		F(i,1,n) a[i]=b[i],b[i]=c[i];
		F(i,1,n) v[j].push_back(a[i]);
//		cout<<j<<":";
//		F(i,1,n) cout<<v[j][i-1]<<" ";
//		cout<<endl;
	}
	k%=Kk;
	F(i,1,n) cout<<v[k][i-1]<<" ";
}

signed main() {
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	n=read(),k=read();
	F(i,1,n) a[i]=read();
	F(i,1,n) b[i]=read();
	if(n<=1000&&k<=1000) {
		Subtask1();
		return 0;
	}
	if(n<=100&&k<=1000000000ll) {
		Subtask2();
		return 0;
	}

	return 0;
}

inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f*=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}

