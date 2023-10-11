#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+ch-'0',ch=getchar();}
    return x*f;
}
void write(int x)
{
    if(x<0){putchar('-'),x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
    return;
}
int main() 
{
		freopen("badge.in","r",stdin);
		freopen("badge.out","w",stdout);
    int n, q;
    n=read(),q=read();
    vector<pair<int, int>> intervals(n);

    for (int i = 0; i < n; ++i) {
        cin>> intervals[i].first >> intervals[i].second;
    }

    while (q--) {
        int m;
        m=read();
        vector<int> diff(n + 2, 0);

        for (int i = 0; i < m; ++i) {
            int x;
            x=read();
            diff[x]++;
        }
        vector<int> prefix_sum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + diff[i];
        }

        int answer = 0;
        for (const auto& interval : intervals) {
            int sum = prefix_sum[interval.second] - prefix_sum[interval.first - 1];
            if (sum % 2 == 1) {
                answer++;
            }
        }

        write(answer);
        putchar('\n');
    }

    return 0;
}

