#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("priorityqueue.in");
ofstream fout("priorityqueue.out");

void Min(int a[],int i, int n){
    int l = i * 2;
    int r = i * 2 + 1;
    int son;

    if(l <= n && a[l] < a[i]){
        son = l;
    }
    else{
        son = i;
    }
    if(r <= n && a[r] < a[son]){
        son = r;
    }
    if(son != i){
        swap(a[i],a[son]);
        Min(a,son,n);
    }
}

void extractMin(int a[],int &n){
    if(n < 1){
        fout << "*\n";
        return;
    }
    int min = a[1];
    a[1] = a[n];
    n--;
    Min(a,1,n);
    fout << min << "\n";
    return;
}
void decreaseKey(int a[],int i, int k){
    a[i] = k;
    while(i > 1 && a[i/2] > a[i]){
        swap(a[i],a[i/2]);
        i = i/2;
    }
}
void push(int a[],int k,int &n){
    n++;
    a[n] = INT_MAX;
    decreaseKey(a,n,k);
}
int main(){
    int a[100000],b[100000];
    string command;
    int c,d;
    int n = 0, k = 0;

    while(fin >> command){
        if(command == "push"){
            fin >> c;
            push(b,c,n);
        }else if(command == "extract-min"){
            c = -1;
            extractMin(b,n);
        }else if(command == "decrease-key"){
            fin >> c >> d;
            int l;
            for(l = 1; l <= n;l++){
                if(a[c]==b[l]){
                    break;
                }
            }
            decreaseKey(b,l,d);
            a[c] = d;
        }
        k++;
        a[k] = c;
    }
}