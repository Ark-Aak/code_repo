//30-
#include<bits/stdc++.h>
using namespace std;
int n,m,x,p[55],l[55][55],o[20][131073],v[55];
string s;
int dfs(int t,int lst){
	//cout<<t<<' '<<lst<<":\n";
	if(t>n) return 1;
	if(o[t][lst]) return o[t][lst];
	for(int i=0;i<(1<<l[t][0]);i++){
		int u=p[t];
		for(int j=0;j<l[t][0];j++)
			u+=(1<<l[t][j+1])*(!!(i&(1<<j)));
		int f=1;
		for(int j=1;j<m;j++){
			int a=(u&(1<<j)),b=(u&(1<<(j-1)));
			int c=(lst&(1<<j)),d=(lst&(1<<(j-1)));
			//cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
			if(a && d && !b && !c){f=0;break;}
			if(!a && !d && b && c){f=0;break;}
		}if(!f) continue;
		int lt=dfs(t+1,u);
		if(lt==1){
			v[t]=u;
			return o[t][lst]=1;
		}
	}
	return o[t][lst]=-1;
}
signed main(){
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;x=0;
		for(int j=1;j<=m;j++){
			x=(x<<1)+(s[j-1]=='1');
			if(s[j-1]=='?'){
				l[i][0]++;
				l[i][l[i][0]]=m-j;
			}
		}p[i]=x;
	}
	int ox=dfs(1,0);
	if(ox==1){
		cout<<"Yes\n";
		for(int i=1;i<=n;i++){
		for(int j=m-1;j>=0;j--){
			cout<<!!(v[i]&(1<<j));
		}cout<<'\n';/*cout<<"("<<p[i]<<")\n";*/}
	}else{cout<<"No\n";}
	return 0;
} 
