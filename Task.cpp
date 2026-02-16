#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Function to display menu
void showMenu() {
    cout << "\n===== Student Management System =====\n";
    cout << "1. Add Student\n";
    cout << "2. View Students\n";
    cout << "3. Save to File\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

// Function to add a student
void addStudent(vector<string>& students) {
    string name;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, name);
    students.push_back(name);
    cout << "Student added successfully!\n";
}

// Function to display all students
void viewStudents(const vector<string>& students) {
    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }

    cout << "\n--- Student List ---\n";
    for (size_t i = 0; i < students.size(); i++) {
        cout << i + 1 << ". " << students[i] << endl;
    }
}

// Function to save students to file
void saveToFile(const vector<string>& students) {
    ofstream file("students.txt");

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    for (const string& student : students) {
        file << student << endl;
    }

    file.close();
    cout << "Data saved to students.txt successfully!\n";
}

int main() {
    vector<string> students;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                viewStudents(students);
                break;
            case 3:
                saveToFile(students);
                break;
            case 4:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}