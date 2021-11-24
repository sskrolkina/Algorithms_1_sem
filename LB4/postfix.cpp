#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int main() {
    stack<int> CurList;
    int commands;
    ifstream fin("postfix.in");
    char b;
    int z;
    ofstream fout("postfix.out");
    for(;;){
        fin >> b;
        if(fin.eof())
            break;
        if(b -'0' > -1){
            CurList.push(b -'0');
        }
        else
            switch(b){
                case '+':
                    z = CurList.top();
                    CurList.pop();
                    CurList.top() = CurList.top() + z;
                    break;
                case '*':
                    z = CurList.top();
                    CurList.pop();
                    CurList.top() = CurList.top() * z;
                    break;
                case '-':
                    z = CurList.top();
                    CurList.pop();
                    CurList.top() = CurList.top() - z;
                    break;
            }
    }
    if(CurList.size() == 0){
        fout << '0';
    }
    else{
        fout << CurList.top();
    }
    return 0;
}
