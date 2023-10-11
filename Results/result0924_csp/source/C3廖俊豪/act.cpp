#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct node{
	int x,y,ops,id,ans;
}p[2000005];
bool cmp(node A,node B){
	if(A.x!=B.x)return A.x<B.x;
	if(A.y!=B.y)return A.y<B.y;
	return A.ops<B.ops;
}
bool CMP(node A,node B){
	return A.id<B.id;
}
map<int,int>q;
priority_queue<int,vector<int>,greater<int> >q2;
map<pair<int,int>,int>Q;
signed main(){
	freopen("act.in","r",stdin);
	freopen("act.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i].y;
	for(int i=1;i<=n;i++)
		cin>>p[i].x;
	for(int i=1;i<=n;i++)
		Q[make_pair(p[i].x,p[i].y)]=1;
	for(int i=1;i<=m;i++){
		cin>>p[i+n].y>>p[i+n].x;
		p[i+n].ops=1;
		p[i+n].id=i;
	}
	sort(p+1,p+n+m+1,cmp);
	int lastx=-1,lasty=-1,ops=1;
	for(int i=0;i<=n+m;i++){
		if(p[i].x!=lastx){
			if(ops==0)lasty++;
			while(q[lasty+1])lasty++;
//			cout<<lastx<<" "<<lasty<<endl;
			int res=p[i].x-lastx-1;
			while(res&&!q2.empty()){
				if(lasty>=q2.top())q2.pop();
				else{ 
					if(res>=q2.top()-lasty-1){
						res-=q2.top()-lasty-1;
						lasty=q2.top();
						q2.pop();
					}else{
						lasty+=res;
						res=0;
					}
				}
//				cout<<lasty<<endl;
			}
			lasty+=res;
//			cout<<p[i].x<<"-"<<lasty<<endl;
			ops=0;
			lastx=p[i].x;
		}
		if(p[i].y>lasty){
			if(ops==0){
				lasty++;
				ops=1;
				Q[make_pair(p[i].x,lasty)]=1;
				while(q[lasty+1])lasty++;
			}
		}
		if(p[i].ops==1){
			if(ops==1&&lasty==p[i].y){
				p[i].ans=0;
			}else if(Q[make_pair(p[i].x,p[i].y)]){
				p[i].ans=0;
			}else if(lasty>=p[i].y){
				p[i].ans=1;
			}else if(ops==1){
				p[i].ans=1;
			}else if(q[p[i].y]){
				p[i].ans=1;
			}else{
				p[i].ans=0;
			}
		}else{
			ops=1;
			q2.push(p[i].y);
			Q[make_pair(p[i].x,p[i].y)]=1;
			q[p[i].y]=1;
			while(q[lasty+1])lasty++;
		}

	}
//	cout<<lastx<<" "<<lasty<<endl;
	sort(p+1,p+n+m+1,CMP);
	for(int i=1;i<=n+m;i++){
//		cout<<p[i].id<<endl;
		if(p[i].id!=0){
			if(p[i].ans==1){
//				cout<<p[i].x<<" "<<p[i].y<<endl;
				cout<<"Alice"<<endl;
			}else{
//				cout<<p[i].x<<" "<<p[i].y<<endl;
				cout<<"Bob"<<endl;
			}
		}
	}
	return 0;
}
/*
1 3
4 0
3 3
5 4
5 3
*/
