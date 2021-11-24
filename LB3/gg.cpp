#include <iostream>
#include <fstream>

using namespace std;

void heap(int a[],int n,int i){
    int mama = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && a[l] > a[mama]){
        mama = l;
    }
    if(r < n && a[r] > a[mama]){
        mama = r;
    }
    if(mama != i){
        swap(a[i],a[mama]);
        heap(a,n,mama);
    }
}
void heapsort(int a[],int n){
    for(int i = n / 2 - 1; i >= 0; i--){
        heap(a,n,i);
    }
    for(int i = n - 1; i > 0;i--){
        swap(a[0],a[i]);
        heap(a,i,0);
    }
}
int main(){
    ifstream fin("sort.in");
    ofstream fout("sort.out");
    int n;
    fin >> n;
    int *meh = new int[n];
    for(int i = 0; i < n;i++){
        fin >> meh[i];
    }
    heapsort(meh,n);
    for(int i = 0; i < n;i++){
        fout << meh[i] << " ";
    }
    return 0;
}