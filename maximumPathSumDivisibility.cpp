#include <iostream>
#include <math.h>
using namespace std;

int divs(int n, int *a) {
    int max_ = INT_MIN;

    for (int t=1;t<=sqrt(n+1) && t % n == 0;++t) {
            max_ = max(max_, a[t]);
    }

    return max_;
}

int main() {
    int n;
    cin >> n;
    int a[n+1], dp[n+1];
    for (int t=1;t<=n;++t) cin >> a[t];

    dp[0] = a[0];
    dp[1] = (a[0] + a[1] > a[1]) ? a[0] + a[1] : a[1];
    for (int t=2;t<=n;++t) {
        dp[t] = max(divs(t, a) + a[t], 0);
    }

    for (int t=1;t<=n;++t) cout << dp[t] << " ";
}

