#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define F(i,a,b) for(int i=a;i<=b;i++)
#define Debug(x) cerr<<"------------"<<x<<"---------------"<<endl;

const int N=2e5+5;

inline int read();

int T=1;

signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	while(T--){
		system("fc gaze.out gaze2.ans");
		//cout<<102/3;
	}
	return 0;
}

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f*=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
