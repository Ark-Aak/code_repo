#ifdef ATCODER
double TL = 2.7;
#else
double TL = 2.0;
#endif

//#pragma GCC optimize("O3,Ofast,omit-frame-pointer,unroll-all-loops,tree-loop-vectorize,tree-slp-vectorize")
#pragma GCC optimize("O3,Ofast")
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <cmath>
#include <cassert>
#include <random>
#include <iomanip>
#include <unordered_set>
#include <chrono>
#include <iomanip>

int STANDARD = 1;
using namespace std;
#define F0(i,n) for (int i=0; i<n; i++)
#define FR(i,n) for (int i=n-1; i>=0; i--)
#define F1(i,n) for (int i=1; i<=n; i++)
#define CL(a,x) memset(x, a, sizeof(x));
#define SZ(x) ((int)x.size())
const int inf = 1000000000;
const double pi = acos(-1.0);
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-9;
template<class A, class B>
ostream& operator<<(ostream& os, const pair<A, B>& p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<class A, class B, class C>
ostream& operator<<(ostream& os, const tuple<A, B, C>& p) { os << "(" << get<0>(p) << "," << get<1>(p) << "," << get<2>(p) << ")"; return os; }
istream& operator>>(istream& is, pii& p) { is>>p.first>>p.second; return is; }
template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "["; F0(i,SZ(v)) { if (i>0) os << ","; os << v[i]; } os << "]"; return os;
}
template<class T>
ostream& operator<<(ostream& os, const set<T>& v) {
    os << "{"; int f=1; for(auto i:v) { if(f)f=0;else os << ","; cerr << i; } os << "}"; return os;
}
template<class T, class R>
ostream& operator<<(ostream& os, const map<T,R>& v) {
    os << "{"; int f=1; for(auto i:v) { if(f)f=0;else os << ", "; cerr << i.first << ":" << i.second; } os << "}"; return os;
}
void print_all() { cerr << endl; }
template <typename H, typename... T>
void print_all(H head, T... tail) { cerr << " " << head; print_all(tail...); }
#define PR(...) cerr << #__VA_ARGS__ << " =", print_all(__VA_ARGS__)

#ifdef ATCODERX
inline ll GetTSC() {
    ll lo, hi;
    asm volatile ("rdtsc": "=a"(lo), "=d"(hi));
    return lo + (hi << 32);
}
inline double GetSeconds() {
    return GetTSC() / 3.0e9;
}
#else
chrono::system_clock::time_point init_time = chrono::system_clock::now();
inline double GetSeconds() {
     chrono::system_clock::time_point current_time = chrono::system_clock::now();
     double ret =  chrono::duration_cast<std::chrono::nanoseconds>(current_time - init_time).count();
     return ret * 1e-9;
}
#endif

const int MAX_RAND = 1 << 30;
struct Rand {
    ll x, y, z, w, o;
    Rand() {}
    Rand(ll seed) { reseed(seed); o = 0; }
    inline void reseed(ll seed) { x = 0x498b3bc5 ^ seed; y = 0; z = 0; w = 0;  F0(i, 20) mix(); }
    inline void mix() { ll t = x ^ (x << 11); x = y; y = z; z = w; w = w ^ (w >> 19) ^ t ^ (t >> 8); }
    inline ll rand() { mix(); return x & (MAX_RAND - 1); }
    inline ll zh() { mix(); return x; }
    inline int nextInt(int n) { return rand() % n; }
    inline int nextInt(int L, int R) { return rand()%(R - L + 1) + L; }
    inline int nextBool() { if (o < 4) o = rand(); o >>= 2; return o & 1; }
    double nextDouble() { return rand() * 1.0 / MAX_RAND; }
};
Rand my(2023);
double saveTime;
double t_o[20];
ll c_o[20];
void Init() {
    saveTime = GetSeconds();
    F0(i, 20) t_o[i] = 0.0;
    F0(i, 20) c_o[i] = 0;
}
double Elapsed() { return GetSeconds() - saveTime; }
void Report() {
    double tmp = Elapsed();
    cerr << "-------------------------------------" << endl;
    cerr << "Elapsed time: " << tmp << " sec" << endl;
    double total = 0.0; F0(i, 20) { if (t_o[i] > 0) cerr << "t_o[" << i << "] = " << t_o[i] << endl; total += t_o[i]; } cerr << endl; //if (total > 0) cerr << "Total spent: " << total << endl;
    F0(i, 20) if (c_o[i] > 0) cerr << "c_o[" << i << "] = " << c_o[i] << endl;
    cerr << "-------------------------------------" << endl;
}
struct AutoTimer {
    int x;
    double t;
    AutoTimer(int x) : x(x) {
        t = Elapsed();
    }
    ~AutoTimer() {
        t_o[x] += Elapsed() - t;
    }
};
//#define AT(i) AutoTimer a##i(i)
#define AT(i)

// CONSTANTS
const int N = 64;
const int M = 1600;
const int U = (1<<12) - 1;
const int RAIL_COST = 100;
const int STATION_COST = 5000;
enum { UP, RIGHT, DOWN, LEFT };
const int DX[]={-1,0,1,0};
const int DY[]={0,1,0,-1};
enum { STATION, LEFT_RIGHT, UP_DOWN, LEFT_DOWN, LEFT_UP, UP_RIGHT, DOWN_RIGHT };
enum { S_WARP_UP, S_WARP_RIGHT, S_WARP_DOWN, S_WARP_LEFT, S_FIRST, S_CONNECT, S_PLACE, S_WARP };
int n, m, K, T;
int sum_fares;
int p[2][M];
pii no(-1, -1);
int fare[M];
int rail_type[4][4], rail_mask[8], mask_to_rail[16], mask_del[16][4];
ll zh[N*N], z[2][M], current_hash;
int qv[N*N], qz, s_eval[N*N];
int resv[N*N], resz, resk[N*N];
int resp[N*N], forp[N*N];
int old_station;
int E[N*N], swp, s_type, bv, delay, new_t;
ll hmask[N], vmask[N], smask[N];
int mv[N*N][4];
char X[N*N], Y[N*N];
double HALF = 16;
int cnt[2][M], income, half_income;
vector<int> s[2][M]; // stations that cover endpoint
vector<int> ins[2][N*N]; // endpoints inside station
char get_dir[N*N][N*N];
int d1[N*N][N*N];
ll bscore, score;
vector<pii> bsol, sol;
char pdirs[N*N][N*N][4], pn[N*N][N*N];
int level_threshold;
int allow_deep;
vector<int> prev_path[4], new_path[4];
vector<int> rp;
vector<int> ci;

const int LOGN = 1 << 16;
double logs[LOGN];

template<class T> auto REL(T& v) { return v[my.nextInt(SZ(v))]; }
template<class T> void RS(vector<T>& v) { F1(i, SZ(v)-1) { int j = my.nextInt(0, i); swap(v[i], v[j]); } }
template<class T> T sqr(T x) { return x*x; }
bool In(pii p) { return p.first >= 0 && p.first < n && p.second >= 0 && p.second < n; }
pii Move(pii p, pii q) { return pii(p.first + q.first, p.second + q.second); }
int ID(pii p) { return p.first * n + p.second; }
int ID(int x, int y) { return x * n + y; }
pii MP(int i) { return pii(i / n, i % n); }
pii Move(pii p, int k) { return pii(p.first + DX[k], p.second + DY[k]); }
#define GetDir(p1,p2) get_dir[(p1)][(p2)]

namespace n1 {
// Layer 1: 7 neurons, 4 inputs
vector<vector<double>> W1 = {
{-1.832502, -0.000025, -0.001926, -2.445335},
    {-0.000378, 0.000098, -0.000119, -0.000510},
    {-0.000153, 0.000021, -0.000027, -0.000027},
    {-0.000256, 0.000040, -0.000165, 0.000147},
    {0.761019, 0.000037, -0.207970, 0.200759},
    {0.043224, 0.000017, 0.167831, 0.033230},
    {0.000723, -0.000004, 0.124511, 0.010348}};

vector<double> B1 = {-17.443274, 0.054358, -9.437000, -25.836348};

// Layer 2: 4 neurons, 7 inputs
vector<vector<double>> W2 = {
{0.002319, -1.657709, 0.083482, 0.254560, 0.179190, 0.207954, 0.128968},
    {0.000122, 0.000038, 0.000072, -0.000040, -0.000020, 0.000017, -0.000090},
    {0.038793, 0.293244, 0.066252, 0.102356, 0.086952, 0.094519, 0.079461},
    {0.305716, -1.468207, 0.427775, 0.707658, 0.570130, 0.638351, 0.511680}};

vector<double> B2 = {-7.579869, -0.433005, -7.132892, -7.434604, -7.109543, -7.470642, -7.209557};

// Layer 3: 7 neurons, 1 inputs
vector<vector<double>> W3 = {
{3.871789},
    {-7.217090},
    {4.409157},
    {5.635832},
    {5.040096},
    {5.338559},
    {4.781404}};

vector<double> B3 = {-3.558002};
}

