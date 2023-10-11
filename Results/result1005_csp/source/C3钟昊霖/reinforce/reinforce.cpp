#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=a;i<=b;i++)

string s; 
int f[27],ans;

signed main(){
	freopen("reinforce.in","r",stdin);
	freopen("reinforce.out","w",stdout);
	cin>>s;
	int len = s.size();
	F(i,1,len){
		if(f[s[i-1]-'a']==0) f[s[i-1]-'a']=i;
	}
	int nb=0;
	F(i,0,len-1){
		if(nb<f[s[i]-'a']) nb=f[s[i]-'a'];
		else ans++,nb=f[s[i]-'a'];
	}
	cout<<ans+1;
	return 0;
}
//我最后一道题能拿60我磕头。 
