#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pt printf
#define For(i,a,b) for(int i=a;i<=b;++i)
#define Rof(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int X1,X2,X3,Y1,Y2,Y3,A1,A2,A3,M1,M2,M3;
int _() {
	int x=0,f=0;char ch=gc();
	while(ch<'0'||ch>'9') f|=(ch=='-'),ch=gc();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	return f?-x:x;
}
void __(int x) {
	int stk[30],tp=0;
	if(x<0) x=-x,pc('-');
	do stk[++tp]=x%10,x/=10;while(x);
	while(tp) pc(stk[tp--]^48);
}
//void Init() {
//	For(i,2,Mxn-1) {
//		if(!Fg[i]) Pm[++K]=i,Mn[i]=i;
//		for(int k=1;k<=K&&i*Pm[k]<Mxn;++k) {
//			Fg[i*Pm[k]]=1,Mn[i]=Pm[k];
//			if(i%Pm[k]==0) break;
//		}
//	}
//}
bool Chk(int x) {
	return Y1/x-X1==Y2/x-X2&&Y2/x-X2==Y3/x-X3;
}
bool Check1() {
	int g=__gcd(abs(Y1),__gcd(abs(Y2),abs(Y3)));
	for(int i=1;i*i<=g;++i) if(g%i==0) 
		if(Chk(i)||Chk(-i)||Chk(g/i)||Chk(-g/i)) return 1;
	return 0;
} 
bool Check2() {
	int a=A2-A1,b=A2-A3,c=X2-X1,d=X2-X3;
	if(c&&d&&a%c==0&&b%d==0&&a/c==b/d) return 1;
	else return 0;
}
/*
2
3 5 7
6 5 10
8 6 3
9 7 8
*/
/*
3
-4 5 6
-3 -3 3
-10 3 -2
-1 2 8
-4 8 -3
1 -8 -6
*/
signed main() {
	freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
	int T=_();
//	Init();
	while(T--) {
//		pt("T=%d ",100000-T);
		X1=_(),X2=_(),X3=_(),Y1=_(),Y2=_(),Y3=_();
		A1=Y1-X1,M1=(X1==0||Y1%X1)?-1:Y1/X1;
		A2=Y2-X2,M2=(X2==0||Y2%X2)?-1:Y2/X2;
		A3=Y3-X3,M3=(X3==0||Y3%X3)?-1:Y3/X3;
		int Sum=(X1==Y1)+(X2==Y2)+(X3==Y3);
		if(Sum==0) {
			if(A1==A2&&A2==A3) pc('1');
			else if(M1!=-1&&M1==M2&&M2==M3) pc('2');
			else if(A1==A2||A2==A3||A1==A3) pc('2');
			else if(M1!=-1&&M1==M2) pc('2');
			else if(M2!=-1&&M2==M3) pc('2');
			else if(M3!=-1&&M3==M1) pc('2');
			else if(A1+A2==A3||A1+A3==A2||A2+A3==A1) pc('2');
			else if(~M1&&~M2&&~M3&&(M1*M2==M3||M1*M3==M2||M2*M3==M1)) pc('2');
			else {
				if(Check1()/* 先加再乘 */||Check2()/* 先乘再加 */) pc('2');
				else pc('3');
			}
		}
		else if(Sum==1) {
			if(X1==Y1) {
				if(A2==A3) pc('1');
				else if(M2!=-1&&M2==M3) pc('1');
				else pc('2');
			}
			else if(X2==Y2) {
				if(A1==A3) pc('1');
				else if(M1!=-1&&M1==M3) pc('1');
				else pc('2');
			}
			else if(X3==Y3) {
				if(A1==A2) pc('1');
				else if(M1!=-1&&M1==M2) pc('1');
				else pc('2');
			}
		}
		else if(Sum==2) pc('1');
		else pc('0');
		pc('\n');
//		else if(Sum==3) pt("0\n");
	}
	return 0;
}
