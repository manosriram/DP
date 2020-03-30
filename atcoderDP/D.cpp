// g++ -std=c++17 D.cpp -o a.out && ./a.out < in
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
int w[110];
int v[110];
ll dp[110000];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, ww;
    cin >> n >> ww;
    for (ll tt=0;tt<n;++tt)
        cin >> w[tt] >> v[tt];

    for (ll t=0;t<n;++t) {
        for (ll j=ww;j>=0;--j) {
            if (j + w[t] <= ww)
                dp[j + w[t]] = max(dp[j+w[t]], dp[j] + v[t]);
        }
    }
    ll ret = 0;
    for (ll t=0;t<=ww;++t) ret = max(ret, dp[t]);

    cout << ret;
}
