#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0;bool f=0;
	char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=5;
int T,y,a[N],b[N],c[N],d[N],e[N];
bool flag,Y;
signed main()
{
	freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
	T=read();
L:	while(T--)
	{
		flag=1;
		for(int i=0;i<3;i++) a[i]=read();
		for(int i=0;i<3;i++) b[i]=read();
		for(int i=0;i<3;i++) c[i]=b[i]-a[i];
		for(int i=0;i<3;i++)
			if(!a[i]) {if(b[i]) flag=0;}
			else if(b[i]%a[i]) flag=0;
			else d[i]=b[i]/a[i];
		sort(c,c+3);
		//ans=0
		for(int i=0;i<3;i++)
			if(a[i]!=b[i]) goto L1;
		puts("0");continue;
		//ans=1
L1:		for(int i=1;i<3;i++) if(c[i])
			for(int j=0;j<i;j++)
				if(c[j]&&c[i]!=c[j]) goto L2;
		puts("1");continue;
L2:		if(!flag) goto L3;
//		cerr<<"here"<<endl;
		for(int i=1;i<3;i++) if(a[i]!=b[i])
			for(int j=0;j<i;j++) if(a[j]!=b[j])
				if(d[i]!=d[j]) goto L3;
		puts("1");continue;
		//ans=2
L3:		if(c[0]==c[1]||c[1]==c[2]||!c[0]||!c[1]||!c[2]) {puts("2");continue;}//++
		if(c[0]+c[1]==c[2]) {puts("2");continue;}
		if(c[0]+c[2]==c[1]) {puts("2");continue;}
		if(c[1]+c[2]==c[0]) {puts("2");continue;}
//		cerr<<"here"<<endl;
		if(flag)//**
		{
			if(d[0]==d[1]||d[1]==d[2]||d[0]==d[2]) {puts("2");continue;}
			if(d[0]*d[1]==d[2]) {puts("2");continue;}
			if(d[1]*d[2]==d[0]) {puts("2");continue;}
			if(d[0]*d[2]==d[1]) {puts("2");continue;}
		}
		//+*
//		cerr<<"here0"<<endl;
		for(int i=0;i<3;i++)//+
			for(int j=1,T1,T2;j<8;j++)
			{
				T1=T2=0;
				for(int k=0;k<3;k++)
					if(j>>k&1) a[k]+=c[i];
				bool pp=1;
				for(int k=0;k<3;k++)
					if(a[k]!=b[k])
					{
						if(!a[k]||(b[k]%a[k])) {pp=0;break;}
						if(T2) {if(a[k]*T1!=b[k]) {pp=0;break;}}
						else T1=b[k]/a[k],T2=1;
					}
				if(pp) {puts("2");goto L;}
				for(int k=0;k<3;k++)
					if(j>>k&1) a[k]-=c[i];
			}
//		cerr<<"here1"<<endl;
		for(int i=0;i<3;i++)//*
		{
			if(!a[i]||!d[i]) continue;
			for(int j=1,T1,T2;j<8;j++)
			{
				T1=T2=0;
				bool pp=1;
				for(int k=0;k<3;k++)
					if(j>>k&1)
						if(b[k]%d[i])
						{
							pp=0;
							for(int p=0;p<k;p++)
								if(j>>p&1) b[p]*=d[i];
							break;
						}
						else b[k]/=d[i];
				if(!pp) continue;
				for(int k=0;k<3;k++)
					if(a[k]!=b[k])
					{
						if(T2) {if(a[k]+T1!=b[k]) {pp=0;break;}}
						else T1=b[k]-a[k],T2=1;
					}
				if(pp) {puts("2");goto L;}
				for(int k=0;k<3;k++)
					if(j>>k&1) b[k]*=d[i];
			}
		}
		//*+
//		for(int j=0;j<3;j++) cerr<<b[j]<<" \n"[j==2];
//		cerr<<"here2"<<endl;
		for(int i=0;i<3;i++)//*
		{
			if(!a[i]) continue;
			for(int j=1,T1,T2;j<8;j++)
			{
				T1=T2=0;
				for(int k=0;k<3;k++)
					if(j>>k&1) e[k]=a[k],a[k]*=d[i];
				bool pp=1;
				for(int k=0;k<3;k++)
					if(a[k]!=b[k])
					{
						if(T2) {if(a[k]+T1!=b[k]) {pp=0;break;}}
						else T1=b[k]-a[k],T2=1;
					}
				if(pp) {puts("2");goto L;}
				for(int k=0;k<3;k++)
					if(j>>k&1) a[k]=e[k];
			}
		}
//		cerr<<"here3"<<endl;
//		for(int i=0;i<3;i++) cerr<<b[i]<<" \n"[i==2];
		for(int i=0;i<3;i++)//+
			for(int j=1,T1,T2;j<8;j++)
			{
				T1=T2=0;
				for(int k=0;k<3;k++)
					if(j>>k&1) b[k]-=c[i];
				bool pp=1;
				for(int k=0;k<3;k++)
					if(a[k]!=b[k])
					{
						if(!a[k]||(b[k]%a[k])) {pp=0;break;}
						if(T2) {if(a[k]*T1!=b[k]) {pp=0;break;}}
						else T1=b[k]/a[k],T2=1;
					}
				if(pp) {puts("2");goto L;}
				for(int k=0;k<3;k++)
					if(j>>k&1) b[k]+=c[i];
			}
		y=Y=0;//+*or*+
//		cerr<<"here4"<<endl;
		for(int i=0;i<3;i++)
			for(int j=i+1,A,B;j<3;j++)
			{
				A=b[j]-b[i],B=a[j]-a[i];
				if(!B)
				{
					if(!A) continue;
					puts("3");goto L;
				}
				if(A%B) {puts("3");goto L;}
				if(Y) {if(B*y!=A) {puts("3");goto L;}}
				else y=A/B,Y=1; 
			}
		puts("2");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
