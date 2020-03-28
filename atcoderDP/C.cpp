// g++ -std=c++17 C.cpp -o a.out && ./a.out < in
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

int dp[110000][3];
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    for (int t=0;t<n;++t) {
        for (int j=0;j<3;++j) {
            cin >> dp[t][j];
        }
    }

    for (int t=1;t<n;++t) {
        for (int j=0;j<3;++j) {
            if (j == 0) {
                dp[t][j] += max(dp[t-1][j+1], dp[t-1][j+2]);
            } else if (j == 1) {
                dp[t][j] += max(dp[t-1][j-1], dp[t-1][j+1]);
            } else {
                dp[t][j] += max(dp[t-1][j-1], dp[t-1][j-2]);
            }
        }
    }

    int max_ = INT_MIN;
    for (int t=0;t<3;++t) max_ = max(max_, dp[n-1][t]);

    cout << max_ << endl;
}
