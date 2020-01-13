#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n+1], dp[n+1];

    for (int t=1;t<=n;++t) cin >> a[t];
    
    dp[1] = max(0, a[1]);
    dp[2] = dp[1];

    for (int t=3;t<=n;++t)
        dp[t] = max(dp[t-2], (dp[t-2]+a[t]));

    auto max_ = *max_element(dp, dp+n+1);
    cout << max_;
}

