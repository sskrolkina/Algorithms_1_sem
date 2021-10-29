#include <iostream>
#include <fstream>
using namespace std;

void quicksort(int* arr, int size) {
    int i = 0;
    int j = size - 1;

    int mid = arr[rand() % size];

    do {
        while (arr[i] < mid) {
            i++;
        }
        while (arr[j] > mid) {
            j--;
        }

        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    if (j > 0) {
        quicksort(arr, j + 1);
    }
    if (i < size) {
        quicksort(&arr[i], size - i);
    }
}

int main() {

    std::ifstream fin("sort.in");
    std::ofstream fout("sort.out");

    int a[300000];
    int n;

    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> a[i];
    }

    quicksort(a, n);

    for (int i = 0; i < n; ++i) {
        fout << a[i] << " ";
    }

    return 0;
}
