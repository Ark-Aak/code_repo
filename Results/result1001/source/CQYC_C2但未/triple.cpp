#include<bits/stdc++.h>
#define int long long
using namespace std;
inline void read(int&x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
int t;
signed main(){
	freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
	read(t);
	while(t--){
		int x,y,z,ans=5;
		read(x);read(y);read(z);
		int a,b,c;
		read(a);read(b);read(c);
		
		if(a==x&&y==b&&z==c){
			//printf("0\n");
			ans=0;
		}
		if(a==b&&b==c&&a==0){
			ans=min(ans,1ll);
		}
		if(a==x&&y==b||a==x&&z==c||y==b&&z==c){
			//printf("1\n");
			ans=min(ans,1ll);
		}
		if(a==b&&b==c&&a!=0){
			ans=min(ans,2ll);
		}
		if(a==b&&c==0||a==c&&b==0||b==c&&a==0){
			ans=min(ans,2ll);
		}
		if(a==x){
			if(z+(b-y)==c)/*printf("1\n");*/ans=min(ans,1ll);
			else{
				if(y&&abs(b)%abs(y)==0&&z*(b/y)==c)/*printf("1\n");*/ans=min(ans,1ll);
				else ans=min(ans,2ll);//printf("2\n");
			}
		}
		else if(b==y){
			if(z+(a-x)==c)ans=min(ans,1ll);//printf("1\n");
			else{
				if(x&&abs(a)%abs(x)==0&&z*(a/x)==c)ans=min(ans,1ll);//printf("1\n");
				else ans=min(ans,2ll);//printf("2\n");
			}
		}
		else if(z==c){
			if(x+(b-y)==a)ans=min(ans,1ll);//printf("1\n");
			else{
				if(y&&abs(b)%abs(y)==0&&x*(b/y)==a)ans=min(ans,1ll);//printf("1\n");
				else ans=min(ans,2ll);//printf("2\n");
			}
		}
		else{
			if(y+(a-x)==b&&z+(a-x)==c)ans=min(ans,1ll);//printf("1\n");
			else{
				if(x&&abs(a)%abs(x)==0&&y*(a/x)==b&&z*(a/x)==c)ans=min(ans,1ll);//printf("1\n");
				else{
					if(y+(a-x)==b)ans=min(ans,2ll);//printf("2\n");
					else{
						if(z+(a-x)==c)ans=min(ans,2ll);//printf("2\n");
						else{
							if(z+(b-y)==c)ans=min(ans,2ll);//printf("2\n");
							else{
								if(x&&abs(a)%abs(x)==0&&y*(a/x)==b)ans=min(ans,2ll);//printf("2\n");
								else{
									if(x&&abs(a)%abs(x)==0&&z*(a/x)==c)ans=min(ans,2ll);//printf("2\n");
									else{
										if(y&&abs(b)%abs(y)==0&&z*(b/y)==c)ans=min(ans,2ll);//printf("2\n");
										else ans=min(ans,3ll);//printf("3\n");
									}
								}
							}
						}
					}
				}
			}
		}
		swap(a,x);swap(y,b);swap(z,c);
		if(a==b&&b==c&&a!=0){
			ans=min(ans,2ll);
		}
		if(a==b&&c==0||a==c&&b==0||b==c&&a==0){
			ans=min(ans,2ll);
		}
		if(a==x&&y==b&&z==c){
			//printf("0\n");
			ans=0;
		}
		if(a==b&&b==c&&a==0){
			ans=min(ans,1ll);
		}
		if(a==x&&y==b||a==x&&z==c||y==b&&z==c){
			//printf("1\n");
			ans=min(ans,1ll);
		}
		if(a==x){
			if(z+(b-y)==c)/*printf("1\n");*/ans=min(ans,1ll);
			else{
				if(y&&abs(b)%abs(y)==0&&z*(b/y)==c)/*printf("1\n");*/ans=min(ans,1ll);
				else ans=min(ans,2ll);//printf("2\n");
			}
		}
		else if(b==y){
			if(z+(a-x)==c)ans=min(ans,1ll);//printf("1\n");
			else{
				if(x&&abs(a)%abs(x)==0&&z*(a/x)==c)ans=min(ans,1ll);//printf("1\n");
				else ans=min(ans,2ll);//printf("2\n");
			}
		}
		else if(z==c){
			if(x+(b-y)==a)ans=min(ans,1ll);//printf("1\n");
			else{
				if(y&&abs(b)%abs(y)==0&&x*(b/y)==a)ans=min(ans,1ll);//printf("1\n");
				else ans=min(ans,2ll);//printf("2\n");
			}
		}
		else{
			if(y+(a-x)==b&&z+(a-x)==c)ans=min(ans,1ll);//printf("1\n");
			else{
				if(x&&abs(a)%abs(x)==0&&y*(a/x)==b&&z*(a/x)==c)ans=min(ans,1ll);//printf("1\n");
				else{
					if(y+(a-x)==b)ans=min(ans,2ll);//printf("2\n");
					else{
						if(z+(a-x)==c)ans=min(ans,2ll);//printf("2\n");
						else{
							if(z+(b-y)==c)ans=min(ans,2ll);//printf("2\n");
							else{
								if(x&&abs(a)%abs(x)==0&&y*(a/x)==b)ans=min(ans,2ll);//printf("2\n");
								else{
									if(x&&abs(a)%abs(x)==0&&z*(a/x)==c)ans=min(ans,2ll);//printf("2\n");
									else{
										if(y&&abs(b)%abs(y)==0&&z*(b/y)==c)ans=min(ans,2ll);//printf("2\n");
										else ans=min(ans,3ll);//printf("3\n");
									}
								}
							}
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

