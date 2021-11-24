#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void radixsort(vector<string> &arr, int m, int k,int i) {
    vector<string> res(arr.size(),"");
    vector<int> counters(26,0);
    for (int j = 0; j < arr.size(); j++) {
        counters[arr[j][i] - 'a']++;
    }
    int tmp, count = 0;
    for (int j = 0; j < counters.size(); j++) {
        tmp = counters[j];
        counters[j] = count;
        count += tmp;
    }
    for (int j = 0; j < arr.size(); j++) {
        res[ counters[arr[j][i] - 'a'] ] = arr[j];
        counters[arr[j][i] - 'a']++;
    }
    arr = res;
}



int main()
{
    ifstream inp("radixsort.in");
    int n, m, k;
    inp >> n >> m >> k;
    vector<string> a(n,"");
    for (int i = 0; i < n; i++) {
        inp >> a[i];
    }
    inp.close();
    for(int i = m - 1 ; i > m - k - 1 ; i-- )
        radixsort(a, m, k, i);
    ofstream outp("radixsort.out");
    for (int i = 0; i < n; i++) {
        outp << a[i] << endl;
    }
    outp.close();
}