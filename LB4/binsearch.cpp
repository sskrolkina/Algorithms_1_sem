#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int middle(int a,int b){
    return (a+b)/2;
}
pair<int,int>bin(int key,vector<int>&items) {
    int left_l = -1, right_l = items.size(); //left
    int left_r = -1, right_r = items.size(); // right

    while (left_l < right_l - 1 || left_r < right_r - 1) {
        // left
        int middle_l = middle(right_l, left_l);
        if (items[middle_l] >= key) {
            right_l = middle_l;
        } else {
            left_l = middle_l;
        }
        //right
        int middle_r = middle(right_r, left_r);
        if (items[middle_r] <= key) {
            left_r = middle_r;
        } else {
            right_r = middle_r;
        }
    }
    if(items[right_l] != key){
        return{-1,-1};
    }
    else{
        return{right_l+1,left_r+1};
    }
}
int main(){
    vector<int> items;
    int t_size = 0;

    ifstream fin("binsearch.in");
    ofstream fout("binsearch.out");

    fin >> t_size;
    items.resize(t_size);
    for(int i = 0;i < t_size;i++){
        fin >> items[i];
    }
    fin >> t_size;
    for(int i = 0;i<t_size;i++){
        int yes;
        fin >> yes;
        pair<int,int>result = bin(yes,items);
        fout << result.first << " " << result.second << "\n";
    }
    return 0;
}
