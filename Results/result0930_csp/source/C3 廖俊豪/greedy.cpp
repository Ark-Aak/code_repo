#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int Inf=1e18;
const int mod=147744151;
int n,k;
int g[1000005][2];
int maxn=1e6;
int sol(int x){
	int l=1,r=x;
	int res=0;
	while(l<r){
		int mid=(l+r-1)/2;
		res++;
		if(mid-l+1>=r-mid){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	return res;
}
signed main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	cin>>n>>k;
	if(k>=60){
		cout<<sol(n);
		return 0;
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	n--;
	if(k==1){
		cout<<n%mod<<endl;
	}else if(k==2){
		int l=1,r=2*sqrt(n);
		while(l<r){
			int mid=(l+r)/2;
			if(mid*(mid+1)/2>=n){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		cout<<l%mod<<endl;
	}else{
		for(int i=1;i<=maxn;i++)g[i][1]=1;
		for(int j=2;j<=k;j++){
			g[1][j&1]=1;
			int sum=1;
			int res;
			for(int i=2;i<=maxn;i++){
				g[i][j&1]=g[i-1][j&1]+g[i-1][1-(j&1)];
				sum+=g[i][j&1];
				res=i;
				if(sum>=n)break;
			}
		}
		int sum=0;
		for(int i=1;i<=maxn;i++){
			sum+=g[i][k&1];
			if(sum>=n){
				cout<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}
/*

//	for(int l=1;l<=k;l++){
//		if(l==1){
//			for(int i=1;i<=n;i++)f[i][l]=i-1;
//		}else{
//			f[1][l]=0;
//			for(int i=2;i<=n;i++){
//				f[i][l]=Inf;
//				for(int j=1;j<=i;j++){
//					if(max(f[j][l-1],f[i-j][l])+1<f[i][l]){
//						b[i][l]=j;
//						cout<<"f["<<i<<"]["<<l<<"]=max{f["<<j<<"]["<<l-1<<"]("<<f[j][l-1]<<"),f["<<i-j<<"]["<<l<<"]("<<f[i-j][l]<<")}+1"<<endl;
//						f[i][l]=max(f[j][l-1],f[i-j][l])+1;
//					}
//				}
//			}
//		}
//	}

*/
