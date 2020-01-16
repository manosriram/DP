#include <iostream>
using namespace std;

int main() {
    int a[] = {10, 20, -30, -1};
    int n = sizeof(a)/sizeof(a[0]), k=2;
    int maxE=0, maxF = INT_MIN;
    for (int t=0;t<n*k;++t) {
        maxE += a[t%n];

        if (maxE > maxF)
            maxF = maxE;

        if (maxE < 0)
            maxE = 0;
    }
    cout << maxF;
}

