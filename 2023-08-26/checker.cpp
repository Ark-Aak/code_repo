#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=1e3+5;
int w=30,n,k,s[N],t[M];

// 这个函数接受一个流，从其中读入
// 检查路径的合法性并返回路径长度
// 当 stream 为 ans 时，所有 stream.quitf(_wa, ...)
// 和失败的 readXxx() 均会返回 _fail 而非 _wa
// 也就是说，如果输出非法，对于选手输出流它将返回 _wa，
// 对于标准输出流它将返回 _fail

int readAns(InStream& stream){
	int cnt=0;
	unordered_map<int,bool> used;
	used.clear();
	for(int i=1;i<=k;i++){
	    int v=stream.readInt(1,(1<<w)-1,format("t[%d]",i).c_str());
	    if(used[v]){
	    	stream.quitf(_wa,"integer %d was used twice",v);
	    }
	    used[t[i]=v]=1;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if((t[i]&s[j])==s[j]){
				cnt++;
			}
		}
	}
	return cnt;
}

int main(int argc, char* argv[]){
	
	registerTestlibCmd(argc, argv);
	n=inf.readInt();
	k=inf.readInt();
	for(int i=1;i<=n;i++){
		s[i]=inf.readInt();
	}
	
	int jans=readAns(ans);
	int pans=readAns(ouf);
	if(jans>pans){
		quitf(_wa,"jury has the better answer: jury's answer=%d , participant's answer=%d\n",jans,pans);
	}else if(jans==pans){
		quitf(_ok,"answer=%d\n",pans);
	}else{
		quitf(_fail,"so sad! participant has the better answer: jury's answer=%d , participant's answer=%d\n",jans,pans);
	}
	
	return 0;
}