namespace n2 {
// Layer 1: 7 neurons, 4 inputs
vector<vector<double>> W1 = {
{3.105037, 0.000042, -0.066462, 3.702779},
    {0.001277, -0.000093, -0.000031, 0.001287},
    {0.889558, 0.000068, -0.092936, 1.518269},
    {-0.000321, 0.000005, 0.000133, 0.001602},
    {-0.002330, 0.000081, 1.230948, -0.690421},
    {0.021409, -0.000028, 0.330062, -0.017476},
    {0.010791, 0.000054, 0.168347, 0.010074}};

vector<double> B1 = {54.889084, -1.008780, -66.048439, 34.963112};

// Layer 2: 4 neurons, 7 inputs
vector<vector<double>> W2 = {
{-0.000041, -0.703731, -1.365074, 0.285816, -0.000083, -0.087335, -1.412463},
    {0.000033, -0.000005, -0.000009, 0.000005, -0.000091, -0.000009, -0.000002},
    {-0.000011, 0.124084, 0.278311, 0.487236, 0.000305, 0.279239, 0.159941},
    {0.000017, 0.745242, -2.150756, 0.000523, -0.000070, -2.079226, -0.298332}};

vector<double> B2 = {-0.353689, 10.091592, -65.413940, -14.718496, -1.348196, -41.073463, -72.992920};

// Layer 3: 7 neurons, 1 inputs
vector<vector<double>> W3 = {
{-0.001148},
    {-3.280104},
    {6.653694},
    {0.790377},
    {0.002761},
    {3.463102},
    {7.207870}};

vector<double> B3 = {-13.796259};

}

namespace n3 {
// Layer 1: 7 neurons, 4 inputs
vector<vector<double>> W1 = {
{0.429554, -2.144368, 0.000006, -0.001722},
    {-0.000068, 0.000078, -0.000109, -0.000022},
    {-0.000241, -0.074689, -0.000025, 0.000115},
    {-0.000079, -0.000286, 0.000040, 0.000035},
    {-0.379987, 0.214587, -0.000015, 0.000120},
    {0.059193, 0.052055, -0.000096, 0.311024},
    {0.055229, 0.012726, -0.000045, 0.284849}};

vector<double> B1 = {11.438619, -42.520229, 0.290229, -26.433374};

// Layer 2: 4 neurons, 7 inputs
vector<vector<double>> W2 = {
{0.063089, -0.000003, -0.001362, 0.513836, -0.000038, -0.000014, -0.000657},
    {-1.053029, -0.000003, 0.941374, -1.204812, -0.000007, -0.000039, 0.000565},
    {0.000098, 0.000032, -0.000059, -0.000037, 0.000104, -0.000100, 0.000054},
    {0.106834, -0.000018, 0.335022, 0.002691, 0.000288, 0.000164, 0.227556}};

vector<double> B2 = {25.750971, 2.292044, -26.352736, 19.754801, -16.596367, 3.159562, -25.576263};

// Layer 3: 7 neurons, 1 inputs
vector<vector<double>> W3 = {
{-7.258137},
    {-0.000185},
    {4.935046},
    {-10.545694},
    {0.013994},
    {-0.009036},
    {1.235599}};

vector<double> B3 = {-25.426102};
};

namespace n8 {
// Layer 1: 7 neurons, 4 inputs
vector<vector<double>> W1 = {
{-3.108618, 0.668566, -0.001452, 0.000041},
    {-0.187708, -0.000100, -0.000069, -0.000023},
    {-2.753038, -0.000300, 0.000266, -0.000035},
    {-0.574781, 0.000722, 0.001055, 0.000076},
    {0.338475, -0.722893, 0.100108, 0.000040},
    {0.023534, 0.324961, 0.389767, -0.000017},
    {0.011557, 0.154389, 0.238246, 0.000004}};

vector<double> B1 = {-51.026642, -16.338747, -23.302853, -0.414518};

// Layer 2: 4 neurons, 7 inputs
vector<vector<double>> W2 = {
{-2.058636, 0.753777, 0.000004, 0.000105, -1.312217, -0.000068, 1.781877},
    {-0.416737, 0.036541, 0.000084, 0.000119, -0.787052, 0.000208, 0.110623},
    {0.458013, 0.330071, 0.000047, -0.000232, 0.312970, 0.000121, 0.790626},
    {0.000038, 0.000032, 0.000006, -0.000021, -0.000034, 0.000035, 0.000007}};

vector<double> B2 = {36.851742, -39.763462, 2.318196, 1.912889, -19.161768, -3.706848, -39.652248};

// Layer 3: 7 neurons, 1 inputs
vector<vector<double>> W3 = {
{-4.867108},
    {1.004799},
    {0.000622},
    {-0.001454},
    {5.193931},
    {-0.001426},
    {1.806426}};

vector<double> B3 = {-39.482677};
}

namespace n4 {
// Layer 1: 7 neurons, 6 inputs
vector<vector<double>> W1 = {
{-0.228164, -1.510077, -0.233737, 0.472086, 0.198073, -2.650489},
    {17.901831, -25.601585, 0.201988, -0.129606, -11.619744, -25.679491},
    {16.672073, -38.316544, 0.563311, -0.282862, -10.661283, -28.899534},
    {3.061845, 2.337394, -0.337938, -0.521319, -2.970644, 2.719802},
    {0.101634, -0.208126, 0.117553, -0.618853, 0.677767, 0.588442},
    {0.176604, 0.289944, -0.649990, 0.185594, 0.065234, -0.152594},
    {0.750768, 0.105581, -0.626505, -0.215567, 0.538181, 0.205407}};

vector<double> B1 = {12.553058, -23.601778, 0.000000, 0.000000, -8.455630, -20.984797};

// Layer 2: 6 neurons, 7 inputs
vector<vector<double>> W2 = {
{0.656754, 0.159629, 0.646423, -0.122646, -0.605153, 0.595224, 0.527024},
    {-1.261583, -1.444975, -0.796555, -0.645052, 1.063898, 0.919298, -0.808567},
    {0.531813, -0.441258, 0.468011, -0.279402, 0.179173, 0.043795, 0.046498},
    {-0.550085, -0.367175, -0.676561, -0.081623, -0.237688, 0.369145, 0.268900},
    {0.126792, 0.497642, -0.396607, 0.152135, 0.273897, 0.784062, -0.446451},
    {-0.588172, -1.340619, -0.805154, -0.176645, 1.252244, -0.263000, -0.152706}};

vector<double> B2 = {9.850118, -1.220105, 8.318170, -0.059907, -20.229342, -9.604852, 8.468923};

// Layer 3: 7 neurons, 1 inputs
vector<vector<double>> W3 = {
{-1.537077},
    {3.348498},
    {-2.985140},
    {-0.605814},
    {3.588256},
    {0.888939},
    {-1.580372}};

vector<double> B3 = {-9.561045};

}

namespace n5 {
// Layer 1: 7 neurons, 4 inputs
vector<vector<double>> W1 = {
{0.000005, -1.513016, 0.000017, -0.000153},
    {-0.000032, 0.000131, -0.000033, -0.000114},
    {-0.000018, -0.250315, -0.000023, -0.000046},
    {0.000047, -0.001140, 0.000026, -0.000248},
    {0.000007, 0.087881, -0.000005, 0.351952},
    {0.000037, 0.053087, -0.000050, 0.001074},
    {0.000032, 0.024743, -0.000014, 0.003391}};

vector<double> B1 = {0.298911, -67.428352, 0.158320, -50.552605};

// Layer 2: 4 neurons, 7 inputs
vector<vector<double>> W2 = {
{-0.000054, -0.000078, 0.000037, -0.000055, -0.000019, -0.000081, -0.000003},
    {0.000208, 0.000229, 0.000507, 0.700268, 0.601373, 0.582288, 0.541167},
    {0.000136, 0.000055, 0.000015, -0.000001, -0.000066, -0.000061, 0.000043},
    {-0.000615, 0.000154, 0.000556, 0.139655, 0.101647, 0.093546, 0.073703}};

vector<double> B2 = {-38.149307, -37.667427, 29.116932, -51.616169, -51.496483, -51.423710, -51.342354};

// Layer 3: 7 neurons, 1 inputs
vector<vector<double>> W3 = {
{0.295465},
    {0.269977},
    {-0.349975},
    {7.602253},
    {7.132672},
    {7.042845},
    {6.862276}};

vector<double> B3 = {-50.196194};
}



