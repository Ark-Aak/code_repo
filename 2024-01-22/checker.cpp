#include <iostream>
#include <fstream>
using namespace std;
using ll = long long;
const int N = 5005;
ll a[N],b[N],ans[N];int n;
inline ll f(int i,int j,int k) {return a[i] * b[j] + a[j] * b[k] + a[k] * b[i];}
inline bool chk(int i,int j,int k) {return f(i,j,k) >= f(k,j,i);}
int main (int argc,char *argv[])
{
    ios::sync_with_stdio(false);
    if (argc <= 2) {cout << "You need to specify input file and output file." << endl;return -1;}
    ifstream inf(argv[1]),ouf(argv[2]);
    inf >> n;for (int i = 1;i <= n;i++) inf >> a[i] >> b[i];
    ouf >> ans[1];if (ans[1] == -1) {cout << "No solution reported." << endl;return 0;}
    for (int i = 2;i <= n;i++) ouf >> ans[i];
    for (int i = 1;i <= n - 2;i++)
        if (!chk(ans[i],ans[i + 1],ans[i + 2]))
        {
            cout << "Invalid triple " << ans[i] << ' ' << ans[i + 1] << ' ' << ans[i + 2] << endl;
            cout << "Wrong Answer." << endl;return 1;
        }
    cout << "Accepted." << endl;
    return 0;
}
