#include <iostream>
#include <fstream>

using namespace std;

int main() {
    long long a, b, c;
    ifstream fin("aplusbb.in");
    ofstream fout("aplusbb.out");


    fin >> a >> b;
    fout << a + b * b;

    return 0;
}