namespace n6 {
// Layer 1: 7 neurons, 7 inputs
vector<vector<double>> W1 = {
{-0.544727, -0.018632, 0.850639, 0.218882, 0.162035, 0.470479, -0.495130},
    {0.252403, -0.167446, -31.051052, -32.306618, 32.524998, 0.111749, -32.476883},
    {-0.394821, 0.542269, -26.253399, -22.529949, 33.437458, -0.071103, -29.869137},
    {0.244520, -0.447390, 0.414388, 1.145261, 0.009622, -0.104699, 0.061311},
    {-0.488408, -0.288278, 0.969341, 0.583905, 0.628166, -0.007058, 0.212477},
    {-0.586924, 0.350873, -0.303344, 0.233292, -0.113296, 0.098306, -0.111099},
    {0.061287, -0.478102, 0.204496, -0.017472, 0.132043, -0.140441, 0.145434}};

vector<double> B1 = {0.000000, 0.000000, -14.765937, -13.747047, 18.777617, 0.000000, -17.202961};

// Layer 2: 7 neurons, 7 inputs
vector<vector<double>> W2 = {
{0.254389, 0.158362, 0.490365, -0.526764, 0.470425, 0.063112, 0.357063},
    {0.244586, -0.510264, -0.267326, -0.083909, 0.168870, -0.247511, -0.611998},
    {0.658092, 0.286994, -0.439999, 0.399406, 0.728828, 0.014644, -0.183559},
    {0.533934, 0.822755, -0.571773, 2.210228, 0.593117, -0.008915, -0.598795},
    {-1.840793, -1.395618, -0.600449, -0.255389, -2.011714, -0.085174, -0.633076},
    {0.179051, -0.353016, -0.449507, -0.480846, -0.637871, 0.139154, 0.653757},
    {1.118044, 1.462891, 0.269453, 0.248379, 0.983034, -0.709730, 0.324117}};

vector<double> B2 = {-16.317181, -14.871901, -0.033717, -5.829535, -24.061102, -0.005301, -0.060171};

// Layer 3: 7 neurons, 1 inputs
vector<vector<double>> W3 = {
{4.758509},
    {3.148473},
    {0.724657},
    {0.923789},
    {5.429516},
    {-0.701031},
    {-1.083642}};

vector<double> B3 = {-5.594834};
}

namespace n7 {
// Layer 1: 7 neurons, 4 inputs
vector<vector<double>> W1 = {
{0.000092, 1.430722, -0.000048, -0.002790},
    {0.000065, -0.000086, 0.000014, -0.000032},
    {0.000043, 0.089712, -0.000044, -0.000014},
    {0.000038, 0.002467, 0.000101, -0.000142},
    {0.000113, -0.106766, -0.000013, 0.129162},
    {0.000133, -0.060210, -0.000027, 0.028139},
    {-0.000003, 0.062676, 0.000100, 0.428010}};

vector<double> B1 = {0.185160, 66.622742, -23.504799, -64.511246};

// Layer 2: 4 neurons, 7 inputs
vector<vector<double>> W2 = {
{0.000028, 0.000034, 0.000103, 0.000007, 0.000088, 0.000169, -0.000083},
    {-0.000037, -0.000047, -0.000641, 0.000013, -1.004605, -0.000042, -0.764410},
    {0.000065, -0.000033, -0.000048, 0.000033, -0.000005, -0.000035, -0.000042},
    {0.000019, 0.000096, 0.253471, -0.000001, 0.191693, -0.000613, 0.133345}};

vector<double> B2 = {-10.986033, -14.308620, -53.633167, 1.141278, -64.460526, 8.654234, -67.791237};

// Layer 3: 7 neurons, 1 inputs
vector<vector<double>> W3 = {
{-0.003128},
    {0.005114},
    {1.918622},
    {-0.001892},
    {8.124666},
    {-0.007723},
    {7.783615}};

vector<double> B3 = {-53.304504};
}

double l1[1024], l2[1024];
vector<double> input_features;

double predict(const vector<vector<double>>& W1,
               const vector<double>& B1,
               const vector<vector<double>>& W2,
               const vector<double>& B2,
               const vector<vector<double>>& W3,
               const vector<double>& B3) {
    assert(SZ(W1) == SZ(input_features));
    F0(i, SZ(W1[0])) {
        double s = 0;
        F0(j, SZ(input_features)) s += input_features[j] * W1[j][i];
        l1[i] = max(s + B1[i], 0.0);
    }

    F0(i, SZ(W2[0])) {
        double s = 0;
        F0(j, SZ(W2)) s += l1[j] * W2[j][i];
        l2[i] = max(s + B2[i], 0.0);
    }

    double ret = 0;
    F0(i, SZ(W3)) ret += l2[i] * W3[i][0];

    return ret;
}


inline int SwapCode(int rt1, int p1, int rt2, int p2) {
    return (rt1 << 27) | (rt2 << 24) | (p1 << 12) | p2;
}

pair<pii, pii> Decode(int code) {
    int rt1 = code >> 27;
    int rt2 = (code >> 24) & ((1<<3)-1);
    int p1 = (code >> 12) & ((1<<12) - 1);
    int p2 = code & ((1<<12) - 1);
    return make_pair(pii(rt1, p1), pii(rt2, p2));
}

bool Goes(int p, int k) {
    if (E[p] & 8) return false;
    return (rail_mask[E[p]] & (1<<k));
}

bool GoesTo(int p, int k) {
    if (E[p] & 8) {
        int rt = E[p] ^ 8;
        return (rail_mask[rt] & (1<<k));
    }
    return Goes(p, k);
}

int ChangeDir(int rt, int i1, int i2) {
    if (!(rail_mask[rt] & (1<<i1))) return rt;
    return mask_to_rail[rail_mask[rt] ^ (1<<i1) ^ (1<<i2)];
}

void Prepare() {
    PR(n, m, K, T);
    bscore = K;
    F0(i, LOGN) logs[i] = -log((i+0.5)/LOGN);

    rail_type[LEFT][RIGHT] = rail_type[RIGHT][LEFT] = LEFT_RIGHT;
    rail_type[UP][DOWN] = rail_type[DOWN][UP] = UP_DOWN;
    rail_type[LEFT][DOWN] = rail_type[DOWN][LEFT] = LEFT_DOWN;
    rail_type[LEFT][UP] = rail_type[UP][LEFT] = LEFT_UP;
    rail_type[UP][RIGHT] = rail_type[RIGHT][UP] = UP_RIGHT;
    rail_type[DOWN][RIGHT] = rail_type[RIGHT][DOWN] = DOWN_RIGHT;
    F0(i, 4) F0(j, 4) if (i != j) {
        mask_del[(1<<i) | (1<<j)][i] = j;
        rail_mask[rail_type[i][j]] = (1<<i) | (1<<j);
        mask_to_rail[(1<<i) | (1<<j)] = rail_type[i][j];
    }

    F0(i, n) F0(j, n) {
        X[ID(i, j)] = i;
        Y[ID(i, j)] = j;
        F0(i2, n) F0(j2, n) {
            d1[ID(i, j)][ID(i2, j2)] = abs(i - i2) + abs(j - j2);
        }
        F0(k, 4) {
            pii p = Move(pii(i, j), k);
            if (!In(p)) mv[ID(i, j)][k] = -1;
            else {
                mv[ID(i, j)][k] = ID(p);
                get_dir[ID(i, j)][ID(p)] = k;
            }
        }
    }

    F0(i, n*n) zh[i] = my.zh();
    F0(i, m) F0(e, 2) z[e][i] = my.zh();

    F0(i, m) {
        fare[i] = d1[p[0][i]][p[1][i]];
        sum_fares += fare[i];
        for (int dx = -2; dx <= 2; dx++) {
            for (int dy = -2; dy <= 2; dy++) if (abs(dx) + abs(dy) <= 2) {
                F0(e, 2) {
                    pii t = Move(MP(p[e][i]), pii(dx, dy));
                    if (In(t)) {
                        s[e][i].push_back(ID(t));
                        ins[e][ID(t)].push_back(i);
                    }
                }
            }
        }
    }
}

void UpdateBest(int score) {
    if (score > bscore) {
        bscore = score;
        bsol = sol;
    }
}

bool DFS(int p, int dst) {
    c_o[7]++;
    new_path[0].push_back(p);
    qv[p] = qz;

    char* dirs = pdirs[p][dst];
    if (!pn[p][dst]) {
        if (X[p] < X[dst]) dirs[pn[p][dst]++] = DOWN;
        else if (X[p] > X[dst]) dirs[pn[p][dst]++] = UP;

        if (Y[p] < Y[dst]) dirs[pn[p][dst]++] = RIGHT;
        else if (Y[p] > Y[dst]) dirs[pn[p][dst]++] = LEFT;
        if (pn[p][dst] == 2) {
            int dx = abs(X[p] - X[dst]);
            int dy = abs(Y[p] - Y[dst]);
            if ((dx < dy) ^ (dirs[0] & 1)) swap(dirs[0], dirs[1]);
        }
    }
    F0(index, pn[p][dst]) {
        int k = dirs[index];
        int p2 = mv[p][k];
        if (p2 == dst) {
            return true;
        }
        if (qv[p2] != qz && !E[p2]) {
            if (DFS(p2, dst)) return true;
        }
    }
    new_path[0].pop_back();
    return false;
}

