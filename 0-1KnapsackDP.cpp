#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    vector<int> cost, wt;
    int w, n;
    cin >> n >> w;
    int a[n], ww[n];
    for (int t=0;t<n;++t) cin >> ww[t] >> a[t];

    for (int t=0;t<n;++t) {
        if (a[t] != -1) {
           cost.push_back(a[t]);
           wt.push_back(ww[t]); 
        }
    }

    n = cost.size();
    int dp[n+1][w+1];
    for (int t=0;t<=w;++t) dp[0][t] = INT_MAX;
    
    for (int t=1;t<=n;++t) dp[t][0] = 0;
    
    for (int t=1;t<=n;++t) {
        for (int j=1;j<=w;++j) {
           if (wt[t-1] > j) // If weight is greater than capacity.
              dp[t][j] = dp[t-1][j]; 

           else // Minimum of: upper row element and same row (column - wt[t-1]) element.
            dp[t][j] = min(dp[t-1][j], dp[t][j-wt[t-1]] + cost[t-1]);
        }
    }
    cout << dp[n][w];
}

