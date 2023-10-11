#include<bits/stdc++.h>
using namespace std;
int n,m,k,top,top1,w[1005][1005],x,sum[1005][1005];
int cheak(int i,int j)
{
	int ans=0,q=-1,qq=-1,p,pp=i,ppp=j,qqq=0,ww;
	if(j<i) swap(i,j);
	p=__gcd(i,j);
	if(i==1) return w[pp][ppp]=j-1,0;
	if(i==j) return w[pp][ppp]=0,0;
	if(w[i/p][j/p]!=0) return w[pp][ppp]=w[i/p][j/p],0;
	int nowi=0,nowj=0;
	while(1)
	{
		if(nowi==i&&nowj==j) break;
		if(nowi==0&&nowj==0&&qqq) break;
		if(nowi==0&&nowj==j) break;
		if(nowi==i&&nowj==0) break;
		if(nowi==i||nowi==0) q=-q,ans++;
		if(nowj==j||nowj==0) qq=-qq,ans++;
		if(q>0&&qq>0)
		ww=min(i-nowi,j-nowj),nowi+=q*ww,nowj+=qq*ww; 
		if(q<0&&qq>0)
		ww=min(nowi,j-nowj),nowi+=q*ww,nowj+=qq*ww; 
		if(q<0&&qq<0)
		ww=min(nowi,nowj),nowi+=q*ww,nowj+=qq*ww; 
		if(q>0&&qq<0)
		ww=min(i-nowi,nowj),nowi+=q*ww,nowj+=qq*ww; 
		qqq++;
	}
	return w[pp][ppp]=ans-2,0;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=100;i++)
		for(int j=1;j<=100;j++)
			cheak(i,j);
	for(int i=1;i<=100;i++)
		for(int j=1;j<=100;j++)
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+w[i][j];
	while(n--)
	{
		cin>>m>>k;
		cout<<sum[m][k]<<'\n';
	}
}
/*
11 5
1 5 2 7 1 9 4 6 2 11 3
*/