int AUG(int p, int dst, int mask = 0) {
    c_o[8]++;
    int level = __builtin_popcount(mask);
    new_path[level].push_back(p);
    qv[p] = qz;

    char* dirs = pdirs[p][dst];
    if (!pn[p][dst]) {
        if (X[p] < X[dst]) dirs[pn[p][dst]++] = DOWN;
        else if (X[p] > X[dst]) dirs[pn[p][dst]++] = UP;

        if (Y[p] < Y[dst]) dirs[pn[p][dst]++] = RIGHT;
        else if (Y[p] > Y[dst]) dirs[pn[p][dst]++] = LEFT;
        if (pn[p][dst] == 2) {
            int dx = abs(X[p] - X[dst]);
            int dy = abs(Y[p] - Y[dst]);
            if ((dx < dy) ^ (dirs[0] & 1)) swap(dirs[0], dirs[1]);
        }
    }

    F0(index, pn[p][dst]) {
        int k = dirs[index];
        int p2 = mv[p][k];
        if (p2 == dst) return level + 1;
        if (qv[p2] == qz) continue;

        if (!E[p2]) {
            int ret = AUG(p2, dst, mask);
            if (ret) return ret;
        } else if (level < level_threshold) {
            qv[p2] = qz;
            if (resv[p2] == resz && !(resk[p2] & mask)) {
                if (!allow_deep) {
                    int p3 = resp[p2];
                    if (qv[p3] != qz) {
                        int ret = AUG(p3, dst, mask | resk[p2]);
                        if (ret) {
                            prev_path[level + 1].push_back(p3);
                            while (p2 != dst) {
                                new_path[level].push_back(p2);
                                prev_path[level + 1].push_back(p2);
                                p2 = forp[p2];
                            }
                            return ret;
                        }
                    }
                } else {
                    int start_p2 = p2;
                    while (resv[p2] == resz) {
                        int p3 = resp[p2];
                        if (qv[p3] == qz) break;

                        int ret = AUG(p3, dst, mask | resk[p2]);
                        if (ret) {
                            p2 = start_p2;
                            while (p3 != p2) {
                                prev_path[level + 1].push_back(p3);
                                p3 = forp[p3];
                            }
                            while (p2 != dst) {
                                new_path[level].push_back(p2);
                                prev_path[level + 1].push_back(p2);
                                p2 = forp[p2];
                            }
                            return ret;
                        }
                        p2 = p3;
                    }
                }
            }
        }
    }

    new_path[level].pop_back();
    return 0;
}

void Add(int x) {
    c_o[19]++;
    smask[X[x]] ^= (1LL << Y[x]);
    if (!E[x]) {
        hmask[X[x]] ^= (1LL << Y[x]);
        vmask[Y[x]] ^= (1LL << X[x]);
    }
    E[x] ^= 8;
    F0(e, 2) for (int i : ins[e][x]) {
        if (!cnt[e][i]++) {
            current_hash ^= z[e][i];
            half_income += fare[i];
            if (cnt[e^1][i]) {
                half_income -= 2 * fare[i];
                income += fare[i];
            }
        }
    }
}

void Del(int x) {
    E[x] ^= 8;
    smask[X[x]] ^= (1LL << Y[x]);
    if (!E[x]) {
        hmask[X[x]] ^= (1LL << Y[x]);
        vmask[Y[x]] ^= (1LL << X[x]);
    }
    F0(e, 2) for (int i : ins[e][x]) {
        if (!--cnt[e][i]) {
            current_hash ^= z[e][i];
            half_income -= fare[i];
            if (cnt[e^1][i]) {
                half_income += 2 * fare[i];
                income -= fare[i];
            }
        }
    }
}

void NicePrint(vector<string> s) {
    F0(i, n) {
        F0(j, n) if (isdigit(s[i][j])) {
            if (s[i][j] == '0') cerr << "X";
            if (s[i][j] == '1') cerr << "─";
            if (s[i][j] == '2') cerr << "│";
            if (s[i][j] == '3') cerr << "┐";
            if (s[i][j] == '4') cerr << "┘";
            if (s[i][j] == '5') cerr << "└";
            if (s[i][j] == '6') cerr << "┌";
            if (s[i][j] == '7') cerr << "┼";
        }
        else {
            cerr << s[i][j];
        }
        wcerr << endl;
    }
}

void Res(int dst) {
    F0(k, 4) {
        int p = mv[dst][k];
        if (p == -1) continue;
        if (!Goes(p, k^2)) continue;
        forp[p] = dst;

        int k1 = k;
        while (1) {
            resv[p] = resz;
            resk[p] = 1 << k;

            int mask = rail_mask[E[p]];
            int k2 = mask_del[mask][k1^2];
            int p2 = mv[p][k2];
            resp[p] = p2;
            forp[p2] = p;

            if (E[p2]&8) break;
            p = p2;
            k1 = k2;
        }
    }
}

struct State {
    int t;
    int money;
    vector<pii> save_sol;
    vector<int> stations;
    State() { Reset(); }
    void SaveSol() {
        save_sol = sol;
    }
    void RestoreSol() {
        int sz = SZ(sol);
        for (int i = sz; i < SZ(save_sol); i++) {
            auto pp = save_sol[i];
            if (pp.first == -1) Wait(pp.second);
            else if (pp.first == -2) AddSwap(pp.second);
            else if (pp.first == STATION) AddStation(pp.second);
            else AddRail(pp);
        }
    }
    void Reset() {
        current_hash = 0;
        money = K;
        t = 0;
        income = 0;
        half_income = 0;
        F0(i, n) hmask[i] = vmask[i] = smask[i] = 0;
        F0(i, n) F0(j, n) E[ID(i, j)] = 0;
        F0(e, 2) F0(i, m) cnt[e][i] = 0;
        stations.clear();
        sol.clear();
    }
    void AddRail(pii p) {
        c_o[18]++;
        t++;
        money -= RAIL_COST;
        money += income;
        sol.push_back(p);
        E[p.second] = p.first;
        hmask[X[p.second]] ^= (1LL << Y[p.second]);
        vmask[Y[p.second]] ^= (1LL << X[p.second]);
    }

    void RemoveRail(pii p) {
        t--;
        money -= income;
        money += RAIL_COST;
        sol.pop_back();
        E[p.second] = 0;
        hmask[X[p.second]] ^= (1LL << Y[p.second]);
        vmask[Y[p.second]] ^= (1LL << X[p.second]);
    }

    bool AddRails(int delay, int p1, int p2) {
        AT(1);
        int level = FindPath(make_pair(p1, p2));
        if (!level) return false;

        F0(i, level) {
            prev_path[i].push_back(p2);
            new_path[i].push_back(p2);
        }

        Wait(delay);

        while (level > 1) {
            level--;
            vector<int>& rp = prev_path[level];
            vector<int>& np = new_path[level];

            if (E[rp[0]] & 8) {
                int x = E[rp[0]] ^ 8;
                if (x) {
                    int d1 = get_dir[rp[0]][rp[1]];
                    int d2 = get_dir[np[0]][np[1]];
                    swp = SwapCode(x, rp[0], ChangeDir(x, d1, d2), rp[0]);
                    AddSwap(swp);
                }
            } else {
                int d1 = GetDir(rp[0], rp[1]);
                int d2 = GetDir(np[0], np[1]);
                swp = SwapCode(E[rp[0]], rp[0], ChangeDir(E[rp[0]], d1, d2), rp[0]);
                AddSwap(swp);
            }
            F1(i, SZ(rp) - 2) {
                int d1 = GetDir(np[i], np[i - 1]);
                int d2 = GetDir(np[i], np[i + 1]);
                swp = SwapCode(E[rp[i]], rp[i], rail_type[d1][d2], np[i]);
                AddSwap(swp);
            }

            if (E[rp.back()] & 8) {
                int x = E[rp.back()] ^ 8;
                if (x) {
                    int d1 = GetDir(rp.back(), rp[SZ(rp) - 2]);
                    int d2 = GetDir(np.back(), np[SZ(np) - 2]);
                    swp = SwapCode(x, rp.back(), ChangeDir(x, d1, d2), rp.back());
                    AddSwap(swp);
                }
            } else {
                int d1 = GetDir(rp.back(), rp[SZ(rp) - 2]);
                int d2 = GetDir(np.back(), np[SZ(np) - 2]);
                swp = SwapCode(E[rp.back()], rp.back(), ChangeDir(E[rp.back()], d1, d2), rp.back());
                AddSwap(swp);
            }
        }

        vector<int>& rp = new_path[0];

        F1(i, SZ(rp) - 2) {
            int d1 = GetDir(rp[i], rp[i - 1]);
            int d2 = GetDir(rp[i], rp[i + 1]);
            AddRail(pii(rail_type[d1][d2], rp[i]));
        }
        return true;
    }

    void AddStation(int p) {
        t += 1;
        stations.push_back(p);
        money -= STATION_COST;
        sol.push_back(pii(0, p));
        Add(p);
        money += income;
    }

    void AddSwap(int code) {
        sol.push_back(pii(-2, code));
        int rt1 = code >> 27;
        int rt2 = (code >> 24) & ((1<<3)-1);
        int p1 = (code >> 12) & ((1<<12) - 1);
        int p2 = code & ((1<<12) - 1);
        E[p1] ^= rt1;
        E[p2] ^= rt2;
        if (!(E[p1] & 8)) {
            hmask[X[p1]] ^= (1LL << Y[p1]);
            vmask[Y[p1]] ^= (1LL << X[p1]);
        }
        if (!(E[p2] & 8)) {
            hmask[X[p2]] ^= (1LL << Y[p2]);
            vmask[Y[p2]] ^= (1LL << X[p2]);
        }
    }

    void DelSwap(int code) {
        sol.pop_back();
        int rt2 = code >> 27;
        int rt1 = (code >> 24) & ((1<<3)-1);
        int p2 = (code >> 12) & ((1<<12) - 1);
        int p1 = code & ((1<<12) - 1);
        E[p1] ^= rt1;
        E[p2] ^= rt2;
        if (!(E[p1] & 8)) {
            hmask[X[p1]] ^= (1LL << Y[p1]);
            vmask[Y[p1]] ^= (1LL << X[p1]);
        }
        if (!(E[p2] & 8)) {
            hmask[X[p2]] ^= (1LL << Y[p2]);
            vmask[Y[p2]] ^= (1LL << X[p2]);
        }
    }

