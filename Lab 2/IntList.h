#ifndef INT_LIST
#define INT_LIST
#include <iostream>

using namespace std;

struct IntNode {
    int data;
    IntNode* prev;
    IntNode* next;
    IntNode(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class IntList {
private:
    IntNode* dummyHead;
    IntNode* dummyTail;
public:
    IntList();
    ~IntList();
    void push_front(int value);
    void pop_front();
    void push_back(int value);
    void pop_back();
    bool empty() const;
    friend ostream & operator<<(ostream &out, const IntList &rhs);
    void printReverse() const;
};

#endif