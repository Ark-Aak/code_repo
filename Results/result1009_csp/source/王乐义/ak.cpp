#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;char c=getchar();
	while(c<48||c>57) {if(c=='-') w=-1;c=getchar();}
	while(c>=48&&c<=57) s=(s<<1)+(s<<3)+c-48,c=getchar();
	return s*w;
}
int a[1000006];
int main() {
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(n<=10){
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		int ans=0;
		for(int i=1;i<=n/k;i++){
			int h=0,l,r;
			if(i%2){//Ñ¡Ð¡µÄ
				int minn=99999999;
				for(int j=1;j<=n-(i-1)*k;j++){
					if(j<k){
						h+=a[j];
						continue;
					}
					h-=a[j-k];
					h+=a[j];
					if(h<=minn){
						minn=h;
						l=j-k+1;
						r=j;
					}
				}
				ans+=minn;
			}
			else{
				int maxx=0;
				for(int j=1;j<=n-(i-1)*k;j++){
					if(j<k){
						h+=a[j];
						continue;
					}
					h-=a[j-k];
					h+=a[j];
					if(h>=maxx){
						maxx=h;
						l=j-k+1;
						r=j;
					}
				}
				ans+=maxx;
			}
			for(int j=l;j<=n-i*k;j++)a[j]=a[r+j-l+1];
//			cout<<ans<<"\n";
//			for(int j=1;j<=n-i*k;j++)cout<<a[j]<<" ";
//			cout<<"\n";
		}
		cout<<ans;
	}
	else if(k==1){
		int h=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			h+=a[i];
		}
		sort(a+1,a+n+1);
		cout<<(n%2==0?h-a[(n+2)/2]:h-a[(n+1)/2]);
	}
	else{
		int h=0;
		int o=1;
		for(int i=1;i<=n;i++){
			a[i]=read();
			h+=a[i];
			if(a[i]>2)o=0;
		}
		if(o){
			int x_1=0,x_2=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)x_1++;
				else x_2++;
			}
			if(x_2==n)cout<<h-2;
			else if(x_1==n)cout<<h-1;
			else
				if(x_1>x_2)cout<<h-1;
				else cout<<h-2;
		}
		else{
			int h=0;
			for(int i=1;i<=n;i++){
				a[i]=read();
				h+=a[i];
			}
			sort(a+1,a+n+1);
			cout<<(n%2==0?h-a[(n+2)/2]:h-a[(n+1)/2]);
		}
	}
	return 0;
}