    void RemoveStation(int p) {
        t -= 1;
        stations.pop_back();
        money -= income;
        money += STATION_COST;
        sol.pop_back();
        Del(p);
    }

    int GetDelay(int rc) {
        int delay = 0;
        if (money + rc * income < rc * RAIL_COST + STATION_COST) {
            int need = rc * RAIL_COST + STATION_COST - rc * income - money;
            delay = (need + income - 1) / income;
        }
        return delay;
    }

    int Final() {
        if (t > T) return 0;
        return money + (T - t) * income;
    }

    void Wait(int delay) {
        if (!delay) return;
        t += delay;
        money += income * delay;
        sol.push_back(pii(-1, delay));
    }

    void UnWait(int delay) {
        t -= delay;
        money -= income * delay;
        sol.pop_back();
    }

    int FindPath(pii pp) {
        int src = pp.first;
        int dst = pp.second;
        F0(k, 4) {
            prev_path[k].clear();
            new_path[k].clear();
        }

        int works = 0;

        qz++;
        works = DFS(src, dst);
        if (works) {
            return works;
        }

        resz++;
        Res(dst);

        qz++;
        level_threshold = 1; // can be 2 or 3
        allow_deep = 0; // can be 1

        works = AUG(src, dst);

        return works;

        if (works) {
            Print(pp);
            F0(k, works) {
                if (!prev_path[k].empty()) {
                    PR(k, prev_path[k]);
                }
                if (!new_path[k].empty()) {
                    PR(k, new_path[k]);
                }
            }
        }
        return 0;
    }

    void Print(pii pp = no) {
        vector<string> s(n, string(n, '.'));
        F0(i, n) F0(j, n) {
            int c = E[ID(i, j)];
            if (c & 8) s[i][j] = '0';
            else if (c) s[i][j] = '0' + c;
        }
        if (pp != no) {
            pii p = MP(pp.first);
            s[p.first][p.second] = 'A';
            p = MP(pp.second);
            s[p.first][p.second] = 'B';
        }
        NicePrint(s);
        cerr << endl;
    }

    void Update() {
        UpdateBest(Final());
    }
};

State b;
int wrp[4], w0;

void Get(int k1) {
    c_o[14]++;
    if (k1 == UP) {
        int x = X[w0];
        ll y = vmask[Y[w0]] & ((1LL << x) - 1);
        wrp[k1] = (y == 0) ? -1
                           : ID(63 - __builtin_clzll(y), Y[w0]);
    }
    else if (k1 == DOWN) {
        int x = X[w0];;
        ll y = vmask[Y[w0]] & ~((1LL << (x + 1)) - 1);
        wrp[k1] = (y == 0) ? -1
                           : ID(__builtin_ctzll(y), Y[w0]);
    }
    else if (k1 == LEFT) {
        int x = Y[w0];
        ll y = hmask[X[w0]] & ((1LL << x) - 1);
        wrp[k1] = (y == 0) ? -1
                           : ID(X[w0], 63 - __builtin_clzll(y));
    } else {
        int x = Y[w0];
        ll y = hmask[X[w0]] & ~((1LL << (x + 1)) - 1);
        wrp[k1] = (y == 0) ? -1
                           : ID(X[w0], __builtin_ctzll(y));
    }
}

bool CanWarpDir(int k1) {
    int k2 = (k1 + 1) & 3;

    int p1 = wrp[k1];
    if (p1 == w0) { Get(k1); p1 = wrp[k1]; }
    if (p1 == -1 || !GoesTo(p1, k2)) return false;

    int p2 = wrp[k2];
    if (p2 == w0) { Get(k2); p2 = wrp[k2]; }
    if (p2 == -1 || !GoesTo(p2, k1)) return false;

    int step = 0;
    while (p1 != p2) {
        ++step;
        if (step == 1) p1 = mv[p1][k2];
        else if (Goes(p1, k2)) {
            if (k2 & 1) {
                if (Y[p1] == Y[p2]) return false;
            } else {
                if (X[p1] == X[p2]) return false;
            }
            p1 = mv[p1][k2];
        }
        else if (Goes(p1, k1^2)) p1 = mv[p1][k1^2];
        else return false;
    }

    s_type = k1;
    return true;
}

void AddWarpDir(int p, int k1) {
    c_o[13]++;
    int k2 = (k1 + 1) & 3;
    wrp[k1] = wrp[k2] = w0 = p;
    Get(k1); Get(k2);
    int p1 = wrp[k1], p2 = wrp[k2];
    int p3 = p1;

    rp.clear();
    rp.push_back(p1);

    int step = 0;
    while (p1 != p2) {
        step++;
        if (step == 1) p1 = mv[p1][k2];
        else if (Goes(p1, k2)) p1 = mv[p1][k2];
        else p1 = mv[p1][k1^2];

        rp.push_back(p1);
    }

    if (E[rp[0]] & 8) {
        int x = E[rp[0]] ^ 8;
        if (x) {
            swp = SwapCode(x, rp[0], ChangeDir(x, k2, k1^2), rp[0]);
            b.AddSwap(swp);
        }
    } else {
        swp = SwapCode(E[rp[0]], rp[0], ChangeDir(E[rp[0]], k2, k1^2), rp[0]);
        b.AddSwap(swp);
    }

    int rt = rail_type[k1][k1^2];
    F1(i, SZ(rp) - 2) {
        bool eq = (k2&1) ? (p3 / n != p2 / n) : (p3 % n != p2 % n);
        if (eq) {
            p3 = mv[p3][k1^2];
            if (k2&1) {
                if (p3 / n == p2 / n) rt = rail_type[k1][k2];
            } else {
                if (p3 % n == p2 % n) rt = rail_type[k1][k2];
            }
        } else {
            p3 = mv[p3][k2];
            rt = rail_type[k2^2][k2];
        }

        swp = SwapCode(E[rp[i]], rp[i], rt, p3);
        b.AddSwap(swp);
    }

    if (E[rp.back()] & 8) {
        int x = E[rp.back()] ^ 8;
        if (x) {
            swp = SwapCode(x, rp.back(), ChangeDir(x, k1, k2^2), rp.back());
            b.AddSwap(swp);
        }
    } else {
        swp = SwapCode(E[rp.back()], rp.back(), ChangeDir(E[rp.back()], k1, k2^2), rp.back());
        b.AddSwap(swp);
    }
}

int CanWarp(int p) {
    AT(2);
    w0 = p;
    F0(dir, 4) wrp[dir] = p;

    F0(dir, 4) {
        if (CanWarpDir(dir)) return 1;
    }

    return 0;
}

vector<vector<int>> dp[800];
vector<vector<char>> way[800];

