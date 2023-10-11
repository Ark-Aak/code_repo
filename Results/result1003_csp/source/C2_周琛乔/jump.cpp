#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
inline void read(int &x){
   int f=1;x=0;char c=getchar();
   while((c<'0'||'9'<c)&&c^'-') c=getchar();
   if(c=='-') f=-1,c=getchar();
   while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-48,c=getchar();
   x*=f;
}
int n,a[N],id[N],ans[N],t[N];
inline bool cmp(int x,int y){return a[x]>a[y];}
void print(int x){
	if(x>9) print(x/10);
	putchar(48+x%10);
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		id[i]=i;
	}
	sort(id+1,id+n+1,cmp);
	for(int i=1,p=1,lt;i<=n;i++){
		if(a[id[i]]!=a[id[i-1]]){
			for(int j=p;j<i;j++)
				for(int x=id[j];x<=n;x+=x&-x) 
					t[x]=max(t[x],id[j]);
			p=i;
		}
		lt=0;
		for(int x=id[i];x;x-=x&-x) lt=max(lt,t[x]);
		ans[id[i]]=ans[lt]+1;
	}
	for(int i=1;i<=n;i++) print(ans[i]),putchar(' ');
	return 0;
}

