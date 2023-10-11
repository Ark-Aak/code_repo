#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,x=0,fl;
string s,t;
bool check_y(){
	int k=0;
	for(int i=0;i<n;i++){
		if(t[i]!='y') return 0;
		k=(k*10+s[i]-48)%11;
	}
	return (k==0);
}
bool check_o(){
	for(int i=0;i<n;i++){
		if(t[i]!='o') return 0;
	}return 1;
}
int vis[30];

signed main(){
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	n=read();
	cin >> s >> t;
//	if(n<=20){
//		dfs(1);
//		cout << "oimiya\n";
//		exit(0);
//	} else{
		if(check_y()){
			cout << "yoimiya\n";
			return 0; 
		}if(check_o()){
			cout << "oimiya\n";
			return 0;
		}
		for(int i=0;i<n;i++){
			if(t[i]=='y'){
				if((x*10+s[i]-48)%11==0) x=0,fl=1;
				else{
					x=(x*10)%11;
				}
			}
			if(t[i]=='o'){
				if((x*10)%11==0){
					x=(x*10+s[i]-48)%11;
				}else x=(x*10)%11;
			}
		}
		
		if(x%11==0 && fl)cout << "yoimiya\n";
		else cout << "oimiya\n";
//	}
	
	
	return 0;
}
/*
没证明的贪心，能过样例，但是绝对A不了、 
*/ 
