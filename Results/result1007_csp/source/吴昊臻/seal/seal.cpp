#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,top,top1,w[200005],ww[100005],ans;
struct node{
	long long id,cnt,fh;
}a[200005];
bool cmp(node i,node j)
{
	return i.cnt<j.cnt;
}
int main()
{
	freopen("seal.in","r",stdin);
	freopen("seal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>ans;
	for(long long i=1;i<=n;i++)
		cin>>a[2*i-1].cnt>>a[2*i].cnt,a[2*i-1].id=i,a[2*i].id=i,a[2*i].fh=1;
	sort(a+1,a+2*n+1,cmp); 
	for(long long i=1;i<2*n;i++)
	{
		if(a[i].fh==0&&a[i+1].fh==0)
		w[a[i].id]+=a[i+1].cnt-a[i].cnt,m-=a[i+1].cnt-a[i].cnt;
		if(a[i].fh==1&&a[i+1].fh==1)
		w[a[i+1].id]+=a[i+1].cnt-a[i].cnt,m-=a[i+1].cnt-a[i].cnt;
		if(a[i].fh==0&&a[i+1].fh==1)
		w[a[i+1].id]+=(a[i+1].cnt-a[i].cnt)/2,w[a[i].id]+=(a[i+1].cnt-a[i].cnt)/2,m-=a[i+1].cnt-a[i].cnt;
	}
	sort(w,w+n+1);
	for(long long i=n;i>n-ans;i--)
		m+=w[i];
	cout<<m;
 } 
/*
4 20 2
12 17
4 11
6 10
5 15
*/
