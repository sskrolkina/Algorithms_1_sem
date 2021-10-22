#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("smallsort.in");
    ofstream fout("smallsort.out");

    long long a[10000], n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }for (int i = 0; i < n; i++) {
        fout << a[i] << " ";
    }

    return 0;
}