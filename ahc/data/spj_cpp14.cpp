#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
typedef struct{
	int Sx,Sy,Tx,Ty;
	bool svd;
}Person;
Person Pn[1611];
int Fd,del;
int n,m,T;
int op[51][51],mp[51][51];
pair<int,int> fa[51][51];
bool sted[51][51];
pair<int,int> find(pair<int,int> x)
{
	return fa[x.first][x.second] == x ? x : fa[x.first][x.second] = find(fa[x.first][x.second]);
}
bool Flag = 0;
void Merge(pair<int,int> x,pair<int,int> y)
{
	x = find(x),y = find(y);
	if(x == y) return;
	Flag |= (sted[x.first][x.second] && sted[y.first][y.second]);
	if(!sted[y.first][y.second]) swap(x,y);
	fa[x.first][x.second] = y;
	sted[y.first][y.second] |= sted[x.first][x.second];
}
inline void ReCalc()
{
	del = 0;
	for(int i = 1;i <= m;i++)
	{
		signed sx = Pn[i].Sx,sy = Pn[i].Sy,tx = Pn[i].Tx,ty = Pn[i].Ty,W = abs(sx - tx) + abs(sy - ty);
		bool flag = !Pn[i].svd;
		for(signed fx = max(sx - 2,1);flag && fx <= sx + 2 && fx <= n;fx++)
			for(signed fy = max(sy - 2,1);flag && fy <= sy + 2 && fy <= n;fy++) if(abs(fx - sx) + abs(fy - sy) <= 2 && op[fx][fy] == 7)
				for(signed ex = max(tx - 2,1);flag && ex <= tx + 2 && ex <= n;ex++)
					for(signed ey = max(ty - 2,1);flag && ey <= ty + 2 && ey <= n;ey++) if(abs(ex - tx) + abs(ey - ty) <= 2 && op[ex][ey] == 7 && find({fx,fy}) == find({ex,ey}))
						flag = 0;
		if(!flag) del += W,Pn[i].svd = 1;
	}
}
const int ow[7] = {15,10,5,12,9,3,6};
inline void Build(pair<int,pair<int,int> > opt)
{
	int o = opt.first,x = opt.second.first,y = opt.second.second;
	mp[x][y] = ow[o];
	if(!o)
	{
		if(Fd < 5000)
		{
			quitf(_wa, "Insufficient funds");
		}
		op[x][y] = 7,Fd -= 5000;
		find({x,y});
		sted[fa[x][y].first][fa[x][y].second] = Flag = 1;
		if(x > 1 && (mp[x - 1][y] & 4)) Merge({x - 1,y},{x,y});
		if(x < n && (mp[x + 1][y] & 1)) Merge({x + 1,y},{x,y});
		if(y > 1 && (mp[x][y - 1] & 2)) Merge({x,y - 1},{x,y});
		if(y < n && (mp[x][y + 1] & 8)) Merge({x,y + 1},{x,y});
	}else{
		if(Fd < 100)
		{
			quitf(_wa, "Insufficient funds");
		}
		op[x][y] = o,Fd -= 100;
		o = mp[x][y];
		if((o & 1) && x > 1 && (mp[x - 1][y] & 4)) Merge({x,y},{x - 1,y});
		if((o & 4) && x < n && (mp[x + 1][y] & 1)) Merge({x,y},{x + 1,y});
		if((o & 8) && y > 1 && (mp[x][y - 1] & 2)) Merge({x,y},{x,y - 1});
		if((o & 2) && y < n && (mp[x][y + 1] & 8)) Merge({x,y},{x,y + 1});
	}
}
signed main(signed argc, char** argv)
{
	registerTestlibCmd(argc, argv);
	n = inf.readInt(50, 50);
	m = inf.readInt(50, 1600);
	Fd = inf.readInt(11000, 20000);
	T = inf.readInt(800, 800);
	const int pans = ans.readInt();
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			fa[i][j] = {i,j};
	for(int i = 1;i <= m;i++)
	{
		int sx,sy,tx,ty;
		sx = inf.readInt(0, n - 1);
		sy = inf.readInt(0, n - 1);
		tx = inf.readInt(0, n - 1);
		ty = inf.readInt(0, n - 1);
		sx++,sy++,tx++,ty++;
		Pn[i] = {sx,sy,tx,ty};
	}
	//from output
	for(int i = 1;i <= T;i++)
	{
		signed opt,x,y;
		opt = ouf.readInt(-1, 6);
		if(opt != -1)
		{
			x = ouf.readInt(0, n - 1);
			y = ouf.readInt(0, n - 1);
			x++, y++;
			Build({(int) opt,{x,y}});
			if(Flag) ReCalc(),Flag = 0;
		}
		Fd += del;
	}
	const double score = Fd * 1.0 / pans * 100.0;
	if (score > 100) quitf(_ok, "Your answer is better! Your score = %d and std = %d", Fd, pans);
	else quitp(score, "Accepted, Your score = %d", Fd);
	return 0;
}
