#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,ops,ops2;
//int g[3005][3005],f[3005][3005];
int ha[3005][3005];
int L[3005],R[3005];
string s;
bool check(int x,int y){
	if(s[x]==s[y]||s[x]=='?'||s[y]=='?')return 1;
	else return 0;
}
bool w(int l,int r){
	if((r-l+1)&1)return 0;
	if(ops)return 1;
	if(ops2)return ha[l][(l+r-1)/2]==ha[(l+r+1)/2][r];
	int mid=(l+r-1)/2;
	for(int i=l,j=mid+1;i<=mid;i++,j++)
		if(!check(i,j))return 0;
	return 1;
}
signed main(){
	freopen("excellent.in","r",stdin);
	freopen("excellent.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		s.clear();
		memset(L,0,sizeof L);
		memset(R,0,sizeof R);
		cin>>s;
		n=s.size();
		s=' '+s;
//		for(int i=2;i<=n;i++){
//			if(check(i,i-1)){
//				g[i][i]=1;
//				f[i-1][i]=1;
//			}
//		}
//		for(int i=2;i<=n;i++){
//			for(int l=1;l+i-1<=n;l++){
//				int r=l+i-1;
//				if(g[l+1][r]&&check(l,l-1))g[l][r]=1;
//			}
//		}
////		for(int i=4;i<=n;i++){
////			for(int l=1;l+i-1<=n;l++){
////				int r=l+i-1;
////				f[l][r]=f[l+1][r-1]&&g[l+1][(l+r-1)>>1]&&check(((l+r-1)>>1),r);
////			}
////		}
		ops=1,ops2=1;
		for(int i=1;i<=n;i++)
			if(s[i]!='?')ops=0;
			else ops2=0;
		if(ops2){
			memset(ha,0,sizeof ha);
			for(int i=1;i<=n;i++){
				ha[i][i]=s[i]-'a';
				for(int j=i+1;j<=n;j++)
					ha[i][j]=(ha[i][j-1]*31+s[j]-'a')%mod;
			}
		}
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				int res=w(l,r);
				L[l]+=res;
				R[r]+=res;
			}
		}
		int ans=0;
		for(int i=1;i<n;i++)ans+=R[i]*L[i+1]; 
		cout<<ans<<endl;
	} 
	return 0;
}
