#include<bits/stdc++.h>
#define MAXN 1000006
using namespace std;
typedef long long ll;

int t,n;
struct Point{
    ll x, y;
    Point(ll x=0, ll y=0):x(x), y(y){}
} P[MAXN];

bool chk_slope(const Point& P1, const Point& P2, const Point& P3, const Point& P4){
    ll dx1 = P2.x - P1.x, dy1 = P2.y - P1.y;
    ll dx2 = P4.x - P3.x, dy2 = P4.y - P3.y;
    return dy1*dx2 < dy2*dx1;
}

struct convex{
	vector<Point> vec;
	void add(Point p){
        while(vec.size() > 1 && chk_slope(vec[vec.size()-2],vec.back(),vec.back(),p)) vec.pop_back();
        vec.push_back(p);
	}

    bool chk(Point P1, Point P2){
        Point P3;
        if(vec.size()==1) P3 = vec[0];
        else{
            int l = 0, r = vec.size()-2, mid;
            while(l<r){
                mid = (l+r)/2;
                if(chk_slope(vec[mid],vec[mid+1],P1,P2)) r = mid;
                else l = mid+1;
            }
            if(chk_slope(vec[r],vec[r+1],P1,P2)) P3 = vec[r];
            else P3 = vec[r+1];
        }
        return (P2.x-P1.x) * P3.y > (P2.x-P1.x) * P2.y + (P2.y-P1.y) *(P3.x - P2.x);
    }
};

struct node{
    int l,r;
    convex d;
    node *ls, *rs;
} pool[2*MAXN], *rt;

int top = 0;
node* build(int l, int r){
    node *p = pool + (++top);
    p->l = l; p->r = r; p->d.vec.clear();
    p->ls = p->rs = 0;
    for(int i=l;i<=r;i++) p->d.add(P[i]);

    if(l==r) return p;

    int mid = (l+r)/2;
    p->ls = build(l, mid);
    p->rs = build(mid+1, r);
    return p;
}

int query(node *p, int ql, int qr, int i){
    if(ql > qr) return 0;
    if(p->l==ql && p->r==qr && p->d.chk(P[i], P[i+1])==0) return 0;
    if(p->l==p->r) return p->d.chk(P[i], P[i+1])?ql:0;

    int mid = (p->l+p->r)/2;
    if(qr <= mid) return query(p->ls, ql, qr, i);
    else if(ql >= mid+1) return query(p->rs, ql, qr, i);
    else{
        int res = query(p->ls, ql, mid, i);
        if(res) return res;
        else return query(p->rs, mid+1, qr, i);
    }
}

int main(){
    freopen("telpher.in", "r", stdin);
    freopen("telpher.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>t;
    //assert(t<=1e5);
    int nn = 0;
    while(t--){
        cin>>n;
        nn += n;
        for(int i=1;i<=n;i++){
            cin>>P[i].x>>P[i].y;
            //assert(P[i].x==i);
            //assert(0<=P[i].x && P[i].x<=1e9 && 0<=P[i].y && P[i].y<=1e9);
            //if(i>1) assert(P[i-1].x < P[i].x);
        }
        top = 0;
        rt = build(1, n);
        for(int i=1;i<n;i++){
            cout<<max(0,query(rt, i+2, n, i)-1)<<" ";
        }
        cout<<'\n';
    }
    //assert(nn <= 1e5);
    //cerr<<"nn = "<<nn<<'\n';
    return 0;
}
