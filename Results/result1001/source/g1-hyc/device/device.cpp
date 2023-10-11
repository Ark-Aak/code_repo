#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("device.in","r",stdin);
    freopen("device.out","w",stdout);
	int q;
	scanf("%d",&q);
    while(q--)
	{
        int k,n,cnt[14]={0};
        scanf("%d%d",&k,&n);
        cnt[k%10]++,cnt[k/10%10]++,cnt[k/100]++;
    	int maxx=0;
    	for(int i=0;i<10;i++)
    		maxx=max(maxx,cnt[i]);
        if(maxx==3||!n)
        	puts("1");
        else if(n>=2)
		{
            if(maxx==1)
            	puts("27");
            else
            	puts("8");
        }
        else
		{
            if(maxx==1)
            	puts("24");
            else
            	puts("7");
        }
    }
    return 0;
}
