#include <cstdlib>
#include <fstream>
#include <iostream>

#include "HashTable.h"

using namespace std;

int main() {
    HashTable table(5);
    table.put("abc", 3);
    if(table.contains("abc") == true) {
        cout << "contains" << endl;
    }
    else {
        cout << "does not contain" << endl;
    }

    return 0;
}