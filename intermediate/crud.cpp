#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
};

// Function to add a student record
void addStudent() {
    ofstream file("students.txt", ios::app);
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }
    
    Student s;
    cout << "Enter ID: ";
    cin >> s.id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter Age: ";
    cin >> s.age;

    file << s.id << "," << s.name << "," << s.age << endl;
    file.close();
    cout << "Student added successfully!\n";
}

// Function to display all student records
void viewStudents() {
    ifstream file("students.txt");
    if (!file) {
        cout << "No records found.\n";
        return;
    }

    string line;
    cout << "ID\tName\tAge\n";
    cout << "----------------------\n";

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, age;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, age, ',');
        cout << id << "\t" << name << "\t" << age << endl;
    }

    file.close();
}

// Function to update a student record
void updateStudent() {
    ifstream file("students.txt");
    if (!file) {
        cout << "No records found.\n";
        return;
    }

    vector<Student> students;
    Student s;
    string line;
    int targetId, found = 0;

    cout << "Enter ID of student to update: ";
    cin >> targetId;

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, age;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, age, ',');

        s.id = stoi(id);
        s.name = name;
        s.age = stoi(age);

        if (s.id == targetId) {
            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, s.name);
            cout << "Enter new Age: ";
            cin >> s.age;
            found = 1;
        }

        students.push_back(s);
    }
    file.close();

    if (!found) {
        cout << "Student ID not found.\n";
        return;
    }

    ofstream outFile("students.txt");
    for (const auto& student : students) {
        outFile << student.id << "," << student.name << "," << student.age << endl;
    }
    outFile.close();

    cout << "Student updated successfully!\n";
}

// Function to delete a student record
void deleteStudent() {
    ifstream file("students.txt");
    if (!file) {
        cout << "No records found.\n";
        return;
    }

    vector<Student> students;
    Student s;
    string line;
    int targetId, found = 0;

    cout << "Enter ID of student to delete: ";
    cin >> targetId;

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, age;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, age, ',');

        s.id = stoi(id);
        s.name = name;
        s.age = stoi(age);

        if (s.id != targetId) {
            students.push_back(s);
        } else {
            found = 1;
        }
    }
    file.close();

    if (!found) {
        cout << "Student ID not found.\n";
        return;
    }

    ofstream outFile("students.txt");
    for (const auto& student : students) {
        outFile << student.id << "," << student.name << "," << student.age << endl;
    }
    outFile.close();

    cout << "Student deleted successfully!\n";
}

// Main menu
int main() {
    int choice;
    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
