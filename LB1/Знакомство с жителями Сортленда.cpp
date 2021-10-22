#include <iostream>
#include <fstream>

using namespace std;

int main() {
    pair<int, float> M[100000];

    ifstream fin("sortland.in");
    ofstream fout("sortland.out");

    int n;
    fin >> n;

    for (int i = 0; i < n; ++i) {
        float v;
        fin >> v;
        M[i] = pair<int, float>(i + 1, v);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (M[j].second > M[j + 1].second) {
                swap(M[j], M[j + 1]);
            }
        }
    }

    fout << M[0].first << ' ' << M[n / 2].first << ' ' << M[n - 1].first;


    return 0;
}