void PrintSol(bool improve = false) {
    //for (auto x : best_sols) PR(x.first);
    //bsol = best_sols.begin()->second;

    int lastT = 0, curT = 0;
    set<pii> translate;
    for (pii p : bsol) {
        if (p.first == -2) {
            auto mp = Decode(p.second);
            translate.insert(mp.first);
        }
        else if (p.first == -1) lastT += p.second;
        else lastT += 1;
    }

    if (lastT < T) {
        bsol.push_back(pii(-1, T - lastT));
    }
    int income = 0;
    int rail_used = 0;
    set<int> stations;
    vector<int> incomes;
    set<int> done;
    vector<int> contrs;
    int contr = 0;
    int est = 0;

    pii current_stage(0, 0);
    vector<pii> stages;

    vector<pii> r_order, s_order;
    F0(index, SZ(bsol)) {
        pii p = bsol[index];
        if (p.first == -2) continue;
        if (p.first != -1) {
            curT++;
            if (p.first == STATION) {
                incomes.clear();
                stations.insert(p.second);
                F0(i, m) if (!done.count(i)) {
                    int cnt = 0;
                    for (int p : s[0][i]) if (stations.count(p)) { cnt++; break; }
                    for (int p : s[1][i]) if (stations.count(p)) { cnt++; break; }
                    if (cnt == 2) {
                        incomes.push_back(fare[i]);
                        done.insert(i);
                        income += fare[i];
                        contr += (T - curT) * fare[i];
                    }
                }
                current_stage.second = income;
                if (index != 0) stages.push_back(current_stage);
                current_stage = pii(0, 0);
                contrs.push_back(contr - STATION_COST);
                contr = 0;
                s_order.push_back(p);
            } else {
                contr -= RAIL_COST;
                current_stage.first++;
                if (translate.count(p)) {
                    int tr = 0;
                    for (int j = index + 1; j < SZ(bsol); j++) if (bsol[j].first == -2) {
                        auto mp = Decode(bsol[j].second);
                        if (p == mp.first) {
                            tr++;
                            p = mp.second;
                        }
                    }
                    //cout << "# transitions: " << tr << endl;
                }
                rail_used++;
                r_order.push_back(p);
            }
            if (improve) continue;
            cout << "# " << curT << "/" << lastT << " " << income << "/" << sum_fares << " " << SZ(stations) << "," << rail_used << " " << incomes << endl;
            est += income;
            cout << "# " << est + K - (rail_used * RAIL_COST) - (SZ(stations) * STATION_COST) + (T - curT) * income << endl;
            cout << p.first << " " << p.second / n << " " << p.second % n << endl;
        } else {
            if (improve) continue;
            F0(x, p.second) {
                est += income;
                curT++;
                if (x == p.second - 1 && p == bsol.back()) {
                    contrs.erase(contrs.begin());
                    int sc = accumulate(contrs.begin(), contrs.end(), 0);
                    vector<int> c;
                    for (int contr : contrs) c.push_back(100LL * SZ(contrs) * contr / sc);
                    cout << "# " << curT << "/" << lastT << " " << income << "/" << sum_fares << " " << SZ(stations) << "," << rail_used << " " << incomes << endl;
                    cout << "#" << c << endl;
                    //F0(i, SZ(c)) PR(i + 2, c[i]);
                    //PR(c);
                } else {
                    cout << "# " << curT << "/" << lastT << " " << income << "/" << sum_fares << " " << SZ(stations) << "," << rail_used << " " << incomes << endl;
                    cout << "# " << est + K - (rail_used * RAIL_COST) - (SZ(stations) * STATION_COST) + (T - curT) * income << endl;
                }
                cout << "-1" << endl;
            }
        }
    }
    if (!improve) return;

    //PR(stages);
    int sz = SZ(stages);
    int mx = 0;
    for (pii p : stages) mx += p.first;


    vector<int> suff(sz + 1);
    suff[sz] = 0;
    for (int i = sz - 1; i >= 0; i--) suff[i] = suff[i + 1] + stages[i].first;
    //PR(suff);

    double dp_start = Elapsed();

    int sets_size = 0;

    F0(t, T) {
        dp[t].resize(sz + 1);
        way[t].resize(sz + 1);
        F0(i, sz + 1) {
            dp[t][i].assign(suff[i] + 1, -1);
            way[t][i].resize(suff[i] + 1);
            sets_size += (suff[i] + 1);
        }
    }

    dp[0][0][0] = K - STATION_COST;
    int states_passed = 0;

    F0(t, T - 1) F0(i, sz + 1) F0(j, suff[i] + 1) if (dp[t][i][j] != -1) {
        states_passed++;
        auto upd = [&](int i2, int j2, int b) {
            int& a = dp[t + 1][i2][j2];
            if (b > a) {
                a = b;
                if (i == i2 && j == j2) way[t + 1][i2][j2] = 1;
                else if (i2 > i) way[t + 1][i2][j2] = 2;
                else way[t + 1][i2][j2] = 3;
            }
        };
        if (dp[t][i][j] >= STATION_COST && i < sz && stages[i].first <= j) upd(i + 1, j - stages[i].first, dp[t][i][j] - STATION_COST + stages[i].second);
        else {
            // TODO: j < mx <-> j < stages[i].first
            if (improve) {
                if (dp[t][i][j] >= RAIL_COST && i < sz && j < suff[i]) upd(i, j + 1, dp[t][i][j] - RAIL_COST + (i == 0 ? 0 : stages[i - 1].second));
            } else {
                if (dp[t][i][j] >= RAIL_COST && i < sz && j < stages[i].first) upd(i, j + 1, dp[t][i][j] - RAIL_COST + (i == 0 ? 0 : stages[i - 1].second));
            }
            if (i > 0) upd(i, j, dp[t][i][j] + stages[i - 1].second);
        }
    }

    vector<pii> rev_ans;
    int t = T - 1, i = sz, j = 0;
    while (t > 0) {
        char w = way[t][i][j];
        if (w == 1) { rev_ans.push_back(no); }
        else if (w == 2) { rev_ans.push_back(s_order.back()); s_order.pop_back(); i--; j += stages[i].first; }
        else { rev_ans.push_back(r_order.back()); r_order.pop_back(); j--; }
        t--;
    }
    rev_ans.push_back(s_order.back());
    double dp_time = Elapsed() - dp_start;
    PR(states_passed, sets_size, dp_time, T * mx * sz, dp[T - 1][sz][0]);
    reverse(rev_ans.begin(), rev_ans.end());
    for (pii p : rev_ans) {
        if (p == no) cout << "-1" << endl;
        else cout << p.first << " " << p.second / n << " " << p.second % n << endl;
    }
}

void PrepNewStation(int new_station) {
    bv = inf;
    if (E[new_station]) {
        bv = 0;
        s_type = S_PLACE;
    } else if (CanWarp(new_station)) {
        bv = 0;
    } else {
        AT(3);
        s_type = S_CONNECT;
        if (SZ(b.stations) < 24) {
            c_o[6] += SZ(b.stations);
            for (int s : b.stations) {
                int av = d1[s][new_station] - 1;
                if (av < bv) {
                    old_station = s;
                    bv = av;
                }
            }
        } else {
            int x = X[new_station], y = Y[new_station];
            ll mask = smask[x] & ~((1LL << (y + 1)) - 1);
            if (mask) {
                int y2 = __builtin_ctzll(mask);
                int av = y2 - y;
                if (av < bv) { bv = av; old_station = ID(x, y2); }
            }
            mask = smask[x] & ((1LL << y) - 1);
            if (mask) {
                int y2 = 63 - __builtin_clzll(mask);
                int av = y - y2;
                if (av < bv) { bv = av; old_station = ID(x, y2); }
            }
            for (int dx = 1; dx < bv && dx <= x; dx++) {
                mask = smask[x - dx] & ~((1LL << (y)) - 1);
                if (mask) {
                    int y2 = __builtin_ctzll(mask);
                    int av = y2 - y + dx;
                    if (av < bv) { bv = av; old_station = ID(x - dx, y2); }
                }
                mask = smask[x - dx] & ((1LL << y) - 1);
                if (mask) {
                    int y2 = 63 - __builtin_clzll(mask);
                    int av = y - y2 + dx;
                    if (av < bv) { bv = av; old_station = ID(x - dx, y2); }
                }
            }
            for (int dx = 1; dx < bv && x + dx < n; dx++) {
                mask = smask[x + dx] & ~((1LL << (y)) - 1);
                if (mask) {
                    int y2 = __builtin_ctzll(mask);
                    int av = y2 - y + dx;
                    if (av < bv) { bv = av; old_station = ID(x + dx, y2); }
                }
                mask = smask[x + dx] & ((1LL << y) - 1);
                if (mask) {
                    int y2 = 63 - __builtin_clzll(mask);
                    int av = y - y2 + dx;
                    if (av < bv) { bv = av; old_station = ID(x + dx, y2); }
                }
            }
            bv--;
        }
    }
    delay = b.GetDelay(bv);
    new_t = b.t + delay + bv + 1;
}

bool AddNewStation(int new_station) {
    if (s_type == S_CONNECT) {
        bool f = false;
        f = b.AddRails(delay, new_station, old_station);
        if (!f) return false;
    } else {
        if (s_type != S_PLACE) AddWarpDir(new_station, s_type);
        b.Wait(delay);
    }

    b.AddStation(new_station);
    b.Update();

    return true;
}

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

// Diff (Stateless) Beam Search
const int MSTEPS = 896;
const int MW = 1 << 14;
typedef int MoveType;
typedef double EvalType;
typedef ll HashType;
struct TreeState {
    int prev;
    MoveType last_move;
};
// eval, new state
typedef pair<EvalType, TreeState> DeltaType;
multiset<EvalType> best_evals;
vector<DeltaType> deltas;
int bn[MSTEPS];
TreeState beam[MSTEPS][MW];
gp_hash_table<HashType, DeltaType> all_hashes;
//unordered_map<HashType, EvalType> all_hashes;
int at_stack[MSTEPS], last_step;
MoveType lm_stack[MSTEPS];
int BW[MSTEPS];
set<int> S;

void InitBeam() {
    b.Reset();
    //all_hashes.reserve(1 << 21);

    for (int i = 0; i < MSTEPS; i++) bn[i] = 0;
    deltas.clear();
    last_step = 0;
    at_stack[0] = 0;

    beam[0][bn[0]++] = {-1, MoveType()};
}

void RevertMove() {
    AT(4);

    while (!sol.empty()) {
        auto pp = sol.back();
        if (pp.first == -1) b.UnWait(pp.second);
        else if (pp.first == -2) b.DelSwap(pp.second);
        else if (pp.first == STATION) b.RemoveStation(pp.second);
        else b.RemoveRail(pp);

        if (SZ(sol) > 1 && sol.back().first == STATION) break;
    }
}

void MakeMove(int step, const MoveType& lm) {
    lm_stack[step] = lm;

    s_type = lm >> 24;
    int new_station((lm >> 12) & U);

    if (s_type == S_FIRST) {
        int old_station = lm & U;
        b.AddStation(old_station);
        b.AddRails(0, new_station, old_station);
    } else {
        if (s_type == S_CONNECT) {
            int old_station = lm & U;
            int bv = d1[new_station][old_station] - 1;
            int delay = b.GetDelay(bv);
            b.AddRails(delay, new_station, old_station);
        } else if (s_type == S_PLACE) {
            b.Wait(b.GetDelay(0));
        } else {
            AddWarpDir(new_station, s_type);
            b.Wait(b.GetDelay(0));
        }
    }
    b.AddStation(new_station);
}

