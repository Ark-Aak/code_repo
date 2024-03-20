#include<bits/stdc++.h>
using namespace std;
const int L=7,C=4; // L Length, C Number of chars
int main(){
  ios::sync_with_stdio(false);
  string s="A1B2C3D"; // Start
  set<string> S={s};
  auto rev=[&](string s,int u){
    string t;
    for(int i=u-1;~i;i--)
      if(isdigit(s[i]))t+=s[i];
      else if(s[i]<'A'+C)t+=s[i]+C;
      else t+=s[i]-C;
    t+=s[u];
    for(int i=L-1;i>u;i--)
      if(isdigit(s[i]))t+=s[i];
      else if(s[i]<'A'+C)t+=s[i]+C;
      else t+=s[i]-C;
    return t;
  };
  auto print=[&](string s){
    for(char i:s)
      if(isdigit(i)||i<'A'+C)cout<<i;
      else cout<<(char)(i-C)<<'\'';
    cout<<endl;
  };
  queue<pair<string,bool> > q; q.emplace(s,0);
  map<string,string> mp;
  while(!q.empty()){
    auto [u,c]=q.front(); q.pop();
	/* cout << u << endl; */
    if(u=="A3B1C2D"){ // End
      vector<string> r;
      while(mp.find(u)!=mp.end())
        r.emplace_back(u),u=mp[u];
      reverse(r.begin(),r.end());
      cout<<s<<endl;
      for(auto i:r)print(i);
      return 0;
    }
    for(int i=0;i<L;i++)
      if(isdigit(u[i])){
        string t=rev(u,i);
        if(S.find(t)==S.end())
          mp[t]=u,S.emplace(t),q.emplace(t,c+1);
      }
  }
  return 0;
}
