#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=1e5+7;
int n,k; 
class perm{
	public:
		int a[Maxn];
		perm(){
			memset(a,0,sizeof a);
		}
		friend perm operator+(perm x,const perm y){
			perm z;
			for(int i=1;i<=n;i++)
				z.a[x.a[i]]=y.a[i];
			return z;
		}
		inline void print(){
			for(int i=1;i<=n;i++)
				printf("%d ",a[i]);
		}
}p,q,r;
int main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&p.a[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&q.a[i]);
	for(int i=1;i<=k;i++){
		if(i&1) p=p+q;
		else q=q+p;
	}
	if(k&1) q.print();
	else p.print();
	return 0;
}
/*
3 3
1 3 2
2 1 3

5 4
4 5 1 2 3
3 2 1 5 4

5 100
4 5 1 2 3
3 2 1 5 4

-> 4 5 1 2 3

5 100
1 2 3 5 4
2 3 1 4 5
*/
