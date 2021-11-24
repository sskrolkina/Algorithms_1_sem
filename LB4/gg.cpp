#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("stack.in");
    ofstream fout("stack.out");
    stack<int>sad;
    int n;
    fin >> n;
    char znak;

    for (int i = 0; i < n; i++) {
        fin >> znak;
        if (znak == '+') {
            int b;
            fin >> b;
            sad.push(b);
        }
        else {
            fout << sad.top() << endl;
            sad.pop();
        }
    }
    return 0;
}