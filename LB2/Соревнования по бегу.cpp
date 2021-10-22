#include <fstream>
#include <vector>

using namespace std;

vector<vector<string>> array, temp_array;

ifstream cin("race.in");
ofstream cout("race.out");

void merge(int left, int middle, int right) {
    int i = left;
    int j = middle;

    for (int k = left; k < right; k++) {
        if (j == right || (i < middle && array[i][0] <= array[j][0])) {
            temp_array[k] = array[i];
            i++;
        }
        else {
            temp_array[k] = array[j];
            j++;
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
        array[i].resize(2);
        cin >> array[i][0] >> array[i][1];
    }

    merge_thingy(0, n);

    string last_current_country_output = "";

    for (int i = 0; i < n; i++) {
        if (last_current_country_output != array[i][0]) {
            cout << "===" << " " << array[i][0] << " " << "===" << endl;
            last_current_country_output = array[i][0];
        }
        cout << array[i][1] << endl;
    }
    return 0;
}