void Reach(int step, int at) {
    if (last_step > step) {
        RevertMove();
        last_step--;
    }
    if (step == last_step && at_stack[step] == at) return;
    Reach(step - 1, beam[step][at].prev);
    MakeMove(step, beam[step][at].last_move);
    at_stack[step] = at;
    last_step++;
}

void Bimsa() {
    InitBeam();

    F0(step, MSTEPS) BW[step] = 1;

    F1(i, 16) BW[i] = 4 * 128 / (3 * i + 1);

    F0(step, MSTEPS) {
        BW[step] = BW[step] * 1600 * 2 / m;
    }

    for (int step = 0; step < MSTEPS - 1; step++) {
        all_hashes.clear();
        best_evals.clear();

        if (step >= bscore) return;
        if (step > 0) {
            int sz = SZ(deltas);
            if (sz > BW[step]) {
                nth_element(deltas.begin(), deltas.begin() + BW[step], deltas.end(),
                    [&](const DeltaType& d1, const DeltaType& d2) {
                        return d1.first > d2.first;
                    }
                );
                sz = BW[step];
            }
            for (int index = 0; index < sz; index++) {
                beam[step][bn[step]++] = deltas[index].second;
            }
            sort(beam[step], beam[step] + bn[step],
                 [&](const TreeState& t1, const TreeState& t2) {
                    return t1.prev > t2.prev;
                 }
            );
            deltas.clear();
        }

        if (!bn[step]) break;

        F0(bi, bn[step]) {
            Reach(step, bi);

            if (step == 0) {
                S.clear();
                F0(first, m) for (int old_station : s[0][first]) for (int new_station : s[1][first]) {
                    int bv = d1[old_station][new_station] - 1;
                    if (b.money < bv * RAIL_COST + 2 * STATION_COST) continue;
                    int i0 = old_station, i1 = new_station;
                    if (i0 > i1) swap(i0, i1);

                    if (S.count((i0 << 12) | i1)) continue;
                    S.insert((i0 << 12) | i1);

                    Add(old_station);
                    Add(new_station);
                    EvalType new_eval = b.money - (bv * RAIL_COST + 2 * STATION_COST);
                    new_eval += (income * (T - (bv + 2) + 1));
                    HashType new_hash = current_hash;
                    Del(old_station);
                    Del(new_station);
                    if (SZ(best_evals) >= BW[step + 1] && *best_evals.begin() >= new_eval) {
                        continue;
                    }
                    if (all_hashes.find(new_hash) != all_hashes.end() && all_hashes[new_hash].first >= new_eval) {
                        continue;
                    }

                    b.AddStation(old_station);
                    b.AddRails(0, old_station, new_station);
                    b.AddStation(new_station);

                    b.Update();

                    s_type = S_FIRST;
                    MoveType lm = (s_type << 24)
                                | (new_station << 12)
                                | (old_station);

                    if (all_hashes.find(new_hash) != all_hashes.end()) {
                        if (best_evals.count(all_hashes[new_hash].first)) {
                            best_evals.erase(best_evals.find(all_hashes[new_hash].first));
                        }
                    }
                    all_hashes[new_hash] = {new_eval, {bi, lm}};
                    if (SZ(best_evals) == BW[step + 1]) {
                        best_evals.erase(best_evals.begin());
                    }
                    best_evals.insert(new_eval);

                    RevertMove();
                }
            } else {
                S.clear();
                // pairs that add income (one end inside station)
                if (step > 64) {
                    F0(i, m) if ((!cnt[0][i]) ^ (!cnt[1][i])) {
                        F0(e, 2) if (!cnt[e][i]) for (int w : s[e][i]) S.insert(w);
                    }
                    F0(i, m) if ((!cnt[0][i]) && (!cnt[1][i])) {
                        F0(e, 2) if (!cnt[e][i]) for (int w : s[e][i]) if (E[w]) S.insert(w);
                    }
                } else {
                    for (int station : b.stations) F0(ins_index, 2) {
                        if (ins[ins_index][station].empty()) continue;
                        for (int i : ins[ins_index][station]) {
                            if (cnt[0][i] && cnt[1][i]) continue;
                            vector<int>& cand = cnt[1][i] ? s[0][i] : s[1][i];
                            for (int p : cand) {
                                S.insert(p);
                            }
                        }
                    }
                }

                if (S.empty() && income != sum_fares) {
                    F0(i, m) if (!cnt[0][i] && !cnt[1][i]) {
                        F0(e, 2) for (int w : s[e][i]) S.insert(w);
                    }
                }

                if (step > 30) HALF = 2.0;
                else if (step >= 5) HALF = 8 - step * 0.2;
                else HALF = 16;

                for (int new_station : S) {
                    PrepNewStation(new_station);

                    if (new_t > T) break;

                    EvalType new_eval = b.money + (delay + bv) * income - (bv * RAIL_COST + STATION_COST);

                    Add(new_station);

                    if (step == 1) {
                        input_features =   {1.0*K,
                                            1.0*m,
                                            1.0*new_t,
                                            1.0*new_eval + income,
                                            1.0*(T - new_t) * income,
                                            1.0*(T - new_t) * half_income,
                                            1.0*(T - new_t) * (sum_fares - income - half_income)};
                        new_eval = predict(n1::W1, n1::B1, n1::W2, n1::B2, n1::W3, n1::B3);
                    } else if (step == 2) {
                        input_features =   {1.0*K,
                                            1.0*m,
                                            1.0*new_t,
                                            1.0*new_eval + income,
                                            1.0*(T - new_t) * income,
                                            1.0*(T - new_t) * half_income,
                                            1.0*(T - new_t) * (sum_fares - income - half_income)};
                        new_eval = predict(n2::W1, n2::B1, n2::W2, n2::B2, n2::W3, n2::B3);
                    } else if (step == 3) {
                        input_features =   {1.0*K,
                                            1.0*m,
                                            1.0*new_t,
                                            1.0*new_eval + income,
                                            1.0*(T - new_t) * income,
                                            1.0*(T - new_t) * half_income,
                                            1.0*(T - new_t) * (sum_fares - income - half_income)};
                        new_eval = predict(n3::W1, n3::B1, n3::W2, n3::B2, n3::W3, n3::B3);
                    } else if (step == 4) {
                        input_features =   {1.0*K,
                                            1.0*m,
                                            1.0*new_t,
                                            1.0*new_eval + income,
                                            1.0*(T - new_t) * income,
                                            1.0*(T - new_t) * half_income,
                                            1.0*(T - new_t) * (sum_fares - income - half_income)};
                        new_eval = predict(n4::W1, n4::B1, n4::W2, n4::B2, n4::W3, n4::B3);
                    } else if (step == 5) {
                        input_features =   {1.0*K,
                                            1.0*m,
                                            1.0*new_t,
                                            1.0*new_eval + income,
                                            1.0*(T - new_t) * income,
                                            1.0*(T - new_t) * half_income,
                                            1.0*(T - new_t) * (sum_fares - income - half_income)};
                        new_eval = predict(n5::W1, n5::B1, n5::W2, n5::B2, n5::W3, n5::B3);
                    } else if (step == 6) {
                        input_features =   {1.0*K,
                                            1.0*m,
                                            1.0*new_t,
                                            1.0*new_eval + income,
                                            1.0*(T - new_t) * income,
                                            1.0*(T - new_t) * half_income,
                                            1.0*(T - new_t) * (sum_fares - income - half_income)};
                        new_eval = predict(n6::W1, n6::B1, n6::W2, n6::B2, n6::W3, n6::B3);
                    } else if (step == 73493) {
                        input_features =   {1.0*K,
                                            1.0*m,
                                            1.0*new_t,
                                            1.0*new_eval + income,
                                            1.0*(T - new_t) * income,
                                            1.0*(T - new_t) * half_income,
                                            1.0*(T - new_t) * (sum_fares - income - half_income)};
                        new_eval = predict(n7::W1, n7::B1, n7::W2, n7::B2, n7::W3, n7::B3);
                    } else if (step == 85454) {
                        input_features =   {1.0*K,
                                            1.0*m,
                                            1.0*new_t,
                                            1.0*new_eval + income,
                                            1.0*(T - new_t) * income,
                                            1.0*(T - new_t) * half_income,
                                            1.0*(T - new_t) * (sum_fares - income - half_income)};
                        new_eval = predict(n8::W1, n8::B1, n8::W2, n8::B2, n8::W3, n8::B3);
                    } else {
                        new_eval += (income * (T - new_t + 1)) + (T - new_t) * (income + half_income) / HALF;
                    }


                    HashType new_hash = current_hash;
                    if (step <= 2) {
                        new_hash = zh[new_station];
                        for (int station : b.stations) new_hash ^= zh[station];
                    }
                    Del(new_station);
                    if (SZ(best_evals) >= BW[step + 1] && *best_evals.begin() > new_eval) {
                        continue;
                    }
                    if (all_hashes.find(new_hash) != all_hashes.end() && all_hashes[new_hash].first > new_eval) {
                        continue;
                    }

                    if (!AddNewStation(new_station)) continue;

                    MoveType lm = (s_type << 24)
                                | (new_station << 12)
                                | (old_station);

                    if (all_hashes.find(new_hash) != all_hashes.end()) {
                        if (best_evals.count(all_hashes[new_hash].first)) {
                            best_evals.erase(best_evals.find(all_hashes[new_hash].first));
                        }
                    }
                    all_hashes[new_hash] = {new_eval, {bi, lm}};
                    if (SZ(best_evals) == BW[step + 1]) {
                        best_evals.erase(best_evals.begin());
                    }
                    best_evals.insert(new_eval);

                    RevertMove();
                }
            }
        }
        for (auto x : all_hashes) if (x.second.first >= *best_evals.begin()) {
            deltas.push_back(x.second);
        }
        //Report();
    }
}

