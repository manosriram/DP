// g++ -std=c++17 I.cpp -o a.out && ./a.out < in
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
using namespace std;

int main() {
    freopen("out", "w", stdout);
    IOS;
    int n;
    cin >> n;
    double a[n];
    for (int t=0;t<n;++t) cin >> a[t];

    double dp[n][n];
    dp[0][0] = 1;

    for (int t=0;t<n;++t) {
        for (int j=0;j<n;++j) {
        }
    }

    for (int t=0;t<n;++t) {
        for (int j=0;j<n;++j) {
            cout << dp[t][j] << " ";
        }
        cout << endl;
    }


    cout << s << endl;
}

