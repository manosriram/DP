#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem Link: https://leetcode.com/problems/counting-bits/

vector<int> countBits(int n) {
    vector<int> dp;
    dp.push_back(0);
    dp.push_back(1);


    for (int t=2;t<=n;) {
        int go = t/2;

        for (int j=go;j<t;++j)
            dp.push_back(dp[j]);

        for (int j=go;j<t;++j)
            dp.push_back(dp[j]+1);

        t *= 2;
    }
    dp.erase(dp.begin() + n + 1, dp.end());
    return dp;
}

int main() {
    vector<int> v = countBits(2);

    for (auto t: v)
        cout << t << " ";
}

