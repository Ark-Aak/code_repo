#include<bits/stdc++.h>
using namespace std;
string s;
int c[30],n;
signed main(){
	freopen("reinforce.in","r",stdin);
	freopen("reinforce.out","w",stdout);
	cin>>s;
	for(auto i:s){
		c[i-'a']++;
		n=max(n,c[i-'a']);
	}cout<<n;
	return 0;
} 
