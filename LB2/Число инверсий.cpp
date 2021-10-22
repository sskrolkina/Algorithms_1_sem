#include <fstream>
#include <vector>

using namespace std;

vector<long> array, temp_array;

long long inv_count = 0;

ifstream cin("inversions.in");
ofstream cout("inversions.out");

void merge(int left, int middle, int right) {
    int i = left;
    int j = middle;

    for (int k = left; k < right; k++) {
        if (j == right || (i < middle && array[i] <= array[j])) {
            temp_array[k] = array[i++];
        }
        else {
            inv_count += middle - i;
            temp_array[k] = array[j++];
        }
    }

    for (int i = left; i < right; i++) {
        array[i] = temp_array[i];
    }
}

void merge_thingy(int left, int right) {
    if (right - left <= 1) return;

    int middle = (left + right) / 2;
    merge_thingy(left, middle);
    merge_thingy(middle, right);
    merge(left, middle, right);
}

int main() {
    int n;
    cin >> n;

    array.resize(n);
    temp_array.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    merge_thingy(0, n);

    cout << inv_count;

    return 0;
}