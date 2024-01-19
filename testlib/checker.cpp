# include "testlib.h"
# include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(int argc,char *argv[])
{
	registerTestlibCmd(argc,argv);
	int ans_sz=ans.readInt(),out_sz=ouf.readInt();
	if(ans_sz!=out_sz) quitf(_wa,"Expected %d elements, but %d found.",ans_sz,out_sz);
	vector<int> ja(ans_sz),pa(out_sz);
	for(int &i:ja) i=ans.readInt(0,mod-1);
	for(int &i:pa) i=ouf.readInt(0,mod-1);
	sort(ja.begin(),ja.end());
	sort(pa.begin(),pa.end());
	if(ja!=pa) quitf(_wa,"Expected multiset and output are different.");
	else quitf(_ok,"Correct answer!");
	return 0;
}
