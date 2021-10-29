#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w;

    freopen("turtle.in", "r", stdin);
    freopen("turtle.out", "w", stdout);

    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = h - 1; i >= 0; i--) {
        for (int j = 0; j < w; j++) {

            int q1 = 0, q2 = 0;

            if (i != h - 1) {
                q1 = a[i + 1][j];
            }
            if (j != 0) {
                q2 = a[i][j - 1];
            }

            a[i][j] += max(q1, q2);

        }
    }

    cout << a[0][w - 1] << endl;
    return 0;

}
