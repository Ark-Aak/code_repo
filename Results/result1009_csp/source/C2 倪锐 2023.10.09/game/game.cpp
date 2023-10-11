#include<bits/stdc++.h>
#define RU 1
#define LU 2
#define RD 3
#define LD 4
#define mod 1000000007
#define int long long
#define re register
// #define int long long
#define rep(i,a,b) for(int i(a);i<=(b);++i)
#define req(i,a,b) for(int i(a);i>=(b);--i)
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf,ubuf[1<<23],*u=ubuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
template<typename TP> inline TP read(TP &num)
{
	re TP x=0;re int f=0;re char ch=getchar();
	while(ch<48||ch>57) f|=ch=='-',ch=getchar();
	while(48<=ch&&ch<=57) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return num=f?-x:x;
}
template<typename TP> inline void write(TP x)
{
	(x<0)?(putchar('-'),x=-x):0;
    (x>9)?(write(x/10),0):0;
	putchar((x%10)^48);
}
template<typename TP> inline void writeln(TP x)
{
	write<TP>(x);
	puts("");
}
int T,ans[1001][1001],x,y;
string orz(int pos)
{
	return pos==RU?"RU":pos==LU?"LU":pos==RD?"RD":pos==LD?"LD":"fuck you";
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(T);
	rep(n,1,1000) rep(m,1,1000) 
	{
		// read(n);read(m);
		int posx=0,posy=0,pos=RU,first=1,round=0,escaped=0;
		while(1)
		{
			// cout<<posx<<" "<<posy<<" "<<orz(pos)<<endl;
			++round;
			int posx_to_right=n-posx,posx_to_left=posx,posy_to_ceil=m-posy,posy_to_floor=posy,nxtpos;
			// if((!posx_to_right)+(!posx_to_left)+(!posy_to_ceil)+(!posy_to_floor)>=2) if(!first) break;
			switch(pos)
			{
				case RU:
					if(posx_to_right<posy_to_ceil) // to right wall
						posx=n,posy+=posx_to_right,pos=LU;
					else if(posx_to_right>posy_to_ceil) // to ceil
						posx+=posy_to_ceil,posy=m,pos=RD;
					else escaped=1;
					break;
				case LD:
					if(posx_to_left<posy_to_floor) // to left wall
						posx=0,posy-=posx_to_left,pos=RD;
					else if(posx_to_left>posy_to_floor) // to floor
						posx-=posy_to_floor,posy=0,pos=LU;
					else escaped=1;
					break;
				case RD:
					if(posx_to_right>posy_to_floor) // to floor
						posx+=posy_to_floor,posy=0,pos=RU;
					else if(posx_to_right<posy_to_floor) // to right wall
						posy-=posx_to_right,posx=n,pos=LD;
					else escaped=1;
					break;
				case LU:
					if(posx_to_left>posy_to_ceil) // to ceil
						posx-=posy_to_ceil,posy=m,pos=LD;
					else if(posx_to_left<posy_to_ceil) // to left wall
						posy+=posx_to_left,posx=0,pos=RU;
					else escaped=1;
					break;
				default:
					assert(0);
					break;
			}
			if(escaped) break;
			first=0;
		}
		ans[n][m]=(round-1);
	}
	rep(i,1,1000) rep(j,1,1000) (ans[i][j]+=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1])%=mod;
	while(T--) read(x),read(y),writeln(ans[x][y]);
	return 0; 
}
/*
 * 第一次大模拟没打挂
 * 但是是暴力
 * O(30pts)
 */
