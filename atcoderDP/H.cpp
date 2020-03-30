// g++ -std=c++17 H.cpp -o a.out && ./a.out < in
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#define ll long long
#define IOS cin.sync_with_stdio(false);cin.tie(nullptr);
#define endl "\n"
#define pb push_back
const ll NN = 1e5+5;
const ll mod = 1000000007;
using namespace std;

int main() {
    freopen("out", "w", stdout);
    IOS;
    int r, c;
    cin >> r >> c;
    char a[r][c];
    for (int t=0;t<r;++t) {
        for (int j=0;j<c;++j) {
            cin >> a[t][j];
        }
    }
    ll dp[r][c];
    dp[0][0] = 1;
    for (int t=1;t<c;++t) {
        if (a[0][t] == '#') dp[0][t] = 0;
        else dp[0][t] = dp[0][t-1];
    }
    for (int t=1;t<r;++t) {
        if (a[t][0] == '#') dp[t][0] = 0;
        else dp[t][0] = dp[t-1][0];
    }
    for (int t=1;t<r;++t) {
        for (int j=1;j<c;++j) {
            if (a[t][j] == '#') {
                dp[t][j] = 0;
                continue;
            }
            dp[t][j] = (dp[t-1][j] + dp[t][j-1]) % mod;
        }
    }
    cout << (dp[r-1][c-1] % mod);
}

