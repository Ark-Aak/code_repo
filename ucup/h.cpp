#include<bits/stdc++.h>
using namespace std;
#define F fflush(stdout)
int n;

map <pair <int, int>, int> mp;

int sum;

int que(int l, int r) {
	if (mp[make_pair(l, r)]) return mp[make_pair(l, r)];
	sum += r - l + 1;
	printf("? %d %d\n", l, r);
	F;
	int p;
	scanf("%d", &p);
	mp[make_pair(l, r)] = p;
	return p;
}

void solve(){
	sum = 0;
	mp.clear();
	scanf("%d",&n);
	int p = que(1, n);
	int l=1,r=n;
	if(p==1)
	{
		l=2;
	}
	else
	{
		int dk = que(1, p);
		if(dk==p)	r=p-1;
		else	l=p+1;
	}
	if(l==p+1)
	{
		while(l<r)
		{
			int mid=(l+r)>>1;
			int sp = que(p, mid);
			if(sp==p)	r=mid;
			else	l=mid+1;
		}
	}
	else
	{
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			int sp = que(mid, p);
			if(sp==p)	l=mid;
			else	r=mid-1;
		}
	}
	cerr << sum << endl;
	assert(sum <= 3 * n);
	printf("! %d\n",l);
	F;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T --> 0) solve();
}
