#include<iostream>
#include<cstdio>
#include"testlib.h"
#define N 250000
#define M 14
using namespace std;
int c,T,delta[M+1]={0,3,3,5,5,6,6,9,9,9,9,9,9,9,9},a[N+1],b[N+1],ta[N+1],tb[N+1];
string w,s[N+1],t[N+1];
int main(int argc,char *argv[])
{
	bool op=1,op2=1;
	registerTestlibCmd(argc,argv);
	c=inf.readInt(),T=inf.readInt();
	for (int i=1;i<=T;++i)
	{
		a[i]=ouf.readInt(),b[i]=ouf.readInt();
		if (b[i]<0||b[i]>=998244353) quitf(_wa,"Wrong Answer");
	}
	for (int i=1;i<=T;++i) ta[i]=ans.readInt(),tb[i]=ans.readInt();
	for (int i=1;i<=T;++i) op&=(a[i]==ta[i]),op2&=(b[i]==tb[i]);
	if (!op) quitf(_wa,"Wrong Answer");
	else if (!op2) quitp((int)(floor(delta[c]*0.25)),"Partically Correct");
	else quitf(_ok,"Accepted!");
	return 0;
}
