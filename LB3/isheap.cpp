#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream fin("isheap.in");
    ofstream fout("isheap.out");
    int n;
    bool k = 1;
    fin >> n;
    int *a = new int[n+1];
    for(int i = 1; i < n+1; i++) {
        fin >> a[i];
    }
    for(int i = 1; i < n/2; i++){
        if(2*i > n || a[i] > a[2*i]){
            k = 0;
        }
        if(2*i + 1 > n || a[i] > a[2*i + 1]){
            k = 0;
        }
    }
    if(k == 1){
        fout << "YES";
    }
    else {
        fout << "NO";
    }
    return 0;
}
