#include<bits/stdc++.h>
using namespace std;
int x,y,n,m,k;
//vector<int>h[1000005],l[1000005];
long long int h[1000005],l[1000005];
long long int sh[1000005],sl[1000005],ans,sb[1005][1005];
vector<int>fh;
vector<int>fl;
char a;
int sol(int hh,int ll)
{
	return ((hh-1)*m+ll)%1000000007;
}
int main()
{
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	cin>>n>>m>>k;
	if(n<=1000&&m<=1000)
	{
//		cout<<"A"<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				sb[i][j]=sol(i,j);
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=m;j++)
//			{
//				cout<<sb[i][j]<<"    ";
//			}
//			cout<<endl;
//		}
		for(int i=1;i<=k;i++)
		{
			cin>>a>>x>>y;
			if(a=='R')
			{
				for(int j=1;j<=m;j++)
				{
					sb[x][j]*=y;
					sb[x][j]%=1000000007;
				}
			}
			else
			{
				for(int j=1;j<=n;j++)
				{
					sb[j][x]*=y;
					sb[j][x]%=1000000007;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
//				cout<<sb[i][j]<<"   ";
				ans+=sb[i][j];
				ans%=1000000007;
			}
//			cout<<endl;
		}
		cout<<ans<<endl;
	}
	else
	{
		for(int i=1;i<=1000000;i++)
		{
			h[i]=-1;
			l[i]=-1;
		}
		for(int i=1;i<=k;i++)
		{
			cin>>a>>x>>y;
			if(a=='R')
			{
//				h[x].push_back(y);
				if(h[x]==-1)
				{
					h[x]=y;
					fh.push_back(x);
//					cout<<"+++++++++++++   "<<x<<endl;
				}
				else
				{
					h[x]*=y;
					h[x]%=1000000007;
				}			
			}
			else
			{
//				l[x].push_back(y);
				if(l[x]==-1)
				{
					l[x]=y;
					fl.push_back(x);
				}
				else
				{
					l[x]*=y;
					l[x]%=1000000007;
				}
				
			}
		}
		for(int i=1;i<=n;i++)
		{
			sh[i]=(((i-1)*m+1+i*m)*m/2)%1000000007;
		}
		for(int i=1;i<=n;i++)
		{
			sl[1]+=(i-1)*m+1;
		}
		sl[1]%=1000000007;
		for(int i=2;i<=m;i++)
		{
			sl[i]=sl[1]+n*(i-1);
			sl[i]%=1000000007;
		}
		for(int i=1;i<=n;i++)
		{
			ans+=sh[i];
			ans%=1000000007;
		}
//		cout<<"--  "<<ans<<endl;
//		for(int i=1;i<=n;i++)
//		{
//			cout<<sh[i]<<" ";
//		}
//		cout<<endl;
//		for(int i=1;i<=m;i++)
//		{
//			cout<<sl[i]<<" ";
//		}
//		cout<<endl;
		for(int i:fh)
		{
//			cout<<"--+    "<<i<<endl;	

			ans+=sh[i]*(h[i]-1);
			ans%=1000000007;	

		
//			cout<<"====  "<<ans<<"  "<<i<<"  "<<h[i]<<endl;
		
		}
//		cout<<"  1    -----  "<<ans<<endl;
		for(int i:fl)
		{

			ans+=sl[i]*(l[i]-1);
//			pl[i]++;
			ans%=1000000007;
		
		}
//		for(int i=0;i<=1000000;i++)
//		{
//			pl[i]=0;
//			ph[i]=0;
//		}
//		cout<<"__DWDWD"<<endl;
//		cout<<h[2][0]<<endl;
		for(int i:fh)
		{
			for(int j:fl)
			{
//				cout<<i<<"   "<<j<<"  "<<ph[i]<<" "<<pl[j]<<" "<<h[i][ph[i]]<<" "<<l[j][pl[j]]<<endl;
//				if(vla[j]==0&&vha[i]==0)
				{
					ans+=(((h[i]-1)*(l[j]-1)%1000000007)*sol(i,j))%1000000007;
					ans%=1000000007;
//					pl[j]++;
//					ph[i]++;
				}			
			}
//			for(int i=1;i<=1000;i++)
//			{
//				pl[i]=0;
//			}
		}
		cout<<ans<<endl;
}
	
}
