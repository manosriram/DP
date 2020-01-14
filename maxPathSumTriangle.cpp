#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n+1][n+1], dp[n+1][n+1];

    for (int t=0;t<n;t++) {
        for (int j=0;j<n;j++) {
            if (j < t+1) cin >> a[t][j];
            else a[t][j] = 0;
        }
    }

    for (int t=0;t<n;++t)
        dp[0][t] = a[0][t];

    for (int t=1;t<n;++t)
        dp[t][0] = a[t][0] + dp[t-1][0];

    for (int t=1;t<n;++t) {
        for (int j=1;j<n;++j) {
            dp[t][j] = max(dp[t-1][j] + a[t][j], dp[t-1][j-1] + a[t][j]);
        }
    }

    int maxSum = INT_MIN;
    for (int t=0;t<n;++t)
        maxSum = max(maxSum, dp[n-1][t]);

    cout << maxSum;

}

