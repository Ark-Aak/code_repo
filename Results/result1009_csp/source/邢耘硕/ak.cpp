#include <bits/stdc++.h>
using namespace std;
const long long inf=114514191981066;
const int N=1e6+6;
int n,a[N],k,cnt;
long long f[N],ans;
bool vis[N];
long long sum;
long long query(int l){
	long long temp=0,cnt=0;
	for(int i=l;i <= n&&cnt<k;i++){
		if(!vis[i]){
			cnt++;
			temp+=a[i];
		}
	}
	if(cnt<k)return -inf;
	return temp;
}
int main(){
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)cin >> a[i];
	if(k==1){
		sort(a+1,a+1+n);
		int l=1,r=n;
		while(l<r){
			sum+=a[l++];
			if(l<=r)break;
			sum+=a[r--];
			if(l<=r)break;
		}
		cout << sum;
	}
	else{
		int op=0;
		while(1){
			long long mx=-inf,id=-1,mn=inf;
			for(int i = 1;i <= n;i++){
				long long tmp;
				tmp=query(i);
				if(tmp==-inf)continue;
				if(op==1){
					if(tmp>mx){
						mx=tmp;
						id=i;
					}
				}
				else{
					if(mn>tmp){
						mn=tmp;
						id=i;
					}
				}
			}
			if(id==-1)break;
			for(int i = id;i <= id+k-1;i++)vis[i]=1;
			if(op==1)ans+=mx;
			else ans+=mn;
			op=(op+1)%2;
		}
		cout << ans;
	}
	return 0;
}
