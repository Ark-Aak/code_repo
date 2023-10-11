#include<bits/stdc++.h>
using namespace std;
string s;
int b[26][26],ans;
int in[26],out[26],vis[26];
signed main(){
	freopen("reinforce.in","r",stdin);
	freopen("reinforce.out","w",stdout);
	cin>>s;
	for(int i=1;i<s.size();i++){
		b[s[i-1]-'a'][s[i]-'a']++;
		out[s[i-1]-'a']++;
		in[s[i]-'a']++;
	}
	for(int i=0;i<26;i++)if(out[i]==0&&in[i]==0)vis[i]=1;
	for(int i=1;i<=26;i++){
		int minn=-1;
		for(int i=0;i<26;i++)if(vis[i]==0){minn=i;break;}
		if(minn==-1)break; 
		for(int i=0;i<26;i++)if((in[i]<in[minn]||(in[i]==in[minn]&&out[i]>out[minn]))&&vis[i]==0)minn=i;
		ans+=in[minn];
//		cout<<char(minn+'a')<<" "<<in[minn]<<endl;
		vis[minn]=1;
		for(int i=0;i<26;i++)in[i]-=b[minn][i];
	}
	cout<<ans+1<<endl;
	return 0;
}///eddee 
