int sol(int n,int m,int k,int s_1,int s_2,int s_3){
	if(k==0)return 1;
	int S_1=poww(s_1,mod-2);
	inv[k]=s_3;
	for(int i=k-1;i>=0;i--)inv[i]=1ll*inv[i+1]*(m+i+1)%mod;
	int ans=0;
	for(int i=0;i<=k;i++){
		if((k-i)&1)ans=Mod(ans+mod-1ll*s[i]*inv[i]%mod*s_1%mod*s_2%mod);
		else ans=Mod(ans+1ll*s[i]*inv[i]%mod*s_1%mod*s_2%mod);
		s_1=1ll*s_1*(n+i+1)%mod;
		s_2=1ll*s_2*(m+i)%mod;
	}
	ans=1ll*S_1*m%mod*ans%mod;
	return ans;
}
