#include<bits/stdc++.h>
using namespace std;
int n, k, m;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>k>>m;
	for(int i = 1; i <= m; ++i) {
		int x, y, z;
		cin>>x>>y>>z;
		if(z != 0) {
			cout<<0;
			return 0;
		}
	}
	cout<<n;
	return 0;
}
