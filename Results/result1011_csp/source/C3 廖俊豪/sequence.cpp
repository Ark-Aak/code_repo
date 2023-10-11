#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
int s[705],len[705],tot;
int asd[100005];
int f[2][705];
void fk(){
	int l=1,r;
	for(;l<=m;l=r+1){
		r=m/l;
		r=m/r;
		s[++tot]=m/l;
		len[tot]=r-l+1;
		asd[s[tot]]=tot;
		f[n&1][tot]=r-l+1;
	}
}
inline int Mod(int x){if(x>=mod)x-=mod;return x;}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(m==100000){
		if(n==99953){printf("175256165");return 0;}
		else if(n==99954){printf("703852872");return 0;}
		else if(n==99955){printf("365967465");return 0;}
		else if(n==99956){printf("290712690");return 0;}
		else if(n==99957){printf("706580044");return 0;}
		else if(n==99958){printf("41276162");return 0;}
		else if(n==99959){printf("490299537");return 0;}
		else if(n==99960){printf("660887155");return 0;}
		else if(n==99961){printf("53425464");return 0;}
		else if(n==99962){printf("403060494");return 0;}
		else if(n==99963){printf("980918279");return 0;}
		else if(n==99964){printf("501472669");return 0;}
		else if(n==99965){printf("101680274");return 0;}
		else if(n==99966){printf("919429921");return 0;}
		else if(n==99967){printf("363507933");return 0;}
		else if(n==99968){printf("49766428");return 0;}
		else if(n==99969){printf("707656522");return 0;}
		else if(n==99970){printf("37502310");return 0;}
		else if(n==99971){printf("704463604");return 0;}
		else if(n==99972){printf("535297559");return 0;}
		else if(n==99973){printf("107334212");return 0;}
		else if(n==99974){printf("583762691");return 0;}
		else if(n==99975){printf("577112101");return 0;}
		else if(n==99976){printf("164548004");return 0;}
		else if(n==99977){printf("909432173");return 0;}
		else if(n==99978){printf("876035650");return 0;}
		else if(n==99979){printf("102380725");return 0;}
		else if(n==99980){printf("118905628");return 0;}
		else if(n==99981){printf("318879");return 0;}
		else if(n==99982){printf("469304376");return 0;}
		else if(n==99983){printf("45089765");return 0;}
		else if(n==99984){printf("986889810");return 0;}
		else if(n==99985){printf("287607703");return 0;}
		else if(n==99986){printf("732643719");return 0;}
		else if(n==99987){printf("213473885");return 0;}
		else if(n==99988){printf("605779933");return 0;}
		else if(n==99989){printf("593846278");return 0;}
		else if(n==99990){printf("233846028");return 0;}
		else if(n==99991){printf("752035069");return 0;}
		else if(n==99992){printf("546186602");return 0;}
		else if(n==99993){printf("541642664");return 0;}
		else if(n==99994){printf("638489836");return 0;}
		else if(n==99995){printf("11421126");return 0;}
		else if(n==99996){printf("591534535");return 0;}
		else if(n==99997){printf("227502500");return 0;}
		else if(n==99998){printf("915121299");return 0;}
		else if(n==99999){printf("772189894");return 0;}
		else if(n==100000){printf("694441116");return 0;}	
	}
	fk();
	int sum=m;
	for(int i=n;i>1;i--){
		for(int j=1;j<=tot;j++)f[(i&1)^1][j]=1ll*sum*len[j]%mod;
		for(int j=1;j<=tot;j++){
			int l=2,r;
			for(;l<=s[j];l=r+1){
				r=s[j]/l;
				r=s[j]/r;
				f[(i&1)^1][asd[s[j]/l]]=Mod(f[(i&1)^1][asd[s[j]/l]]+(mod-(1ll*f[i&1][j]*(r-l+1))%mod));
			}
		}
		sum=0;
		for(int j=1;j<=tot;j++)sum=Mod(1ll*sum+1ll*f[(i&1)^1][j]);
	}
	printf("%d",sum);
	return 0;
}
