#include<bits/stdc++.h>
using namespace std;
int n, k, a[100005], b[100005], c[100005], ans[100005], f[100005];
int main() {
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	cin>>n>>k;
	if(k <= 1000) {
		for(int i = 1; i <= n; ++i) {
			cin>>a[i];
		}
		for(int i = 1; i <= n; ++i) {
			cin>>b[i];
		}
		for(int i = 2; i <= k; ++i) {
			for(int j = 1; j <= n; ++j) {
				c[a[j]] = b[j];
			}
			for(int j = 1; j <= n; ++j) {
				a[j] = b[j];
				b[j] = c[j];
			}
		}
		for(int i = 1; i <= n; ++i) {
			cout<<c[i]<<" ";
		}
	}
	else {
		for(int i = 1; i <= n; ++i) {
			cin>>a[i];
		}
		for(int i = 1; i <= n; ++i) {
			cin>>b[i];
		}
		int id;
		for(int i = 2; i; ++i) {
			for(int j = 1; j <= n; ++j) {
				c[a[j]] = b[j];
			}
			for(int j = 1; j <= n; ++j) {
				a[j] = b[j];
				b[j] = c[j];
			}
			bool flag = false;
			for(int j = 1; j <= n; ++j) {
				if(c[j] != ans[j]) {
					flag = true;
					break;
				}
			}
			if(!flag) {
				id = i;
				break;
			}
		}
		if(k == k / id * id) {
			for(int i = 1; i <= n; ++i) {
				cout<<ans[i]<<" ";
			}
			return 0;
		}
		for(int i = 1; i <= n; ++i) {
			f[a[i]] = b[i];
		}
		for(int i = 1; i <= n; ++i) {
			a[i] = b[i];
			b[i] = f[i];
		}
		if(k == k / id * id + 1) {
			for(int i = 1; i <= n; ++i) {
				cout<<f[i]<<" ";
			}
			return 0;
		}
		cout<<id<<endl;
		for(int i = k / id * id + 2; i <= k; ++i) {
			for(int j = 1; j <= n; ++j) {
				f[a[j]] = b[j];
			}
			for(int j = 1; j <= n; ++j) {
				a[j] = b[j];
				b[j] = f[j];
			}
		}
		for(int i = 1; i <= n; ++i) {
			cout<<b[i]<<" ";
		}
	}
	return 0;
}
