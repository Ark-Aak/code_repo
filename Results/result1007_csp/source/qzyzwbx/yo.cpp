#include<bits/stdc++.h>
using namespace std;
bool f;
int n,cnt,ans,rem[1000007][11],ccnt;
string opr,num,oimiya;
string two(int x){
	string s="";
	if(!x){
		s="0";
	}
	else
		while(x){
			int a=x%2;
			x/=2;
			char c='0'+a;
			s=c+s;
		}
	return s;
}
void dfs(int step,int sum,int tot){
//	if(rem[step][sum]){
//		return;
//	}
//	rem[step][sum]=1;
	if(step==n||f){
		if(sum%11==0){
			f=1;
		}
		return;
	}
	int x=num[step]-'0';
//	cout<<opr[step]<<endl;
	if(opr[step]=='o'){
	//	cout<<(oimiya[tot]-'0')*x<<":"<<step<<endl;
		dfs(step+1,(sum*10+(oimiya[tot]-'0')*x)%11,tot+1);
	}
	else{
		dfs(step+1,(sum*10+x)%11,tot);
		dfs(step+1,sum*10%11,tot);
	}
}
int main(){
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	cin>>num;
	cin>>opr;
	
	for(int i=0;i<n;i++){
		if(opr[i]=='o'){
			cnt++;
		}
		if(num[i]=='0'){
			ccnt++;
		}
	}
	if(cnt==0||ccnt==n){
		cout<<"yoimiya"<<endl;
		return 0;
	}
	if(cnt==n||(opr[n-1]=='o'&&num[n-1]!='0')){
		cout<<"oimiya"<<endl;
		return 0;
	}
	for(int i=0;i<=cnt;i++){
		oimiya=two(i);
	//	cout<<oimiya<<endl;
		f=0;
		dfs(0,0,0);
		ans+=f;
		
	}
	if(ans>cnt){
		cout<<"yoimiya"<<endl;
	}
	else{
		cout<<"oimiya"<<endl;
	}
	
	return 0;
}