bool Skip(int new_station) {
    if (E[new_station] & 8) return true;
    int old_income = income, old_half_income = half_income;
    Add(new_station);
    int skip = (old_income == income && old_half_income == half_income);
    Del(new_station);
    return skip;
}

void Shuffle() {
    b.Reset();
    vector<int> o, new_o;
    for (pii p : bsol) if (p.first == STATION) {
        o.push_back(p.second);
    }
    b.AddStation(o[0]);

    int sz = 0, e = 0;
    int mx_score = 0, mx_new_size = 0;
    for (int i = 1; i < SZ(o); i++) {
        int new_station = o[i];
        PrepNewStation(new_station);
        AddNewStation(o[i]);
        if (b.Final() > mx_score) {
            mx_score = b.Final();
            mx_new_size = i + 1;
        }
    }
    sz = mx_new_size;
    while (SZ(o) > sz) {
        o.pop_back();
        RevertMove();
    }
    score = bscore;
    b.SaveSol();

    int tot = 1, acc = 0;
    double T2 = 0.00035 * score * sqrt(50.0 * 1600.0) / m * (4500.0 / (K - 9500)), T1 = 0.0 * T2, TEMP = 0.0, r = 0.0;
    int itc = 1000000;
#define TIME_BASED
#ifdef TIME_BASED
    double startTime = Elapsed();
    double endTime = TL; itc = 1000000000;
#endif
    F0(iter, itc) {
        if ((iter & 7) == 0) {
            r = (endTime - Elapsed()) / (endTime - startTime);
            if (r <= 0) {
                //PR(iter);
                break;
            }
            TEMP = T1 + (T2 - T1) * r;
            //TEMP = pow(T1, 1-r) * pow(T2, r);
        }

        if (sz < 3) return;
        int keep_i = my.nextInt(2, sz - 1);

        if ((sz - keep_i) > r * sz) keep_i = my.nextInt(2, sz - 1);

        for (int i = sz - 1; i >= keep_i; i--) RevertMove();

        int rng = my.nextInt(16);
        int tp = 0;
        if (rng < 1) tp = 0;
        else if (rng < 1 + 8) tp = 2;
        else tp = 1;

        new_o.clear();

        double maxd = TEMP * logs[my.nextInt(LOGN)];

        mx_score = b.Final();
        mx_new_size = 0;

        if (tp == 1) {
            int fail = 0;

            int i = -1;

            if (keep_i != sz && my.nextInt(4)) {
                ci.clear();
                F0(e, 2) {
                    for (int i : ins[e][o[keep_i]]) {
                        if (!cnt[0][i] || !cnt[1][i]) ci.push_back(i);
                    }
                }
                i = REL(ci);
            }

            if (i == -1) {
                i = my.nextInt(m);
                int its = 0;
                while (cnt[0][i] && cnt[1][i]) {
                    c_o[5]++;
                    i = my.nextInt(m);
                    if (++its > m) {
                        fail = 1;
                        break;
                    }
                }
            }

            if (!fail) {
                e = my.nextInt(2);
                if (cnt[e][i]) e ^= 1;

                RS(s[e][i]);

                int new_station = s[e][i][0];
                for (int p : s[e][i]) {
                    Add(p);
                    s_eval[p] = income * 4 + half_income;
                    Del(p);
                }

                PrepNewStation(new_station);

                if (s_type == S_CONNECT && bv != 0) {
                    int better_found = 0;
                    for (int p : s[e][i]) if (E[p] && s_eval[p] >= s_eval[new_station]) {
                        new_station = p;
                        better_found = 1;
                    }

                    if (!better_found) {
                        for (int p : s[e][i]) if (s_eval[p] >= s_eval[new_station] && d1[p][old_station] < d1[new_station][old_station]) {
                            better_found = 1;
                            new_station = p;
                        }
                    }
                    if (better_found) PrepNewStation(new_station);
                }

                if (!AddNewStation(new_station)) fail = 1; else {
                    new_o.push_back(new_station);
                    if (b.Final() > mx_score) {
                        mx_score = b.Final();
                        mx_new_size = SZ(new_o);
                    }
                }
            }

            if (!fail && !cnt[e^1][i]) {
                int new_station = REL(s[e^1][i]);
                if (E[new_station]) {
                    PrepNewStation(new_station);
                    if (AddNewStation(new_station)) {
                        new_o.push_back(new_station);
                        if (b.Final() > mx_score) {
                            mx_score = b.Final();
                            mx_new_size = SZ(new_o);
                        }
                    }
                }
            }

            if (!fail) {
                //maxd *= 2;
                for (int i = keep_i; i < sz; i++) {
                    int new_station = o[i];
                    if (Skip(new_station)) continue;

                    PrepNewStation(new_station);
                    if (!AddNewStation(new_station)) {
                        continue;
                    }
                    new_o.push_back(new_station);
                    if (b.Final() > mx_score) {
                        mx_score = b.Final();
                        mx_new_size = SZ(new_o);
                    }
                }
            } else {
                tp = 2;
            }
        }

        if (keep_i >= sz - 1) tp = 0;

        if (tp == 0) {
            // skip move
            for (int i = keep_i + 1; i < sz; i++) {
                // (i == keep_i) continue;
                int new_station = o[i];
                if (Skip(new_station)) continue;

                PrepNewStation(new_station);
                if (!AddNewStation(new_station)) {
                    continue;
                }
                new_o.push_back(new_station);
                if (b.Final() > mx_score) {
                    mx_score = b.Final();
                    mx_new_size = SZ(new_o);
                }
            }
        }

        if (tp == 2) {
            // swap two
            for (int i = keep_i; i < sz; i++) {
                // (i == keep_i) continue;
                int new_station = o[i];
                if (i == keep_i) new_station = o[i + 1];
                else if (i == keep_i + 1) new_station = o[i - 1];
                if (Skip(new_station)) continue;

                PrepNewStation(new_station);
                if (!AddNewStation(new_station)) {
                    continue;
                }
                new_o.push_back(new_station);
                if (b.Final() > mx_score) {
                    mx_score = b.Final();
                    mx_new_size = SZ(new_o);
                }
            }
        }

        while (SZ(new_o) > mx_new_size) {
            new_o.pop_back();
            RevertMove();
        }

        if (mx_score < score) tot++;
        if (mx_score >= score || mx_score >= score - maxd) {
            c_o[tp]++;
            if (mx_score < score) acc++;
            //if (mx_score > score) PR(x, tp, keep_i, sz, mx_score - score);
            o.resize(keep_i);
            score = mx_score;
            for (int p : new_o) o.push_back(p);
            sz = SZ(o);
            b.SaveSol();
        } else {
            while (!new_o.empty()) {
                new_o.pop_back();
                RevertMove();
            }
            b.RestoreSol();
        }
    }
    cerr << acc << "/" << tot << " " << 100.0 * acc / tot << " " << score << "/" << bscore << endl;
}


void Solve() {
    Prepare();

    Bimsa();

    F0(i, 20) {
        c_o[i] = t_o[i] = 0;
    }
    PR(Elapsed());
    Shuffle();

    PR(bscore);
    PrintSol(1);

    Report();
}


void ReadInput() {
    cin >> n >> m >> K >> T;
    F0(i, m) {
        int x, y;
        cin >> x >> y;
        p[0][i] = ID(x, y);
        cin >> x >> y;
        p[1][i] = ID(x, y);
    }
}

int main(int argc, char* argv[]) {
    Init();

    int seed1 = 0, seed2 = 0;
    if(argc>1) {
        if (argc == 2) {
            seed1 = seed2 = atoi(argv[1]);
        } else {
            seed1 = atoi(argv[1]);
            seed2 = atoi(argv[2]);
        }
        STANDARD=0;
    }

    if(STANDARD) {
        ReadInput();
        Solve();
        return 0;
    }

    for (int seed=seed1; seed<=seed2; seed++) {
        if(seed>=0 && seed<1000) {
            char inp[128];
            sprintf(inp, "in/%04d.txt", seed);
            char outp[128];
            sprintf(outp, "out/%04d.txt", seed);
            ignore = freopen(inp, "r", stdin);
            ignore = freopen(outp, "w", stdout);
            ReadInput();
            Solve();
            cerr << "Seed #" << seed << " ";
            cerr << bscore << endl;
            //cout << "Score would be " << bscore << endl;
        } else {
            // Generate
            Rand my(seed);
            n = 6; m = 5; K = 15000; T = 800;
            F0(i, m) {
                p[0][i] = my.nextInt(n * n);
                p[1][i] = p[0][i];
                while (d1[p[0][i]][p[1][i]] <= 4) {
                    p[0][i] = my.nextInt(n * n);
                }
            }
            Solve();
        }
    }

    return 0;
}
