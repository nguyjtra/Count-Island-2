#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };

void check(int a[][500], int n, int m, int i, int j) {
    a[i][j] = 0;
    for (int u = 0; u < 4; u++) {
        int idx = i + dx[u];
        int idy = j + dy[u];
        if (idx >= 0 && idx < n && idy >= 0 && idy < m && a[idx][idy] == 1) {
            check(a, n, m, idx, idy);
        }
    }
}
int main() {
    int n, m; cin >> n >> m;
    int a[n][500];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                ++count;
                check(a, n, m, i, j);
            }
        }
    }
    cout << count;

    return 0;
}
