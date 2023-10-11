#include<bits/stdc++.h>
using namespace std;
int n,cnt,root,ans,ansq;
string anss,l,r;
queue<int> q;
struct tree{
	int fail=-1,ed[2005],nx[10],ans[2005],g[2005];
	char c;
}t[20005];
bool is[20005];
void getfail(){
	for(int i=0;i<10;i++){
		int y=t[root].nx[i];
		if(!y) continue;
		t[y].fail=root;
		q.push(y);
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<10;i++){
			int &y=t[x].nx[i];
			if(y){
				t[y].fail=t[t[x].fail].nx[i];
				if(!is[y]){
					q.push(y);
					is[y]=1;
				}
			}
			else y=t[t[x].fail].nx[i];
		}
	}
	for(int x=0;x<=cnt;x++){
		for(int k=0;k<=n;k++){
			for(int p=x;p!=-1;p=t[p].fail){
                t[x].g[k]+=t[p].ed[k];
			}
		}
	}
}
void AC(){
	for(int j=0;j<n;j++)
		for(int i=0;i<=cnt;i++) t[i].ans[j]=-1e9;
	t[root].ans[0]=0;
	for(int q=0;q<n;q++){
		for(int i=0;i<=cnt;i++){
			for(int j=0;j<10;j++){
				int y=t[i].nx[j];
				if(t[y].ans[q+1]<t[i].ans[q]+t[y].g[n-1-q]){
                    t[y].ans[q+1]=t[i].ans[q]+t[y].g[n-1-q];
					// if(q==0) cout<<j<<" "<<t[y].ans[q+1]<<"\n";
					ans=max(ans,t[y].ans[q+1]);
                }
			}
		}
	}
}
void add(int x,int l,int r,int len){
	for(int i=l;i<=r;i++){
		int &y=t[x].nx[i];
		if(!y){
			y=++cnt;
			t[y].c=i+'0';
		}
		t[y].ed[len]++;
	}
}
void move(int &x,int b){
	int &y=t[x].nx[b];
	if(!y){
		y=++cnt;
		t[y].c=b+'0';
	}
	x=y;
}
void build_tree(){
	int nl=l.size(),nr=r.size();
	if(nl==nr){
		bool bj=0;
		int x=root,x1=-1;
		for(int i=0;i<nl;i++){
			int last=nl-i-1;
			if(l[i]==r[i]&&!bj) move(x,l[i]-'0');
			else{
				if(!bj){
					x1=x;
					add(x,l[i]-'0'+1,r[i]-'0'-1,last);
				}
				else{
					add(x,l[i]-'0'+1,9,last);
					add(x1,0,r[i]-'0'-1,last);
				}
				move(x,l[i]-'0');
				move(x1,r[i]-'0');
				bj=1;
			}
		}
		t[x].ed[0]++;
		if(x1!=-1) t[x1].ed[0]++;
	}
	else{
		bool bj=0;
		int x=root,x1=root;
		for(int i=0;i<nl;i++){
			int last=nl-i-1;
			add(x,l[i]-'0'+1,9,last);
			move(x,l[i]-'0');
			bj=1;
		}
		t[x].ed[0]++;
		for(int i=0;i<nr;i++){
			int last=nr-i-1;
			add(x1,0+(x1==root),r[i]-'0'-1,last);
			move(x1,r[i]-'0');
			bj=1;
		}
		t[x1].ed[0]++;
		for(int i=0;i<=9;i++){
			for(int j=nl+1-1;j<=nr-1-1;j++){
				if(!t[root].nx[i]){
					t[root].nx[i]=++cnt;
					t[t[root].nx[i]].c=i;
				}
				t[t[root].nx[i]].ed[j]++;
			}
		}
	}
	for(int i=0;i<=cnt;i++){
		for(int j=1;j<=n;j++){
			t[i].ed[j]+=t[i].ed[j-1];
		}
	}
}
bool res[20005][2005];
void find(){
	for(int i=0;i<=cnt;i++){
		if(t[i].ans[n]==ans) res[i][n]=1; 
	}
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<=cnt;j++){
			for(int k=0;k<=9;k++){
				int nx=t[j].nx[k];
				if(res[nx][i+1]&&t[j].ans[i]+t[nx].g[n-i-1]==t[nx].ans[i+1]){
					res[j][i]=1;
					break;
				}
			}
		}
	}
	int x=root;
	// cout<<"\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<=9;j++){
			int nx=t[x].nx[j];
			if(res[nx][i+1]&&t[x].ans[i]+t[nx].g[n-i-1]==t[nx].ans[i+1]){
				// cout<<"!!\n";
				cout<<char(j+'0');
				x=nx;
				break;
			}
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>l>>r>>n;
	build_tree();
    getfail();
    AC();
	cout<<ans<<"\n";
	find();
	return 0;
}
