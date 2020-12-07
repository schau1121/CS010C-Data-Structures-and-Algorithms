#include <iostream>
#include <unordered_map>

using namespace std;

bool pairSum(int arr[], size_t size, int key) {
    unordered_map<int, int> map;
    for(size_t i = 0; i < size; i++) {
        if(map.find(key - arr[i]) != map.end()) {
            return true;
        }
        map[arr[i]] = i;
    }
    
    return false;
}



int main() {
    int array[] = {1, 5, 7, 10, 23};
    size_t sz = 5;
    int sum = 15;

    if(pairSum(array, sz, sum) == true) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}