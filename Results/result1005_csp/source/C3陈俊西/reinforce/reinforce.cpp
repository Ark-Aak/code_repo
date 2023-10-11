#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
string s;
int fi[N],ss[N],tp,ans;
bool c[N];
signed main(){
	freopen("reinforce.in","r",stdin);
	freopen("reinforce.out","w",stdout);
	cin>>s;
	ans=N;
	for(int i=0;i<s.size();i++){
		if(!c[s[i]-'a']) fi[s[i]-'a']=0;
		c[s[i]-'a']=1;
	}
	for(int i=0;i<26;i++){
		memset(c,0,sizeof c);
		int res=0;
		tp=0;
		int ks=fi[i];
		for(int j=0;j<ks;j++)
			ss[++tp]=s[j]-'a',c[s[j]-'a']=1,res++;
		for(int j=ks;j<s.size();j++){
			if(c[s[j]-'a']){
				while(tp&&ss[tp]!=s[j]-'a') tp--,c[ss[tp]]=0;
				res++;
			} 
			else ss[++tp]=s[j]-'a',c[s[j]-'a']=1;
		}
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}
//reerer


