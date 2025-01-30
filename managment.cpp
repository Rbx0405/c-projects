#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random user ID
int generate_id()
{
    return 1000 + (rand() % 9000); // Generate a random 4-digit number
}

int main()
{
    srand(time(0)); // Seed the random number generator

    // Map to store user data with ID as the key
    map<int, pair<string, float> > user_data;

    int choice;

    do
    {
        cout << "\n=== User Management System ===\n";
        cout << "1. Add User\n";
        cout << "2. View User Information by ID\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            // Add a new user
            string name;
            float hours_worked;
            int user_id = generate_id();

            cout << "Enter user name: ";
            cin.ignore(); // To clear the newline left in the buffer
            getline(cin, name);

            cout << "Enter hours worked: ";
            cin >> hours_worked;

            // Store data in the map
            user_data[user_id] = make_pair(name, hours_worked);

            cout << "User added successfully!\n";
            cout << "Generated User ID: " << user_id << endl;
        }
        else if (choice == 2)
        {
            // View user information
            int search_id;
            cout << "Enter User ID: ";
            cin >> search_id;

            // Search in the map
            if (user_data.find(search_id) != user_data.end())
            {
                cout << "User Name: " << user_data[search_id].first << endl;
                cout << "Hours Worked: " << user_data[search_id].second << endl;
            }
            else
            {
                cout << "User ID not found.\n";
            }
        }
        else if (choice == 3)
        {
            cout << "Exiting program. Goodbye!\n";
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}