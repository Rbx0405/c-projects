#include <iostream>
using namespace std;

int main()
{
    int n;

    // Ask user for the number of inputs
    cout << "Enter the number of elements: ";
    cin >> n;

    // Declare an array to store inputs
    int arr[n];

    // Taking inputs from user
    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Display stored inputs
    cout << "You entered: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}