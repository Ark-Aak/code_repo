#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long s=0,w=1;char c=getchar();
	while(c<48||c>57) {if(c=='-') w=-1;c=getchar();}
	while(c>=48&&c<=57) s=(s<<1)+(s<<3)+c-48,c=getchar();
	return s*w;
}
long long color[50003];
vector<int>e[50004],b[55];
long long d[50004];
priority_queue<pair<int,int> >q;
bool book[50004];
long long n,k;
void zdl(){
	q.push({0,1});
	for(long long i=1;i<=n;i++)d[i]=99999999999999;
	d[1]=0;
	while(!q.empty()){
		long long x=q.top().second;
		q.pop();
		book[x]=1;
		long long l=e[x].size();
		for(long long i=0;i<l;i++){
			if(d[x]+abs(e[x][i]-x)<d[e[x][i]]){
				d[e[x][i]]=d[x]+abs(e[x][i]-x);
				if(!book[e[x][i]]){
					q.push({-d[e[x][i]],e[x][i]});
				}
			}
		}
	}
	if(d[n]==99999999999999)cout<<-1;
	else cout<<d[n];
}
int main() {
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		color[i]=read();
		b[color[i]].push_back(i);
	}
	for(long long i=1;i<=k;i++){
		for(long long j=1;j<=k;j++){
			char x;
			cin>>x;
			if(x=='1'){
				long long l_1=b[i].size(),l_2=b[j].size();
				for(long long h=0;h<l_1;h++){
					for(long long w=0;w<l_2;w++){
						e[b[i][h]].push_back(b[j][w]);
					}
				}
			}
		}
	}
	zdl();
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
