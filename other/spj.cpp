#include "testlib.h"
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
    // 初始化特殊评测器
    registerTestlibCmd(argc, argv);

    // 读取答案和参赛者输出
    double expected = ans.readDouble();
    double contestant = ouf.readDouble();

    // 设置允许的最大绝对误差和相对误差
    const double absolute_error_limit = 1e-6;
    const double relative_error_limit = 1e-6;

    // 计算绝对误差和相对误差
    double absolute_error = abs(expected - contestant);
    double relative_error = absolute_error / max(abs(expected), abs(contestant));

    // 检查误差是否在允许范围内
    if (absolute_error <= absolute_error_limit || relative_error <= relative_error_limit) {
        // 如果在范围内，则评测通过
        quitf(_ok, "Accepted: answer is correct within tolerance");
    } else {
        // 如果不在范围内，则评测失败
        quitf(_wa, "Wrong Answer: absolute error=%.9f, relative error=%.9f", absolute_error, relative_error);
    }

    return 0;
}
