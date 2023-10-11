#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,cnt; 
int a[10005],ans,vis[10005],mx;
int num[20];
void dfs(int step){
	if(step>n){
		memset(num,0,sizeof(num));
		for(int i=1;i<=cnt;i++){
			num[vis[i]]++;
		}
		for(int i=0;i<=10;i++){
			if(!num[i]){
				ans+=i;
				break;
			}
		}
		return;
	}
	for(int i=0;i<=a[step];i++){
		vis[step]=i;
		dfs(step+1);
	}
}
signed main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout); 
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i],mx=max(mx,a[i]);
	dfs(1);
	cout << ans%mod << "\n";
	return 0;
}


