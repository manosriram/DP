#include <iostream>
#include <vector>
using namespace std;

// Problem Link: https://leetcode.com/problems/count-square-submatrices-with-all-ones/

int threeMin(int a, int b, int c) {
    int tm = min(a, b);
    tm = min(tm, c);
    return tm;
}

int countSquares(vector<vector<int> >& matrix) {
    int r = matrix.size(), c = matrix[0].size();
    int sum = 0;
    for (int i=1;i<r;++i) {
        for (int j=1;j<c;++j) {
            if (matrix[i][j] == 0)
                continue;

            matrix[i][j] = threeMin(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]) + 1;

        }
    }

    for (int i=0;i<r;++i) {
        for (int j=0;j<c;++j) {
            cout << matrix[i][j] << " ";
            sum += matrix[i][j];
        }
        cout << endl;
    }

    return sum;
}

int main() {
    vector<vector<int> > mat;
    vector<int> tm;
    int m, n, temp;
    cin >> m >> n;

    for (int t=0;t<m;t++) {
        for (int j=0;j<n;j++) {
            cin >> temp;
            tm.push_back(temp);
        }
        mat.push_back(tm);
        tm.clear();
    }
    
    cout << countSquares(mat);
}

