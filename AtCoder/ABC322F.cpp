#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
const int maxn=1e5+5;
struct Tree
{
	int l0,r0;
	int l1,r1;
	int ml0,ml1;
	int lazy;
} tree[maxn<<2];
char val;
void up(int k,int l,int r)
{
	int mid=(l+r)>>1;
	///前缀最大1的个数
	tree[k].l1=tree[k<<1].l1;
	if(tree[k].l1==mid-l+1)
	{
		tree[k].l1+=tree[k<<1|1].l1;
	}
	///前缀最大0的个数
	tree[k].l0=tree[k<<1].l0;
	if(tree[k].l0==mid-l+1)
	{
		tree[k].l0+=tree[k<<1|1].l0;
	}
	///后缀最大1的个数
	tree[k].r1=tree[k<<1|1].r1;
	if(tree[k].r1==r-mid)
	{
		tree[k].r1+=tree[k<<1].r1;
	}
	///后缀最大0的个数
	tree[k].r0=tree[k<<1|1].r0;
	if(tree[k].r0==r-mid)
	{
		tree[k].r0+=tree[k<<1].r0;
	}
	///区间最大1和最大0的个数
	tree[k].ml1=max(max(tree[k<<1].ml1,tree[k<<1|1].ml1),tree[k<<1].r1+tree[k<<1|1].l1);
	tree[k].ml0=max(max(tree[k<<1].ml0,tree[k<<1|1].ml0),tree[k<<1].r0+tree[k<<1|1].l0);
}

void _swap(int k)
{
	swap(tree[k].l0,tree[k].l1);
	swap(tree[k].r0,tree[k].r1);
	swap(tree[k].ml0,tree[k].ml1);
}

void pushdowm(int k,int l,int r)
{
	if(l!=r)
	{
		tree[k<<1].lazy^=1;
		tree[k<<1|1].lazy^=1;
		_swap(k<<1);
		_swap(k<<1|1);
		tree[k].lazy=0;

	}

}

void build(int k,int l,int r)
{
	tree[k].lazy=0;
	if(l==r)
	{
		cin >> val;
		if(val=='1')
		{
			tree[k].l1=tree[k].r1=tree[k].ml1=1;
			tree[k].l0=tree[k].r0=tree[k].ml0=0;


		}
		else
		{
			tree[k].l1=tree[k].r1=tree[k].ml1=0;
			tree[k].l0=tree[k].r0=tree[k].ml0=1;

		}
		return ;

	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	up(k,l,r);

}

void update(int k,int l,int r,int L,int R)
{
	if(l>=L&&r<=R)
	{
		tree[k].lazy^=1;
		_swap(k);
		return ;

	}
	if(tree[k].lazy) pushdowm(k,l,r);
	int mid=(l+r)>>1;
	if(mid>=R) update(k<<1,l,mid,L,R);
	else if(mid<L) update(k<<1|1,mid+1,r,L,R);
	else
	{
		update(k<<1,l,mid,L,R);
		update(k<<1|1,mid+1,r,L,R);

	}
	up(k,l,r);

}

int query(int k,int l,int r,int L,int R)
{
	//cout << k << endl;
	if(l>=L&&r<=R)
	{
		return tree[k].ml1;

	}
	if(tree[k].lazy) pushdowm(k,l,r);
	int mid=(l+r)>>1;
	if(mid>=R) return query(k<<1,l,mid,L,R);
	else if(mid<L) return query(k<<1|1,mid+1,r,L,R);
	else
	{
		int m1 = query(k<<1,l,mid,L,R);
		int m2 = query(k<<1|1,mid+1,r,L,R);
		int m3=min(mid-L+1,tree[k<<1].r1);
		int m4=min(R-mid,tree[k<<1|1].l1);
		return max(max(m1,m2),m3+m4);

	}
	up(k,l,r);

}


int main()
{
	int N, M;
	cin >> N >> M;
	build(1,1,N);
	int q,L,R;
	while(M--)
	{
		cin >> q >> L >> R;
		//++R;
		if(q==1)
		{
			update(1,1,N,L,R);
		}
		else
		{
			cout << query(1,1,N,L,R) << endl;
		}
	}
	return 0;
}
