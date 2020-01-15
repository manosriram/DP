#include <iostream>
using namespace std;

int main() {
    int a[] = {5, 15, 10, 300};
    int n = sizeof(a)/sizeof(a[0]), sm = 0, k = 12;

    sort(a, a+n);
    for (int t=n-1;t>0;t--) {
        if (a[t] - a[t-1] < k) {
            sm += (a[t] + a[t-1]);
            --t;
        }
    }
    cout << sm;
}

