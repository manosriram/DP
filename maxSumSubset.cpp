#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n+1], dp[n+1];

    for (int t=1;t<=n;++t) cin >> a[t];

    dp[1] = max(0, a[1]);

    for (int t=2;t<=n;++t)
        dp[t] = max(dp[t-1], (dp[t-1] + a[t]));

    cout << dp[n];
}

