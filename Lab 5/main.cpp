#include <iostream>
#include <stdexcept>
#include <string>

#include "stack.h"

using namespace std;

int main() {
  cout << "Enter a test number(1-5): ";
  int test;
  cin >> test;
  cout << endl;
  switch (test) {
    case 1: {
      // tests constructor, push, pop, top and empty
      try {
        cout << "\nstack1 constructor called";
        stack<int> stack1;
        cout << (stack1.empty() ? "\nstack1 is empty."
                                : "\nstack1 is not empty");
        cout << "\npush 10";
        stack1.push(10);
        cout << "\npush 20";
        stack1.push(20);
        cout << "\npush 30";
        stack1.push(30);
        cout << "\nstack1 top: " << stack1.top();
        cout << "\npop";
        stack1.pop();
        cout << "\nstack1 top: " << stack1.top();
        cout << "\npop";
        stack1.pop();
        cout << "\nstack1 top: " << stack1.top();
        cout << "\npop";
        stack1.pop();
        cout << (stack1.empty() ? "\nstack1 is empty."
                                : "\nstack1 is not empty");
        cout << endl;
      } catch (underflow_error& e) {
        cout << e.what() << endl;
      } catch (overflow_error& e) {
        cout << e.what() << endl;
      } catch (out_of_range& e) {
        cout << e.what() << endl;
      }
      break;
    }
    case 2: {
      // tests top on empty stack
      try {
        cout << "\nstack2 constructor called";
        stack<int> stack2;
        cout << "\nstack2 top: " << stack2.top() << endl;
      } catch (underflow_error& e) {
        cout << e.what() << endl;
      } catch (overflow_error& e) {
        cout << e.what() << endl;
      } catch (out_of_range& e) {
        cout << e.what() << endl;
      }
      break;
    }
    case 3: {
      // tests pop from an empty stack
      try {
        cout << "\nstack3 constructor called";
        stack<int> stack3;
        cout << "\npop from empty stack\n";
        stack3.pop();
        cout << endl;
      } catch (underflow_error& e) {
        cout << e.what() << endl;
      } catch (overflow_error& e) {
        cout << e.what() << endl;
      } catch (out_of_range& e) {
        cout << e.what() << endl;
      }
      break;
    }
    case 4: {
      // tests push to a full stack
      try {
        cout << "\nstack4 constructor called";
        stack<int> stack4;
        cout << "\npush 20 elements";
        for (int i = 1; i <= 20; ++i) stack4.push(i);
        cout << "\nstack4 top: " << stack4.top();
        cout << "\npush 21\n";
        stack4.push(21);
        cout << endl;
      } catch (underflow_error& e) {
        cout << e.what() << endl;
      } catch (overflow_error& e) {
        cout << e.what() << endl;
      } catch (out_of_range& e) {
        cout << e.what() << endl;
      }
      break;
    }
    case 5: {
      // tests stack of strings
      try {
        cout << "\nstack5 constructor called";
        stack<string> stack5;
        cout << "\npush A";
        stack5.push("A");
        cout << "\npush B";
        stack5.push("B");
        cout << "\npush C";
        stack5.push("C");
        cout << "\nstack5 top: " << stack5.top();
        cout << "\npop";
        stack5.pop();
        cout << "\nstack5 top: " << stack5.top();
        cout << "\npop";
        stack5.pop();
        cout << "\nstack5 top: " << stack5.top();
        cout << "\npop";
        stack5.pop();
        cout << (stack5.empty() ? "\nstack5 is empty."
                                : "\nstack5 is not empty");
        cout << "\nstack5 top: \n";
        stack5.top();
        cout << endl;
      } catch (underflow_error& e) {
        cout << e.what() << endl;
      } catch (overflow_error& e) {
        cout << e.what() << endl;
      } catch (out_of_range& e) {
        cout << e.what() << endl;
      }
      break;
    }
    default:
      break;
  }
  return 0;
}