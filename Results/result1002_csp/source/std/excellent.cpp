#include<bits/stdc++.h>
using namespace std;
int T;
string st;
int n,lcp[3050][3050];
int lcnt[3050],rcnt[3050];
long long ans=0;
int main() {
    freopen("excellent.in","r",stdin);
    freopen("excellent.out","w",stdout);
    cin>>T;
    while (T--) {
        cin>>st;
        n=st.size();
        memset(lcp,0,sizeof(lcp));
        for (int i=n-1;i>=0;i--) {
            for (int j=n-1;j>=0;j--) {
                if ((st[i]==st[j])||(st[i]=='?')||(st[j]=='?')) lcp[i][j]=lcp[i+1][j+1]+1;
                else lcp[i][j]=0;
            }
        }
        memset(lcnt,0,sizeof(lcnt));
        memset(rcnt,0,sizeof(rcnt));
        ans=0;
        for (int i=0;i<n;i++) {
            for (int len=1;i-len*2+1>=0;len++) {
                if (lcp[i-len*2+1][i-len+1]>=len) lcnt[i]++;
            }
            for (int len=1;i+len*2-1<n;len++) {
                if (lcp[i][i+len]>=len) rcnt[i]++;
            }
        }
        for (int i=0;i<n-1;i++) ans+=1ll*lcnt[i]*rcnt[i+1];
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}