#include <iostream>
using namespace std;

int main() {
    int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(a)/sizeof(a[0]);
    int dp[n];
    memset(dp, 0, n);
    int sum = 0, in, maxIn = INT_MIN, in_;
    for (int t=0;t<n;++t) {
        sum += a[t];
        if (sum < 0) {
            in = t;
            sum = 0;
        }
        dp[t] = sum;

        if (sum > maxIn) {
            maxIn = sum;
            in_ = t;
        }
    }
    cout << (in_ - in);
}

