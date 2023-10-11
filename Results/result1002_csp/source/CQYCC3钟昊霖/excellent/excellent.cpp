#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define F(i,a,b) for(int i=a;i<=b;i++)

const int N=2e5+5;

string s;
int T,vis[55][55];

inline void Subtask2(){
	int ans=0;
	int len=s.size();
	for(int i=4;i<=len;i+=2)
		ans+=(len-i+1);
	cout<<ans<<'\n';
	return;
}

inline bool Check1(int x,int y){
	int l=x,r=y;
	int mid=l+r>>1;
	int r1=mid,l1=mid+1;
	int Q=l1;
	while(l!=l1){
		if(s[l]==s[Q]||s[l]=='?'||s[Q]=='?') l++,Q++;
		else return false;
	}
	return true;
}

inline int Check(int l,int r){
	int ans = 0;
	for(int i=l+1;i<r;i+=2){
		if(Check1(l,i)&&Check1(i+1,r)) ans++;
	}
	return ans;
}

inline void Subtask1(){
	int ans = 0;
	int len=s.size();
	for(int l=0;l<len;l++)
	for(int r=l+3;r<len;r+=2)
	{ans+=Check(l,r);}
	cout<<ans<<'\n';
	return;
}	

signed main(){
	freopen("excellent.in","r",stdin);
	freopen("excellent.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>s;
		int falg=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='?') falg++;
		}
		if(falg==s.size()) Subtask2();
		else Subtask1();

	}

 	return 0;
}
