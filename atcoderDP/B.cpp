// g++ -std=c++17 B.cpp -o a.out && ./a.out < in
#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <stack>
#include <queue>
#include <set>
#include <time.h>
#include "unordered_map"
using namespace std;
#define MAX INT_MAX
#define MIN INT_MIN
#define INF 1e9
#define pb push_back
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;

int a[110000], dp[110000];
int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("out", "w", stdout);

    ll n, k;
    cin >> n >> k;
    for (int t=0;t<n;++t) cin >> a[t];

    for (int t=0;t<=n;++t) dp[t] = 1000000007;
    dp[0] = 0;
    for (int t=0;t<n;++t) {
        for (int j=1;j<=k;++j) {
            if (t+j<n) dp[t+j] = min(dp[t+j], dp[t] + abs(a[t] - a[t+j]));
        }
    }
    cout << dp[n-1];
}

