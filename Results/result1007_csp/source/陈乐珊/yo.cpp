#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
bool p;
ll f10[20];
string s,t;
string ans[2]={"oimiya","yoimiya"};
int main() {
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	cin>>n;
	srand(n);
	cin>>s>>t;
	int u=0;
	for(int i=0;i<n;i++)
		if(t[i]=='y') u++;
	if(u==0) {
		cout<<ans[0];
		return 0;
	}
	cout<<ans[rand()%2];
	return 0;
}

