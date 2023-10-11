 #include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N=5e4+5,inf=1e18;
int n,k;
int a[N];
char mp[55][55];
int dis[55][55];
vector<int> vis[55];
signed main(){
	freopen("ex_tower1.in","r",stdin);
//	freopen("tower.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=50;i++){
		for(int j=1;j<=50;j++) dis[i][j]=inf;
	}
	for(int i=1;i<=n;i++) a[i]=read(),vis[a[i]].push_back(i);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			cin >> mp[i][j];
			if(mp[i][j]=='1'){
//				cout << i << " " << j << "\n";
				for(int ud=0;ud<(int)vis[i].size();ud++){
					int u=vis[i][ud];
					for(int vd=0;vd<(int)vis[j].size();vd++){
						int v=vis[j][vd];
						dis[i][j]=min(dis[i][j],abs(u-v));
					}
				}
			}
		}
	}
	for(int m=1;m<=k;m++){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=k;j++){
				if(dis[i][j]>dis[i][m]+dis[m][j]) dis[i][j]=dis[i][m]+dis[m][j];
			}
		}
	}
	if(dis[a[1]][a[n]]>=inf) cout << -1;
	else cout << dis[a[1]][a[n]] << "\n";
	return 0;
}
/*
5 4
1 4 2 3 4
1010
0001
0110
0100

*/

