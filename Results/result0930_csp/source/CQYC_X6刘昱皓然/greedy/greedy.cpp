#include<bits/stdc++.h>
using namespace std;
long long n, k;
int main() {
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	cin>>n>>k;
	if(k==1)	cout<<ceil((double)log2(n));
	else	cout<<1;
	return 0;
}
