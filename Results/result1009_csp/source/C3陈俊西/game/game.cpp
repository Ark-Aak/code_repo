#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5,mod=1e9+7;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int T,c,r,ans[N][N];
int count(int C,int R){
	//f={1,2,3,4} 1:右上 2:右下 3:左上 4:左下
	int x=0,y=0,f=1,res=0;
	while(true){
		if(f==1){//youshang
			if(x+(R-y)<=C){
				x+=(R-y);
				y=R;
				f=2;
			}
			else{
				y=y+(C-x);
				x=C;
				f=3;
			}
			if(x==C&&y==R) break;
			res++;
		}
		else if(f==2){//youxia
			if(x+y<=C){
				x+=y;
				y=0;
				f=1;
			}
			else{
				y=y-(C-x);
				x=C;
				f=4;
			}
			if(x==C&&y==0) break;
			res++;
		}
		else if(f==3){//zuoshang
			if(x-(R-y)>=0){
				x-=(R-y);
				y=R;
				f=4;
			}
			else{
				y=y+x;
				x=0;
				f=1;
			}
			if(x==0&&y==R) break;
			res++;	
		}
		else{//zuoxia
			if(x-y>=0){
				x-=y;
				y=0;
				f=3;
			}
			else{
				y=y-x;
				x=0;
				f=2;
			}
			res++;
		}
	}
	return res;
}
signed main(){
//	fc C:\Users\HP\Desktop\T\ex_tower1.out C:\Users\HP\Desktop\T\ex_tower1.ans
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	for(int i=1;i<=1000;i++)
		for(int j=1;j<=1000;j++)
			ans[i][j]=(ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]+mod+count(i,j))%mod;
	T=read();
	while(T--){
		c=read(),r=read();
		printf("%lld\n",ans[c][r]);
	}
	return 0; 
}

