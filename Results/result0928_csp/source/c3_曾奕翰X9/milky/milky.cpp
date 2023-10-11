#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005,Mod=4294967296;
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
struct XXX {
	int a,b;
};
bool cmp(XXX x,XXX y){
	if(x.a==y.a) return x.b<y.b;
	return x.a<y.a;
}
bool cmb(XXX x,XXX y){
	if(x.b==y.b) return x.a<y.a;
	return x.b<y.b;
}
char s[N];
int n;
int qzhm[N],qzhmi[N],qzhmil[N],qzhmilk[N],qzhmilky[N];
int y[N];
int mm[N],ii[N],ll[N],kk[N];
int visi[1005][1005],visl[1005][1005];
int vism[1005][1005];
int totm,toti,totl,totk;
signed main(){
	ios::sync_with_stdio(0);
	freopen("milky.in","r",stdin);
	freopen("milky.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(n>1000)qzhm[i]=qzhm[i-1];
		if(s[i]=='m') qzhm[i]++,mm[++totm]=i;
		if(n>1000)qzhm[i]%=Mod;
	}
	for(int i=1;i<=n;i++){
		if(n>1000)qzhmi[i]=qzhmi[i-1];
		if(s[i]=='i') qzhmi[i]+=qzhm[i],ii[++toti]=i;
		if(n>1000)qzhmi[i]%=Mod;
	}
	for(int i=1;i<=n;i++){
		if(n>1000)qzhmil[i]=qzhmil[i-1];
		if(s[i]=='l') qzhmil[i]+=qzhmi[i],ll[++totl]=i;
		if(n>1000)qzhmil[i]%=Mod;
	}
	for(int i=1;i<=n;i++){
		if(n>1000)qzhmilk[i]=qzhmilk[i-1];
		if(s[i]=='k') qzhmilk[i]+=qzhmil[i],kk[++totk]=i;
		if(n>1000)qzhmilk[i]%=Mod;
	}
	for(int i=1;i<=n;i++){
		if(n>1000)qzhmilky[i]=qzhmilky[i-1];
		y[i]=y[i-1];
		if(s[i]=='y') qzhmilky[i]+=qzhmilk[i],y[i]++;
		if(n>1000)qzhmilky[i]%=Mod;
	}
	mm[++totm]=1145141919; 
	ii[++toti]=1145141919; 
	ll[++totl]=1145141919; 
	kk[++totk]=1145141919; 
	int q=read();
	while(q--){
		int l=read(),r=read();
		if(n<=1000){
		int ans=0;
			int p1=lower_bound(mm+1,mm+totm+1,l)-mm;
			for(int i=p1;mm[i]<=r;++i){
				if(vism[r][i]){
					ans+=vism[r][i];
					ans%=Mod;
					continue;
				}
				int p2=lower_bound(ii+1,ii+toti+1,mm[i])-ii;
				int res33=0;
				for(int i1=p2;ii[i1]<=r;++i1){
					if(visi[r][i1]){
						ans+=visi[r][i1];
						ans%=Mod;
						continue;
					}
					int p3=lower_bound(ll+1,ll+totl+1,ii[i1])-ll;
					int res22=0;
					for(int i2=p3;ll[i2]<=r;++i2){
						if(visl[r][i2]){
							ans+=visl[r][i2];
							ans%=Mod;
							continue;
						}
						int p4=lower_bound(kk+1,kk+totk+1,ll[i2])-kk;
						int res=0;
						for(int i3=p4;kk[i3]<=r;++i3){
							res+=y[r]-y[kk[i3]];
						}
						res%=Mod;
						visl[r][i2]=res;
						ans+=res;
						res22+=res;
						ans%=Mod;
					}
					res22%=Mod;
					visi[r][i1]=res22;
					res33+=res22;
				}
				res33%=Mod;
				vism[r][i]=res33;
			}
			printf("%lld\n",ans);
			continue;
		}
		if(r-l+1<5){
			cout<<0<<endl;
			continue;
		}
		int klreln=qzhmilky[r]-qzhmilky[l-1];
		
		cout<<(klreln+3*Mod)%Mod<<endl;
	}
	return 0;
}
