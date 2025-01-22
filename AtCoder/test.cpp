#include <bits/stdc++.h>
using namespace std;

// We will frequently need 128-bit intermediate checks.
// In GCC/Clang, we can use built-in type __int128 for that.
static inline bool safeAddOverflow(long long a, long long b, long long limit) {
    // Check if a+b > limit (just a typical check to avoid 128-bit if we want)
    // We do a clamp or direct comparison
    return (a > limit - b);
}
static inline bool safeMulOverflow(long long a, long long b, long long limit) {
    // Check if a*b > limit
    // a,b <= ~2e9, so we can do 128-bit multiplication or just use a>limit/b etc.
    if (a == 0 || b == 0) return false;
    if (a > limit / b) return true;
    return false;
}

// We'll write a function to compute costX = sum(x_i^2 * P_i)
// but break early if costX > M (not feasible).
// We do everything in 64-bit but with checks.
long long computeBaseCostAndSumX(const vector<long long> &P,
                                 const vector<long long> &x,
                                 long long M, // budget for early cutoff
                                 long long &sumX)
{
    __int128 cost = 0;
    sumX = 0;
    for (int i = 0; i < (int)P.size(); i++) {
        long long xi = x[i];
        sumX += xi;
        // cost_i = xi^2 * P_i
        // check overflow or partial
        if (xi > 0) {
            // We do xi^2 as 128-bit or just check if xi>sqrt(M/P_i)
            // but let's do direct:
            __int128 c = ( __int128)xi * xi;
            c *= P[i];
            cost += c;
            if (cost > M) {
                return (long long)(cost); // exceed M
            }
        }
    }
    return (long long)cost;
}


// For leftover distribution, we do a "binary search on X" approach
// to find sum of smallest 'L' increments among inc_i(t) = P_i*(2*x_i + 2t + 1).
// We'll implement a function that, given X, computes:
//   1) T(X) = total # of increments <= X
//   2) sumAll(X) = sum of those increments
//   3) E(X) = how many increments == X
// We'll do this in O(N).
struct IncrementsSummary {
    long long T;     // total #inc <= X
    __int128 sumAll; // sum of those increments (use 128-bit partial)
    long long E;     // number of increments exactly = X
};

IncrementsSummary countAndSumIncrementsLE(const vector<long long> &P,
                                          const vector<long long> &x,
                                          long long X)
{
    // We'll accumulate T, sumAll, E over all i.
    // c'_i(X) = max(0, floor((X/P_i - 1)/2 - x_i) + 1).
    // if X < P_i*(2*x_i + 1), c'_i(X)=0.
    // sum of those increments = P_i * [ R^2 + 2*x_i*R ] if R>0, R = c'_i(X).
    // E(X) increment: check if the largest among them equals X.

    IncrementsSummary s;
    s.T = 0;
    s.sumAll = 0;
    s.E = 0;
    const int N = (int)P.size();

    for (int i = 0; i < N; i++) {
        long long pi = P[i];
        long long xi = x[i];

        // minimal increment for product i is inc_i(0) = pi*(2*xi + 1).
        long long minInc = pi * (2LL*xi + 1LL);
        if (minInc > X) {
            // then no increments <= X for this i
            continue;
        }

        // we want: pi*(2*xi + 2t + 1) <= X
        // => 2*xi + 2t + 1 <= X/pi
        // => 2t <= X/pi - 1 - 2*xi
        // => t <= floor((X/pi - 1 - 2*xi)/2)
        // => R_i = t_max + 1
        long long bound = (X / pi) - 1 - 2LL*xi;
        if (bound < 0) {
            // no increments
            continue;
        }
        long long R = (bound / 2) + 1;
        // R could be huge, but let's keep it in 64-bit as leftover won't exceed ~1e9 in typical usage
        if (R < 0) R = 0;

        s.T += R;
        // sum of these R increments: sum_{t=0..R-1} pi*(2*xi + 2t + 1)
        // = pi * [ R*(2xi+1) + 2* sum_{t=0..R-1} t ]
        // = pi * [ R*(2xi+1) + 2*(R(R-1)/2) ]
        // = pi * [ R*(2xi+1) + R(R-1) ]
        // = pi * [ R^2 + 2xi R ]
        __int128 tmp = ( __int128)R * R + 2LL*( __int128)xi * R;
        tmp *= pi;

        s.sumAll += tmp;

        // E(X): how many increments are exactly X from product i?
        // The largest among those R increments is inc_i(R-1) = pi*(2*xi + 2*(R-1) + 1).
        // We check if inc_i(R-1) == X.  If so, E(X)++.
        // inc_i(R-1) = pi*(2xi + 2(R-1) + 1)
        //            = pi*(2xi + 2R - 2 + 1)
        //            = pi*(2xi + 2R - 1)
        // Compare that to X
        long long lastInc = pi * (2LL*xi + 2LL*(R-1) + 1LL);
        if (lastInc == X) {
            s.E += 1;
        }
    }

    return s;
}

