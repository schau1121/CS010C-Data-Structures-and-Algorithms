#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 20

#include <stdexcept>
#include <iostream>

using namespace std;

template<class T>
class stack {
private:
    T data_[MAX_SIZE];
    int size_;
public:
    stack() {size_ = 0;};

    void push(const T &val) {
        if(size_ == MAX_SIZE) {
            throw overflow_error("Called push on full stack.");
        }
        else {
            data_[size_] = val;
            size_++;
        }
    }

    void pop() {
        if(size_ == 0) {
            throw out_of_range("Called pop on empty stack.");
        }
        size_--;
    }

    T top() const {
        if(size_ == 0) {
            throw underflow_error("Called top on empty stack.");
        }
        return data_[size_ - 1];
    }

    bool empty() const {
        if(size_ == 0) {
            return true;
        }
        else {
            return false;
        }
    }
};

#endif