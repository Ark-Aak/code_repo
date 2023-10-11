#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e6+5;
int n,k;
ll ans,a[N],s,maxn;
bool out[N];
int main() {
	freopen("ak.in", "r", stdin);
	freopen("ak.out", "w", stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		s+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<=10) {
		int i=1;
		while(n>1) {
			int sum=0,ret=0,id=-1;
			for(int j=1;j<=k;j++) {
				sum+=a[j];
			}
			ret=sum;
			id=k;
			for(int j=k+1;j<=n;j++) {
				sum+=a[j];
				sum-=a[j-k];
				if(i==1&&sum<ret) {
					ret=sum;
					id=j;
				}
				if(i==2&&sum>ret) {
					ret=sum;
					id=j;
				}
			}
			for(int j=id-k+1;j<=id;j++) {
				a[j]=a[j+k];
			}
			n-=k;
			if(i==1) i=2;
			else i=1;
		}
		cout<<s-a[1];
		return 0;
	}
	if(k==1) {
		sort(a+1,a+n+1);
		int l=1,r=n;
		bool i=1;
		while(l!=r) {
			if(i) l++;
			else r--;
			i^=1;
		}
		cout<<s-a[l];
		return 0;
	}
	if(maxn<=2) {
		if(maxn==1) {
			cout<<s-1;
			return 0;
		}
		int t1=0,t2=0;
		for(int i=1;i<n;i++) {
			if(a[i]==1&&a[i+1]==1) {
				t1++;
				i++;
			}
			if(a[i]==2&&a[i+1]==2) {
				t2++;
				i++;
			}
		}
		if(t1>t2) t1=t2+1;
		else t2=t1;
		for(int i=1;i<n;i++) {
			if(a[i]==1&&a[i+1]==1&&t1) {
				t1--;
				a[i]=a[i+1]=0;
				i++;
			}
			if(a[i]==2&&a[i+1]==2&&t2) {
				t2--;
				a[i]=a[i+1]=0;
				i++;
			}
		}
		for(int i=1;i<=n;i++) {
			if(a[i]==1) t1++;
			if(a[i]==2) t2++;
		}
		if(t1>=t2) cout<<s-1;
		else cout<<s-2;
		return 0;
	}
	return 0;
}