// We now write a function that, given we must pick 'L' increments total,
// returns the sum of the smallest L increments among all inc_i(t).
// We'll do a binary search on X up to some high value (e.g. ~4e18).
// Then we'll compute partial sums as described.
long long sumOfSmallestLIncrements(
    const vector<long long> &P,
    const vector<long long> &x,
    long long L,
    long long M
) {
    if (L == 0) return 0;

    // *** Increase the high bound to ~5e18 (or bigger if you prefer) ***
    long long lo = 0;
    long long hi = 5'000'000'000'000'000'000LL;  // e.g. 5e18

    while (lo < hi) {
        long long mid = (lo + hi) >> 1;
        IncrementsSummary s = countAndSumIncrementsLE(P, x, mid);
        if (s.T >= L) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    long long X = lo;
    IncrementsSummary s = countAndSumIncrementsLE(P, x, X);
    long long excess = s.T - L;
    __int128 ans = s.sumAll - ( (__int128)excess * X );
    // Return something big if it overflows M
    if (ans > M) return M+1;
    return (long long) ans;
}
// The main feasibility checker for a candidate S:
// 1) Compute ideal real k_i' = S / sum(1/Pj) * (1/P_i).
// 2) Let x_i = floor(k_i') (clamped >=0).
// 3) costX = sum(x_i^2 * P_i). If >M => not feasible
// 4) leftover L = S - sumX. If L<0 => not feasible (rounding issues).
// 5) leftoverCost = sumOfSmallestLIncrements(..., L).
// 6) totalCost = costX + leftoverCost <= M => feasible, else not.
bool feasible(long long S,
              const vector<long long> &P,
              long double invSumOfInvP, // = 1.0 / sum(1.0L/P[i]) or some approach
              long long M)
{
    // 1) compute x_i' in floating, then x_i = floor(...)
    // 2) sumX, costX
    // If costX > M => return false
    // 3) leftover => L = S - sumX
    // if L < 0 => false
    // 4) leftoverCost => add => check <= M

    int N = (int)P.size();
    vector<long long> x(N);

    // We'll do:
    //   scale = S * invSumOfInvP
    //   x_i' = scale / P[i]
    // Then x_i = floor(x_i')
    // Watch for floating rounding. We can do max(...,0).

    long double scale = (long double)S * invSumOfInvP;
    for (int i = 0; i < N; i++) {
        // x_i' = scale / P[i]
        long double val = scale / (long double)P[i];
        if (val < 0.0L) val = 0.0L; // just in case
        long long fl = (long long)floor(val);
        if (fl < 0) fl = 0; // safety
        x[i] = fl;
    }

    // compute costX
    long long sumX;
    long long costX = computeBaseCostAndSumX(P, x, M, sumX);
    if (costX > M) return false; // not feasible
    long long L = S - sumX;
    if (L < 0) {
        // sum of floors is bigger than S => can't do it
        return false;
    }
    if (L == 0) {
        // no leftover => total cost = costX <= M => feasible
        return (costX <= M);
    }
    // leftover distribution cost
    long long leftoverCost = sumOfSmallestLIncrements(P, x, L, M - costX);
    // check final
    // total = costX + leftoverCost
    // if leftoverCost alone is > M - costX => total cost > M
    if (leftoverCost > M - costX) return false;

    // else feasible
    return true;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;
    cin >> N >> M;
    vector<long long> P(N);
    for(int i=0; i<N; i++){
        cin >> P[i];
    }

    // We will do a binary search on S in [0.. up to ~1e9].
    // First, compute sum(1.0L / P[i]) => we'll store it in a long double.
    long double sumInvP = 0.0L;
    for(int i=0; i<N; i++){
        sumInvP += 1.0L / (long double)P[i];
    }
    // We'll often need the reciprocal of sumInvP:
    //   if sumInvP = 0, that means P[i] are huge? Actually P[i]>=1, sumInvP>0.
    long double invSumOfInvP = 1.0L / sumInvP;

    // Binary search for the maximum S
    long long lo = 0;
    long long hi = 1000000000LL + 2; // 1e9 + small margin

    while (lo < hi) {
        long long mid = (lo + hi + 1) >> 1; // try upper mid
        if (feasible(mid, P, invSumOfInvP, M)) {
            lo = mid; // mid is feasible
        } else {
            hi = mid - 1;
        }
    }
    int ans = lo;
    for (int i = 1; i <= 100; i++) if (feasible(lo + i, P, invSumOfInvP, M)) ans = lo + i;
    cout << lo << "\n";
    return 0;
}
