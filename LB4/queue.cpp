//лучше сделать через списки

#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("queue.in");
    ofstream fout("queue.out");
    queue<int> happy;
    int n;
    fin >> n;
    char znak;

    for (int i = 0; i < n; i++) {
        fin >> znak;
        if (znak == '+') {
            int b;
            fin >> b;
            happy.push(b);
        } else {
            fout << happy.front() << endl;
            happy.pop();
        }
    }
    return 0;
}
