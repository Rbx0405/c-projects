#include <iostream>

using namespace std;

int main() {
    int num;
    
    // Input from user
    cout << "Enter a number: ";
    cin >> num;

    // Check if even or odd
    if (num % 2 == 0) {
        cout << num << " is Even." << endl;
    } else {
        cout << num << " is Odd." << endl;
    }

    return 0;
}