#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct list{
    char a;
    list *head,*next;
};

void push(char a,list *&CurList){
    list *newlist = new list;
    newlist -> a = a;
    newlist -> next = CurList -> head;
    CurList -> head = newlist;
    return;
}

char pop(list *&CurList){
    long long ret;
    ret = CurList-> head -> a;
    list *newlist = CurList -> head -> next;
    delete CurList -> head;
    CurList -> head = newlist;
    return ret;
}

int main() {
    list *CurList = new list;
    CurList->head = NULL;
    int com;
    ifstream fin("brackets.in");
    char b;
    char a;
    ofstream fout("brackets.out");
    string str;
    while(!fin.eof()){
        getline(fin,str);
        if(fin.eof())
            break;
        for(int i=0;i < str.length(); i++){
            a = str[i];
            push(a,CurList);
        }
        list *Check = new list;
        Check -> head = NULL;
        for(int i=0;i < str.length() ; i++){
            if(Check -> head == NULL){
                a = pop(CurList);
                push(a,Check);
                if(a=='(' || a=='['){
                    break;
                }
            }
            else{
                if(CurList -> head -> a == ')' || CurList -> head -> a == ']'){
                    a = pop(CurList);
                    push(a,Check);
                }
                else{
                    if((CurList -> head -> a == '(' && Check -> head -> a == ')') || (CurList -> head -> a == '[' && Check -> head -> a == ']') )
                    {
                        pop(CurList);
                        pop(Check);
                    }
                    else{
                        break;
                    }
                }
            }
            if(CurList -> head == NULL)
                break;
        }
        if(Check -> head == NULL)
            fout << "YES" << "\n";
        else
            fout << "NO" << "\n";
    }
    return 0;
}