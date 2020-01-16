#include <iostream>
using namespace std;

int toInt(char c) {
    return c-'0';
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int dp[n];
    dp[0] = toInt(s[0]);
    int res = dp[0];
    
    for (int t=1;t<n;++t) {
        int el = toInt(s[t]);
        dp[t] = (t+1) * el + 10 * dp[t-1];
        res += dp[t];
    }    
    cout << res;
}
