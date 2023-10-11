#include <bits/stdc++.h>
#define ll long long
using namespace std;
string S;
ll ans,b[1000];
int main(){
	freopen("reinforce.in","r",stdin);
	freopen("reinforce.out","w",stdout);
	cin>>S;
	for(int i=0;i<S.size();i++)
		ans=max(ans,++b[S[i]]);
	printf("%lld",ans);
	return 0;
}
/*
mildredree 
*/

