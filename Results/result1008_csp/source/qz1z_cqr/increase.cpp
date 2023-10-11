//100
#include<bits/stdc++.h>
#define MN 200005
#define MM 500005
#define GP pair<int,int>
#define MP make_pair
using namespace std;//0A  1B
int n,m,a,b,c,d,w,res,mx[MN][2],md[MN],ck[MN];
struct eg{int x,y;}e[MM];
/*int mp[105][105];vector<GP> v[MN];*///use to test!!!!
void upd2(int nd,int pyr,int rsl){
	//cout<<"update:"<<nd<<' '<<pyr<<' '<<rsl<<'\n';
	if(pyr==0) mx[nd][pyr]=min(mx[nd][pyr],rsl);
	if(pyr==1) mx[nd][pyr]=max(mx[nd][pyr],rsl);
}
/*void update(int nd,int bq,int to){
	if(md[nd]==bq){return;}
	mp[nd][bq*2]=1+mx[nd][1];
	mp[nd][bq*2+1]=1+mx[nd][0];
	cout<<nd<<' '<<bq<<"(0) "<<1+mx[nd][1]<<'\n';
	cout<<nd<<' '<<bq<<"(1) "<<1+mx[nd][0]<<'\n';
}*/
signed main(){
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	scanf("%d%d",&n,&m);
	//for(int i=1;i<=n;i++){v[i].push_back(MP(0,0));}
	for(int i=1;i<=n;i++){mx[i][0]=n+1;}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&w);
		e[w].x=a;e[w].y=b;
		md[a]=max(md[a],w);
		md[b]=max(md[b],w);
		ck[a]=ck[b]=1;
		/*v[a].push_back(MP(w,b));
		if(a!=b)
			v[b].push_back(MP(w,a));*/
	}
	//for(int i=1;i<=n;i++){cout<<md[i]<<' ';}cout<<'\n';
	for(int i=m;i>=1;i--){
		//cout<<i<<':'<<e[i].x<<' '<<e[i].y<<'\n';
		/*update(e[i].x,i,e[i].y);
		if(e[i].x!=e[i].y){
			update(e[i].y,i,e[i].x);}*/
		if(md[e[i].x]>i) a=mx[e[i].x][1]+1,b=mx[e[i].x][0]+1;
			else a=b=0;
		if(md[e[i].y]>i) c=mx[e[i].y][1]+1,d=mx[e[i].y][0]+1;
			else c=d=0;
		//cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
		upd2(e[i].y,1,b);//A play
		upd2(e[i].y,0,a);//B play
		if(e[i].x==e[i].y){continue;}
		upd2(e[i].x,1,d);//A play
		upd2(e[i].x,0,c);//B play
	}
	/*
	for(int i=1;i<=n;i++)//use to test!!!
		sort(v[i].begin(),v[i].end());
	for(int i=1;i<=n;i++){
		printf("%d | ",i);
		for(auto j:v[i]){
			cout<<setw(2)<<j.first;
			cout<<'('<<mp[i][j.first*2]<<','<<mp[i][j.first*2+1]<<')';
		}cout<<'\n';
	}*/
	for(int i=1;i<=n;i++)
		printf("%d ",(1+mx[i][1])*ck[i]);
	printf("\n");
	//for(int i=1;i<=n;i++)
	//	cout<<1+mx[i][1]<<' ';
	return 0;
} 
