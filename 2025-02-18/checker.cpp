#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
#define ld double
const int M=1e6+5;
int C;
struct line{
	ld l,r,id;
	inline bool operator<(const line &x)const{
		return l==x.l?r>x.r:l<x.l;
	}
}P[M];
int n;
vector<line> tmp;
struct qu{
	ld pos;
	int op;
	inline bool operator<(const qu &x)const{return pos<x.pos;}
}Q[M<<1];
int qcnt;
unordered_set<int> s;
inline void guess(){
	qcnt=0;
	for(auto p:tmp)Q[++qcnt]={p.l,1},Q[++qcnt]={p.r,-1};
	sort(Q+1,Q+qcnt+1);
	int nop=0;
	ld lenth=0;
	for(int i=1;i<qcnt;i++){
		nop+=Q[i].op;
		if(nop==1)lenth+=Q[i+1].pos-Q[i].pos;
	}
	if(lenth<0.15)quitf(_wa,"Your answer is less than 0.15.");
	if(lenth>=0.65)quitf(_ok,"Accepted."); 
	quitp(_pc(min(100.0,400.0*(lenth-0.15)*(lenth-0.15))-16),("Your answer is "+to_string(lenth)).data());
	return;
}
int main(int argc,char **argv){
	 registerTestlibCmd(argc,argv);
//	registerLemonChecker(argc,argv);
	n=inf.readInt();
	for(int i=1;i<=n;i++)P[i].l=inf.readDouble(0,1),P[i].r=inf.readDouble(0,1);
	int k=ouf.readInt(1,n);
	for(int id,i=1;i<=k;i++){
		id=ouf.readInt(1,n);
		if(s.count(id))quitf(_wa,"Illegal Output --- Same ID.");
		s.insert(id);
		tmp.push_back(P[id]);
	}
	guess();
	return 0;
}
