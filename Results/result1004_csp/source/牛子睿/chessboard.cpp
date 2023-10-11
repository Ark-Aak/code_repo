#include <iostream>
#include <cstdio>
#include <vector>
const int N=2050;
struct node {
    int x,y;
};
std::vector<node> vt;
int getch(void) {
    char ch;
    do{ch=getchar();}while
    (ch!='0'&&ch!='1'&&ch!='?');
    return ch=='?'?2:ch-'0';
}
int n,m;
int map[N][N];
bool check(void) {
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            int a=map[i][j];
            int b=map[i+1][j];
            int c=map[i][j+1];
            int d=map[i+1][j+1];
            if(a==0&&b==1&&c==1&&d==0) return false;
            if(a==1&&b==0&&c==0&&d==1) return false;
        }
    return true;
}
bool res=false;
void dfs(int step) {
    if(res) return;
    if(step==vt.size()) {
        if(check()) res=true;
        return;
    }
    node x=vt[step];
    map[x.x][x.y]=1;
    dfs(step+1);
    map[x.x][x.y]=0;
    dfs(step+1);
}
int main() {
    freopen("chessboard.in","r",stdin);
    freopen("chessboard.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) map[i][j]=getch();
    bool flag=true;
    for(int i=n-1;i>=0;i--) {
        for(int j=n-1;j>=0;j--) {
            int& a=map[i][j];
            int& b=map[i+1][j];
            int& c=map[i][j+1];
            int& d=map[i+1][j+1];
            if(a==0&&b==1&&c==1&&d==0) {
                flag=false;
                break;
            }
            if(a==1&&b==0&&c==0&&d==1) {
                flag=false;
                break;
            }
            if(a==2&&b==1&&c==1&&d==0) a=1;
            if(a==2&&b==0&&c==0&&d==1) a=0;
            if(a==0&&b==2&&c==1&&d==0) b=0;
            if(a==1&&b==2&&c==0&&d==1) b=1;
            if(a==0&&b==1&&c==2&&d==0) c=0;
            if(a==1&&b==0&&c==2&&d==1) c=1;
            if(a==0&&b==1&&c==1&&d==2) d=1;
            if(a==1&&b==0&&c==0&&d==2) d=0;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(map[i][j]==2) vt.push_back((node){i,j});
    if(!flag) {
        printf("No\n");
        return 0;
    }
    if(!vt.empty()) {
        dfs(0);
        if(!res) {
            printf("No\n");
            return 0;
        }
        else {
            printf("Yes\n");
            for(int i=1;i<=n;i++,putchar('\n'))
                for(int j=1;j<=n;j++) printf("%d",map[i][j]);
        }
    }
    else {
        printf("Yes\n");
        for(int i=1;i<=n;i++,putchar('\n'))
            for(int j=1;j<=n;j++) printf("%d",map[i][j]);
    }
    return 0;
}