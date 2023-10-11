#include<bits/stdc++.h> 
using  namespace std;
map<long long,int>m,mm;
long long n,p,pr[10000000],q;
int main(){
	freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout);
	scanf("%lld%lld",&n,&p);
	int tot=0;
	for(int i=2;i<=p;i++){
		if(!m[i]){
			pr[++tot]=i;
			for(int j=i;j<=p;j+=i){
				m[j]=1;
			}
		}
	}
	//	cout<<tot<<endl;
	for(int i=1;i<=n;i++){
		scanf("%lld",&q);
		long long aa=1;
		while(aa<=q){
			aa*=p+1;
		}
		for(long long ans=q;ans<=aa;ans++)
		{
			int k=0;
			for(int j=1;j<=tot;j++){
				if((ans/pr[j])*pr[j]==ans){
					k++;
				}
			}
			if(k==0){
				printf("%lld\n",ans);
				break;
			}
		}
	}
	return 0;
}
