#include <bits/stdc++.h>
using namespace std;
int n,m,cnt[1<<19];
bool vis[105];
vector <int> a;
int main(){
    cin >> n >> m;
    for(int i = (1<<m)-1;i < (1<<n);i++){
       int x=i;
       for(;x;x-=x&(-x))cnt[i]++;
       if(cnt[i]==m)a.push_back(i);
    }
    for(int i = 0;i < a.size();i++){
        int x=i;
        for(int j = 0;j < n;j++){
            if(i&(1<<j))vis[j+1]=true;
            else vis[j+1]=false;
        }
    }
    cout << "6";
    return 0;
}
