#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 5;

int s[MAXN],n;
vector<int> q[MAXN];

int read() {
	int w = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		w = (w << 3) + (w << 1) + (ch ^ 48);
		ch = getchar();
	}
	return w * f;
}

int cnt,w[MAXN];
int siz[MAXN],dep[MAXN],fa[MAXN],son[MAXN],id[MAXN],wt[MAXN],top[MAXN],m;
struct mat {int m[2][2];};
mat mul(mat x,mat y) {
	mat z;
	z.m[0][0]=min(x.m[0][0]+y.m[0][0],x.m[0][1]+y.m[1][0]);
	z.m[0][1]=min(x.m[0][0]+y.m[0][1],x.m[0][1]+y.m[1][1]);
	z.m[1][0]=min(x.m[1][0]+y.m[0][0],x.m[1][1]+y.m[1][0]);
	z.m[1][1]=min(x.m[1][0]+y.m[0][1],x.m[1][1]+y.m[1][1]);
	return z;
}//建立矩阵 

struct treeT {
	#define mid (l+r>>1)
	#define ls (rt<<1)
	#define rs (rt<<1|1)
	mat a[MAXN * 3];
	void build(int rt,int l,int r,int k) {
		if(l==r) {
			int W=(wt[l]>=k);
			a[rt].m[0][0]=W;
			a[rt].m[1][0]=1e8;
			a[rt].m[0][1]=(!W);
			a[rt].m[1][1]=(!W);
			return ;
		}
		build(ls,l,mid,k);
		build(rs,mid+1,r,k);
		a[rt]=mul(a[ls],a[rs]);
	}
	void update(int rt,int l,int r,int L,int R,int k) {
		if(L<=l && r<=R) {
			int W=(wt[l]>=k);
			a[rt].m[0][0]=W;
			a[rt].m[1][0]=1e8;
			a[rt].m[0][1]=(!W);
			a[rt].m[1][1]=(!W);
			return ;
		}
		if(L<=mid) update(ls,l,mid,L,R,k);
		if(mid<R) update(rs,mid+1,r,L,R,k);
		a[rt]=mul(a[ls],a[rs]);
	}
	mat query(int rt,int l,int r,int L,int R) {
		if(L<=l && r<=R) return a[rt];
		mat res;
		if(L<=mid && mid<R) res=mul(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
		if(L<=mid) res=query(ls,l,mid,L,R);
		if(mid<R) res=query(rs,mid+1,r,L,R);
		a[rt]=mul(a[ls],a[rs]);
		return res;
	}
}T[16]; //线段树 

struct treeS {
	mat a[MAXN * 3];
	void build(int rt,int l,int r,int k) {
		if(l==r) {
			int W=(wt[l]>=k);
			a[rt].m[0][0]=W;
			a[rt].m[1][0]=1e9;
			a[rt].m[0][1]=(!W);
			a[rt].m[1][1]=(!W);
			return ;
		}
		build(ls,l,mid,k);
		build(rs,mid+1,r,k);
		a[rt]=mul(a[rs],a[ls]);
	}
	void update(int rt,int l,int r,int L,int R,int k) {
		if(L<=l && r<=R) {
			int W=(wt[l]>=k);
			a[rt].m[0][0]=W;
			a[rt].m[1][0]=1e9;
			a[rt].m[0][1]=(!W);
			a[rt].m[1][1]=(!W);
			return ;
		}
		if(L<=mid) update(ls,l,mid,L,R,k);
		if(mid<R) update(rs,mid+1,r,L,R,k);
		a[rt]=mul(a[rs],a[ls]);
	}
	mat query(int rt,int l,int r,int L,int R) {
		if(L<=l && r<=R) return a[rt];
		mat res;
		if(L<=mid && mid<R) res=mul(query(rs,mid+1,r,L,R),query(ls,l,mid,L,R));
		if(L<=mid) res=query(ls,l,mid,L,R);
		if(mid<R) res=query(rs,mid+1,r,L,R);
		a[rt]=mul(a[rs],a[ls]);
		return res;
	}
}S[16]; //线段树 


void dfs1(int x,int f) {
	siz[x]=1;
	dep[x]=dep[f]+1;
	fa[x]=f;
	for(int i=0;i<q[x].size();i++) {
		int v=q[x][i];
		if(v==f) continue;
		dfs1(v,x);
		siz[x]+=siz[v];
		if(siz[son[x]]<siz[v]) son[x]=v;
	}
}
void dfs2(int x,int topf) {
	top[x]=topf;
	id[x]=++cnt;
	wt[cnt]=w[x];
	if(!son[x]) return ;
	dfs2(son[x],topf);
	for(int i=0;i<q[x].size();i++) {
		int v=q[x][i];
		if(v==fa[x] || v==son[x]) continue;
		dfs2(v,v);
	}
}
int query(int x,int y) {
	mat sum1[16],sum2[16]; 
	
	int flag1=0,flag2=0,fl=0;
	while(top[x]!=top[y]) {
		if(dep[top[x]]<dep[top[y]]) {
			swap(x,y);
			fl=!fl;
		} 
		if(!fl) {
			if(flag1) for(int i=0;i<=15;i++) sum1[i]=mul(sum1[i],T[i].query(1,1,n,id[top[x]],id[x]));
			else {
				flag1=1;
				for(int i=0;i<=15;i++) sum1[i]=T[i].query(1,1,n,id[top[x]],id[x]);
			}
		} else {
			if(flag2) for(int i=0;i<=15;i++) sum2[i]=mul(S[i].query(1,1,n,id[top[x]],id[x]),sum2[i]);
			else {
				flag2=1;
				for(int i=0;i<=15;i++) sum2[i]=S[i].query(1,1,n,id[top[x]],id[x]);
			}
		}
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) {
		swap(x,y);
		fl=!fl;
	}
	if(!fl) {
		if(flag1) for(int i=0;i<=15;i++) sum1[i]=mul(sum1[i],T[i].query(1,1,n,id[x],id[y]));
		else {
			flag1=1;
			for(int i=0;i<=15;i++) sum1[i]=T[i].query(1,1,n,id[x],id[y]);
		}
	} else {
		if(flag2) for(int i=0;i<=15;i++) sum2[i]=mul(S[i].query(1,1,n,id[x],id[y]),sum2[i]);
		else {
			flag2=1;
			for(int i=0;i<=15;i++) sum2[i]=S[i].query(1,1,n,id[x],id[y]);
		}
	}
	for(int i=0;i<=15;i++) {
		if(flag1 && flag2) sum1[i]=mul(sum1[i],sum2[i]);
		else if(flag2) sum1[i]=sum2[i];
	}
	int tmp=0;
	for(int i=0;i<=15;i++) tmp=tmp+min(sum1[i].m[0][0],sum1[i].m[0][1]);
	return tmp;
}//树剖板子 

signed main() {
	n = read();
	m = n - 1;
	for(int i=1;i<=n;i++) w[i] = read();
	for(int i=1;i<=m;i++) {
		int x,y;
		read(x,y);
		q[x].emplace_back(y);
		q[y].emplace_back(x);
	} 

	cnt=0;
	dfs1(1,0);
	dfs2(1,1);
	for(int i=0;i<=15;i++) T[i].build(1,1,n,i);
	for(int i=0;i<=15;i++) S[i].build(1,1,n,i);
	
	int Q;
	read(Q);
	while(Q--) {
		int t,x,u,v;
		read(t,x,u,v);
		wt[id[t]]=x;
		for(int i=0;i<=15;i++) T[i].update(1,1,n,id[t],id[t],i);
		for(int i=0;i<=15;i++) S[i].update(1,1,n,id[t],id[t],i);
		write(query(u,v));
		putch('\n');
	}
	flush();
	return 0;
}
/*
8 7
6 2 1 9 3 4 5 3
1 2
1 3
1 4
2 5
2 6
3 7
3 8
1
1 5 6 4
*/
