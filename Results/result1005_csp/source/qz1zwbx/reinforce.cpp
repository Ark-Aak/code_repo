#include<bits/stdc++.h>
using namespace std;
int a[30],ans,x;
string s;
int main(){
	freopen("reinforce.in","r",stdin);
	freopen("reinforce.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=1;i<=len;i++){
		x=(int)s[i-1]-'a'+1;
		a[x]++;
	}
	for(int i=1;i<=29;i++){
		ans=max(ans,a[i]);
	}
	cout<<ans<<endl;
	return 0;
}
