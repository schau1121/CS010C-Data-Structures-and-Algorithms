#include <cstdio>
#include <stdexcept>
#include <iostream>

using namespace std;

template <class T>
class TwoStacks {
 public:
  // Constructor, initialize the array to size_hint
  TwoStacks(size_t size_hint = 16) : size_(size_hint), array_(new T(size_hint)) {}
  // Destructor
  ~TwoStacks() { delete array_; }

  // Push a value to the first stack
  void push_first(const T& val) {
    if(top_first + 1 < top_second) {
        top_first++;
        array_[top_first] = val;
    }
    else {
        size_t new_size = 2 * size_;
        size_t i, j;
        T* temp_array = new T[size_];
        for(i = 0; i < size_; i++){
            temp_array[i] = array_[i];
        }
        array_ = new T[new_size];
        for(i = 0; i < top_first + 1; i++) {
            array_[i] = temp_array[i];
        }
        j = new_size - 1;
        for(i = size_ - 1; i >= top_second; i--) {
            array_[j] = temp_array[i];
            j--;
        }
        top_second = j + 1;
        top_first++;
        array_[top_first] = val;
        size_ = new_size;
    }
  }

  // Push a value to the second stack
  void push_second(const T& val) {
    if(top_second > top_first + 1) {
        top_second--;
        array_[top_second] = val;
    }
    else {
        size_t new_size = 2 * size_;
        size_t i, j;
        T* temp_array = new T[size_];
        for(i = 0; i < size_; i++){
            temp_array[i] = array_[i];
        }
        array_ = new T[new_size];
        for(i = 0; i < top_first + 1; i++) { //copy first stack
            array_[i] = temp_array[i];
        }

        j = new_size - 1;
        for(i = size_ - 1; i > top_second - 1; i--) { //copy second stack
            array_[j] = temp_array[i];
            j--;
        }
        top_second = j;
        array_[top_second] = val;
        size_ = new_size;
    }
  } 

  // Pop from the first stack and return the value
  T pop_first() {
    if(empty_first()) {
      throw out_of_range("First stack empty");
    }
    else {
      T currElement = array_[top_first];
      top_first--;
      return currElement;
    }
  }

  // Pop from the second stack and return the value
  T pop_second() {
    if(empty_second()) {
      throw out_of_range("Second stack empty");
    }
    else {
      T currElement = array_[top_second];
      top_second++;
      return currElement;
    }
  }

  // Return the size of the first stack
  size_t size_first() const {
    return top_first + 1;
  }

  // Return the size of the second stack
  size_t size_second() const {
    return size_ - top_second;
  }

  void print_first() const {
      if(empty_first()) {
          cout << "Empty stack" << endl;
      }
      else {
        cout << "Stack 1:" << endl;
        for(size_t i = 0; i <= top_first; i++) {
            cout << array_[i] << " ";
        }
        cout << "\nTop of stack 1: Element " << top_first << endl;
      }
  }

  void print_second() const {
    if(empty_second()) {
        cout << "Empty stack" << endl;
    }
    else {
        cout << "Stack 2:" << endl;
        for(size_t i = size_ - 1; i >= top_second; i--) {
            cout << array_[i] << " ";
        } 
        cout << "\nTop of stack 2: Element " << top_second << endl;
    }
  }

  void print_array() const {
    cout << "Current array elements:" << endl;
    for(size_t i = 0; i < size_; i++) {
      cout << array_[i] << " ";
      cout << endl;
    }
  }

  // Return true if the first stack is empty
  bool empty_first() const { return size_first() == 0; }

  // Return true if the second stack is empty
  bool empty_second() const { return size_second() == 0; }

 private:
  size_t size_;
  T *array_;
  size_t top_first = -1;
  size_t top_second = size_;
};