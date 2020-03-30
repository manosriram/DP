// g++ -std=c++17 G.cpp -o a.out && ./a.out < in
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#define ll long long
#define IOS cin.sync_with_stdio(false);cin.tie(nullptr);
#define endl "\n"
#define pb push_back
const ll NN = 1e5+5;
using namespace std;
vector<int> g[110000];
int dp[110000];

int solve(int s) {
    if (dp[s] != -1) return dp[s];
    int ret = 0;
    for (int t=0;t<g[s].size();++t)
        ret = max(ret, solve(g[s][t]) + 1);

    return dp[s] = ret;
}

int main() {
    freopen("out", "w", stdout);
    IOS;

    int n, q, s, d;
    cin >> n >> q;
    while (q--) {
        cin >> s >> d;--s, --d;
        g[s].pb(d);
    }
    for (int t=0;t<n;++t) dp[t] = -1;

    int ret = 0;
    for (int t=0;t<n;++t)
        ret = max(ret, solve(t));

    cout << ret;
}
