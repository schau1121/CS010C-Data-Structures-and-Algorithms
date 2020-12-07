#include "IntList.h"

IntList::IntList() {
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
}   

IntList::~IntList() {
    while(!empty()) {
        pop_back();
    }
}

void IntList::push_front(int value) {
    if(empty()) {
        IntNode* curr = new IntNode(value);
        dummyHead->next = curr;
        curr->prev = dummyHead;
        curr->next = dummyTail;
        dummyTail->prev = curr;
    }
    else {
        IntNode* curr = new IntNode(value);
        IntNode* temp = dummyHead->next;
        curr->next = temp;
        temp->prev = curr;
        dummyHead->next = curr;
        curr->prev = dummyHead;
    }
}

ostream & operator<<(ostream &out, const IntList &rhs) {
    IntNode* curr = rhs.dummyHead->next;
    while(curr != rhs.dummyTail) {
        out << curr->data;
        if(curr->next != rhs.dummyTail) {
            out << " ";
        }
        curr = curr->next;
        }
    return out;
}

bool IntList::empty() const {
    if(dummyHead->next == dummyTail) {
        return true;
    }
    else {
        return false;
    }
}

void IntList::pop_back() {
    if(empty()) {
        return;
    }
    if(dummyTail->prev == dummyHead->next) { //only one item
        delete dummyHead->next;
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    else {
        IntNode* temp = dummyTail->prev;
        dummyTail->prev = temp->prev;
        temp->prev->next = dummyTail;
        delete temp;
    }
}

void IntList::pop_front() {
    if(empty()) {
        return;
    }
    if(dummyHead->next == dummyTail->prev) {
        delete dummyHead->next;
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    else {
        IntNode* temp = dummyHead->next;
        dummyHead->next = temp->next;
        temp->next->prev = dummyHead;
        delete temp;
    }
}

void IntList::push_back(int value) {
    if(empty()) {
        push_front(value);
    }
    else {
        IntNode* curr = new IntNode(value);
        IntNode* temp = dummyTail->prev;
        temp->next = curr;
        curr->next = dummyTail;
        dummyTail->prev = curr;
        curr->prev = temp;
    }
}

void IntList::printReverse() const {
    IntNode* curr = dummyTail->prev;
    while(curr != dummyHead) {
        cout << curr->data << " ";
        curr = curr->prev;
    }
}