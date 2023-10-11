#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,ans;
struct node{
	int x,y,c;
}a[N],b[N];
bool cmp1(node a,node b){
	return max(a.x,a.y)<max(b.x,b.y);
}
bool cmp2(node a,node b){
	return min(a.x,a.y)>min(b.x,b.y);
}
signed main(){
	freopen("imp.in","r",stdin);
	freopen("imp.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) 
		a[i].x=read(),a[i].y=read(),a[i].c=read();
	if(n<=250){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int l=min(a[i].x,a[i].y),r=max(a[j].x,a[j].y);
				if(l>r) continue;
				int res=-(r-l);
				for(int k=1;k<=n;k++){
					int ls=min(a[k].x,a[k].y),rs=max(a[k].x,a[k].y);
					if(ls>=l&&rs<=r) res+=a[k].c;
				}
				ans=max(ans,res);
			}
		}
		printf("%lld",ans);
	}
	else{
		sort(a+1,a+1+n,cmp1);
		for(int r=1;r<=n;r++){// min -> max
			while(max(a[r].x,a[r].y)==max(a[r+1].x,a[r+1].y)) r++;
			for(int l=1;l<=r;l++) 
				b[l].x=a[l].x,b[l].y=a[l].y,b[l].c=a[l].c;
			sort(b+1,b+1+r,cmp2);
			int res=0;
			for(int l=1;l<=r;l++){// max->min
				while(min(b[l].x,b[l].y)==min(b[l+1].x,b[l+1].y)) res+=b[l].c,l++;
				res+=b[l].c;
				ans=max(ans,res-(max(a[r].x,a[r].y)-min(b[l].x,b[l].y)));
			}
		}
		printf("%lld",ans);
	}
	return 0;
}	
