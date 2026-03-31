#include <iostream>
#include <vector>
using namespace std;

int reverseNumber(int num) {
    int rev = 0;
    while (num > 0) {
        rev = rev * 10 + (num % 10);
        num /= 10;
    }
    return rev;
}

int main() {
    vector<int> arr = {123, 456, 789};
    
    for (int num : arr) {
        cout << reverseNumber(num) << " ";
    }
    return 0;
}
