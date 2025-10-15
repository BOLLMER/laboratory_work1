#ifndef LIST_H
#define LIST_H

#include <string>
using namespace std;

//узел списка
struct Node {
    string value; //значение (строка)
    Node* next;   //указатель на следующий элемент
};

//сам список
struct MyList {
    Node* head; //начало списка
};

void initList(MyList &list);
void freeList(MyList &list);
void addHead(MyList &list, const string& val);
void addTail(MyList &list, const string& val);
void delHead(MyList &list);
void addAfter(MyList &list, const string& target, const string& val);
void addBefore(MyList &list, const string& target, const string& val);
void delTail(MyList &list);
void delByValue(MyList &list, const string& val);
void findValue(const MyList &list, const string& val);
void readForward(const MyList &list);
void readBack(const MyList &list);

void delAfterValue(MyList &list, const string& val);
void delBeforeValue(MyList &list, const string& val);

#endif
