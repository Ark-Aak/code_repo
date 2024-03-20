#include <vector>
#include <algorithm>

int count_sets(std::vector<int>& l, std::vector<int>& r) {
    int n = l.size();
    std::vector<std::pair<int, int>> lr(n);
    for (int i = 0; i < n; ++i) {
        lr[i] = {l[i], r[i]};
    }
    std::sort(lr.begin(), lr.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });

    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        int j = i - 1;
        while (j >= 0 && lr[j].first <= lr[i - 1].second) {
            --j;
        }
        if (j >= 0) {
            dp[i] += dp[j];
        } else {
            ++dp[i];
        }
    }
    return dp[n];
}
