#include<bits/stdc++.h>
using namespace std;
int n,cnt,a[1000005],ans,k;
int main(){
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cnt=n;
	sort(a+1,a+1+n);
	for(int i=1;i<=(n-1)/2;i++){
		ans+=a[i];
		ans+=a[n-i+1];
		cnt-=2;
	}
	if(cnt>1){
		ans+=a[(n-1)/2+1];
	}
	cout<<ans;
	return 0;
}

