#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s;
bool vis[257];
int a[257],tot,gg;
signed main() {
	freopen("reinforce.in","r",stdin);
	freopen("reinforce.out","w",stdout);
	cin>>s;
	n=s.size();
	s=' '+s;
	int now=1;
	for(int i=1;i<=n;i++){
		if(!vis[(int)(s[i]-'a')]){
			if(now==1){
				a[++tot]=(int)(s[i]-'a');
				now++;
			}else{
				for(int j=tot;j>=now;j--)
					a[j+1]=a[j];
				tot++;
				a[now]=(int)(s[i]-'a');
				now++;
				
			}
		}
		else{
			if(now>tot) now=1,gg++;
			while(a[now]!=(int)(s[i]-'a')){
				if(now>tot) now=1,gg++;
				now++;
				if(now>tot) now=1,gg++;
			}
			now++;
			if(now>tot) now=1,gg++;
		}
		vis[(int)(s[i]-'a')]=1;
	} 
	if(now==1) gg--;
	cout<<gg+1;
	return 0;
}//ÒªÓÃprintf£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡

