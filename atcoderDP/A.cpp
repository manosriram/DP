// g++ -std=c++17 A.cpp -o a.out && ./a.out < in
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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    int a[n], dp[n+1];
    for (int t=0;t<n;++t) cin >> a[t];

    dp[0] = 0, dp[1] = abs(a[1] - a[0]);

    for (int t=2;t<n;++t) {
        dp[t] = min((dp[t-1] + abs(a[t] - a[t-1])), (dp[t-2] + abs(a[t] - a[t-2])));
    }
    
    cout << dp[n-1];
}
