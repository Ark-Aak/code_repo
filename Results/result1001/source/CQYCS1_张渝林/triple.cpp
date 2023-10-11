#include<bits/stdc++.h>
#define ll long long
#define int ll
#define L xd[x].l
#define R xd[x].r
#define mid (l+r>>1LL)
#define lc L,l,mid
#define rc R,mid+1,r
#define Root 1,1,n
#define OK l>=Ll&&r<=Rr
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define pb push_back
#define ull unsigned ll
#define e(x) for(int i=h[x],y=to[i];i;i=nxt[i],y=to[i])
#define E(x) for(auto y:p[x])
#define Pi pair<int,int>
#define ui unsigned ll
inline int read(){int s=0,w=1;char c=getchar();while(c<48||c>57) {if(c=='-') w=-1;c=getchar();}while(c>=48&&c<=57) s=(s<<1)+(s<<3)+c-48,c=getchar();return s*w;}
inline void pf(ll x){if(x<0) putchar('-'),x=-x;if(x>9)pf(x/10);putchar(x%10+48);}
const int N =5e5+5,M=1e6+5,inf=(1LL<<31)-1;
const ll llf=1e18,mod=1e8+7,bas=131;
const ui base=13331;
using namespace std;
int T,p,q,r,a,b,c;
void out(int x){
	pf(x),putchar('\n');
}
inline int get(int a,int b,int x,int y){
	if(a==x&&b==y)return 0;
	if(a==x||b==y)return 1;
	if(x-a==y-b)return 1;
	if(!a||!b)return 2;
	int c=x/a;
	if(1LL*a*c==x&&1LL*b*c==y)return 1;
	return 2;
}
inline int got(int a,int b,int c,int x,int y,int z){
	if(x-a==y-b&&x-a==z-c)return 1;
	if(a==x&&b==y&&z==c)return 0;
	if(a&&b&&c){
		if(x%a==0){
			int k=x/a;
			if(k*b==y&&k*c==z)return 1;
		}
	}
	return 2;
}
int f[4],g[4];
inline int check(){
	f[1]=p,f[2]=q,f[3]=r,g[1]=a,g[2]=b,g[3]=c;
	int ad,ml;
	ad=ml=llf;
	rep(Sp,1,7)rep(Sm,1,7){
		ad=ml=llf;
		bool fl=1;
		rep(i,1,3){
			if(!((Sp>>i-1)&1)&&!((Sm>>i-1)&1)){
				if(f[i]!=g[i]){
					fl=0;
					break;
				}
			}
			if(((Sp>>i-1)&1)&&!((Sm>>i-1)&1)){
				if(ad!=llf){
					if(f[i]+ad!=g[i]){
						fl=0;
						break;
					}
				}
				ad=g[i]-f[i]; 
			}
			if(((Sm>>i-1)&1)&&!((Sp>>i-1)&1)){
				if(ml!=llf){
					if(f[i]*ml!=g[i]){
						fl=0;
						break;
					} 
				}
				if(!f[i]){
					if(!g[i])continue;
					fl=0;
					break;
				}
				if(g[i]%f[i]!=0){
					fl=0;
					break;
				}
				ml=g[i]/f[i];
			}
		}
		if(!fl)continue;
		int pra=llf,prb=llf;
		rep(i,1,3){
			int nw=f[i];
			if(((Sp>>i-1)&1)&&((Sm>>i-1)&1)){
				if(ad!=llf&&ml!=llf){
					if((f[i]+ad)*ml!=g[i]){
						fl=0;
						break;
					}
					continue;
				}
				if(ad!=llf){
					int nw=f[i]+ad;
					if(!g[i]){
						if(nw)ml=0;
						continue;
					}
					if(!f[i]){
						fl=0;
						break;
					}
					if(g[i]%f[i]!=0){
						fl=0;
						break;
					}
					ml=g[i]/f[i];
				}
				else if(ml!=llf){
					if(ml==0){
						if(g[i]){
							fl=0;
							break;
						}
						continue;
					}
					if(g[i]%ml!=0){
						fl=0;
						break;
					}
					ad=g[i]/ml-f[i];
				}else {
					if(pra==llf)pra=f[i],prb=g[i];
					else {
						if(g[i]==prb){
							ml=0;
							continue;
						}
						if(f[i]==pra){
							fl=0;
							break;
						}
						pra-=f[i],prb-=g[i];
						if(prb%pra!=0){
							fl=0;
							break;
						}
						ml=prb/pra;
						if(g[i]%ml!=0){
							fl=0;
							break;
						}
						ad=g[i]/ml-f[i];
					}
				}
			}
		}
		//if(fl)cout <<ad<<" "<<ml<<'\n';
		if(fl)return 2;
	}
	rep(Sp,1,7)rep(Sm,1,7){
		ad=ml=llf;
		bool fl=1;
		rep(i,1,3){
			if(!((Sp>>i-1)&1)&&!((Sm>>i-1)&1)){
				if(f[i]!=g[i]){
					fl=0;
					break;
				}
			}
			if(((Sp>>i-1)&1)&&!((Sm>>i-1)&1)){
				if(ad!=llf){
					if(f[i]+ad!=g[i]){
						fl=0;
						break;
					} 
				}
				ad=g[i]-f[i];
			}
			if(((Sm>>i-1)&1)&&!((Sp>>i-1)&1)){
				if(ml!=llf){
					if(f[i]*ml!=g[i]){
						fl=0;
						break;
					} 
				}
				if(!f[i]){
					fl=0;
					break;
				}
				if(g[i]%f[i]!=0){
					fl=0;
					break;
				}
				ml=g[i]/f[i];
			}
		}
		//if(Sp==7&&Sm==7)cout <<ad<<" "<<ml<<" "<<fl<<endl;
		if(!fl)continue;
		int pra=llf,prb=llf;
		rep(i,1,3){
			//if(Sp==Sm&&Sp==7)cout <<i<<" "<<ad<<" "<<ml<<endl;
			if(((Sp>>i-1)&1)&&((Sm>>i-1)&1)){
				if(ad!=llf&&ml!=llf){
					if(f[i]*ml+ad!=g[i]){
						fl=0;
						break;
					}
					continue;
				}
				else if(ad!=llf){
					int nw=g[i]-ad;
					if(nw==0){
						if(f[i]==0)continue;
						ml=0;
						continue;
					}
					if(!f[i]){
						fl=0;
						break;
					}
					if(nw%f[i]!=0){
						fl=0;
						break;
					}
					ml=nw/f[i];
				}
				/*
1
-4 -10 -5 -7 -1 -6
*/
				else if(ml!=llf){
					int nw=f[i]*ml;
					ad=g[i]-nw;
				}else {
					if(pra==llf)pra=f[i],prb=g[i];
					else {
						if(g[i]==prb){
							if(f[i]==pra)continue;
							ml=0,ad=g[i];
							continue;
						}
						//if(Sp==Sm&&Sp==7)cout <<prb<<" "<<pra<<endl;
						if(f[i]==pra){
							fl=0;
							break;
						}
						pra-=f[i],prb-=g[i];
						//if(Sp==Sm&&Sp==7)cout <<prb<<" "<<pra<<endl;
						if(prb%pra!=0){
							fl=0;
							break;
						}
						ml=prb/pra;
						ad=g[i]-f[i]*ml;
					}
				}
			}
		}
		if(fl)return 2;	
	}
	return 3;
}
signed main(){
	freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
	T=read();
	while(T--){
		p=read(),q=read(),r=read(),a=read(),b=read(),c=read();
		int ct=(p==a)+(q==b)+(c==r);
		if(ct==3)out(0);
		else if(ct==2)out(1);
		else if(ct==1){
			int d=0,e;
			if(p^a)d=a-p;
			if(q^b)d?e=b-q:d=b-q;
			if(c^r)e=c-r;
			if(d==e){
				out(1);
				continue;
			}
			if((p^a&&!p)||(q^b&&!q)||(c^r&&!r)){
				out(2);
				continue;
			}
			if((p^a&&(a%p!=0))||(q^b&&(b%q!=0))||(c^r&&(c%r!=0))){
				out(2);
				continue;
			}
			d=0,e=0;
			if(p^a)d=a/p;
			if(q^b)d?e=b/q:d=b/q;
			if(c^r)e=c/r;
			if(d==e)out(1);
			else out(2);
		}
		else {
			int ans=3;
			ll d=a-p,e=b-q,f=c-r;
			int ct=(d==e)+(e==f)+(d==f);
			if(ct==3)ans=1;
			if(ct==1)ans=2;
			if(d+e==f||d+f==e||e+f==d)ans=min(ans,2LL);
			d=e=f=-inf;
			if(p)if(a%p==0)d=a/p;
			if(q)if(b%q==0)e=b/q;
			if(r)if(c%r==0)f=c/r;
			ct=(d==e&&d!=-inf)+(d==f&&d!=-inf)+(f==e&&e!=-inf);
			if(ct==3)ans=1;
			if(ct==1)ans=min(ans,2LL);
			if(d!=-inf&&e!=-inf&&f!=-inf){
				if(d*e==f||d*f==e||e*f==d)ans=min(ans,2LL);
			} 
			if(ans^3){
				out(ans);
				continue;
			}
			ans=min(ans,1LL+min({get(q+a-p,r+a-p,b,c),get(q,r+a-p,b,c),get(q+a-p,r,b,c),get(p+b-q,r+b-q,a,c),get(p,r+b-q,a,c),get(p+b-q,r,a,c),get(p+c-r,q+c-r,a,b),get(p,q+c-r,a,b),get(p+c-r,q,a,b)}));
			if(p)if(a%p==0){
				d=a/p;
				ans=min(ans,1LL+min({get(q*d,r*d,b,c),get(q,r*d,b,c),get(q*d,r,b,c)}));
			}
			if(q)if(b%q==0){
				d=b/q;
				ans=min(ans,1LL+min({get(p*d,r*d,a,c),get(p,r*d,a,c),get(p*d,r,a,c)}));
			}
			if(r)if(c%r==0){
				d=c/r;
				ans=min(ans,1LL+min({get(p*d,q*d,a,b),get(p,q*d,a,b),get(p*d,q,a,b)}));
			}
			ans=min(ans,1LL+min({get(p,q,a-c+r,b-c+r),get(p,r,a-b+q,c-b+q),get(q,r,b-a+p,c-a+p),get(p,q,a,b-c+r),get(p,r,a,c-b+q),get(q,r,b-a+p,c),get(p,q,a-c+r,b),get(p,r,a-b+q,c),get(q,r,b-a+p,c)}));
			if(p)if(a%p==0){
				d=a/p;
				if(d){
					if(b%d==0&&c%d==0)ans=min(ans,1LL+get(q,r,b/d,c/d));
					if(b%d==0)ans=min(ans,1LL+get(q,r,b/d,c));
					if(c%d==0)ans=min(ans,1LL+get(q,r,b,c/d));
					ans=min(ans,min({get(q*d,r,b,c),get(q,r*d,b,c),get(q*d,r*d,b,c)})+1LL);
				}
			}
			if(q)if(b%q==0){
				d=b/q;
				if(d){
					if(a%d==0&&c%d==0)ans=min(ans,1LL+get(p,r,a/d,c/d));
					if(a%d==0)ans=min(ans,1LL+get(p,r,a/d,c));
					if(c%d==0)ans=min(ans,1LL+get(p,r,a,c/d));
					ans=min(ans,min({get(p*d,r,a,c),get(p,r*d,a,c),get(p*d,r*d,a,c)})+1LL);
				}
			}
			if(r)if(c%r==0){
				d=c/r;
				if(d){
					if(a%d==0&&b%d==0)ans=min(ans,1LL+get(p,q,a/d,b/d));
					if(a%d==0)ans=min(ans,1LL+get(p,q,a/d,b));
					if(b%d==0)ans=min(ans,1LL+get(p,q,a,b/d));
					ans=min(ans,min({get(p*d,q,a,b),get(p,q*d,a,b),get(p*d,q*d,a,b)})+1LL);
				}
			}
			ans=min(ans,1LL+min({got(0,0,0,a,b,c),got(p,0,0,a,b,c),got(0,q,0,a,b,c),got(0,0,r,a,b,c),got(p,q,0,a,b,c),got(p,0,r,a,b,c),got(0,q,r,a,b,c)}));
			ans=min(ans,check());
			out(ans);
		}
	}
	return 0;
}
