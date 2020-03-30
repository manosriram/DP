// g++ -std=c++17 F.cpp -o a.out && ./a.out < in
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#define ll long long
#define IOS cin.sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'
#define pb push_back
const ll NN = 1e5+5;
using namespace std;

int dp[3100][3100];
int main() {
    freopen("out", "w", stdout);
    IOS;
    string a, b;
    cin >> a >> b;
    if (b.length() > a.length()) swap(a, b);

    for (int t=0;t<a.length();++t) dp[0][t] = 0;

    for (int t=0;t<b.length();++t) dp[t][0] = 0;

    for (int t=1;t<=a.length();++t) {
        for (int j=1;j<=b.length();++j) {
            if (a[t-1] == b[j-1])
                dp[t][j] = 1 + dp[t-1][j-1];
            else
                dp[t][j] = max(dp[t-1][j], dp[t][j-1]);
        }
    }
    string res;

    int rr = b.length(), cc = a.length();
    while (rr > 0 && cc > 0) {
        if (a[cc-1] == b[rr-1]) {
            res += a[cc-1];
            --rr, --cc;
        } else if (dp[rr-1][cc] < dp[rr][cc-1]) {
            --rr;
        } else --cc;
    }
    reverse(res.begin(), res.end());
    cout << res;


}

