//CSCI - 40 Final Project
// Author: Lizette Iriarte

/*
 Description: This code will be a system that stores information of different students. It will allow the user to add students using their name, ID, major, and contact info.
 The user will also be able to add and remove students. Users will be able to search up the students using their name or ID.
 As well as sorting the students by ID/name.*
 *
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

struct Student {
    string name;
    int id;
    string major;
    string contact;
};

void addStudent(vector<Student>& students) {
    Student s;

    cin.ignore();
    cout << "Enter student name: ";
    getline(cin, s.name);
    cout << "Enter student ID: ";
    cin >> s.id;
    cin.ignore();
    cout << "Enter major: ";
    getline(cin, s.major);
    cout << "Enter contact info: ";
    getline(cin, s.contact);
    students.push_back(s);
    cout << "Student added successfully." << endl;
}

void removeStudent(vector<Student>& students) {
    int id;
    cout << "Enter student ID to remove: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            found = true;
            cout << "Student removed successfully." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Student not found." << endl;
    }
}

void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students in directory.";
        return;
    }
    cout << "\nStudent Directory:\n";
    for (const Student& s : students) {
        cout << "----------------------\n";
        cout << "Name: " << s.name << endl;
        cout << "ID: " << s.id << endl;
        cout << "Major: " << s.major << endl;
        cout << "Contact: " << s.contact << endl;
    }
}
void searchByID(const vector<Student>& students) {
    int id;
    cout << "Enter student ID to search: ";
    cin >> id;

    for (const Student& s : students) {
        if (s.id == id) {
            cout << "\n Student found:\n";
            cout << "Name: " << s.name << endl;
            cout << "ID: " << s.id << endl;
            cout << "Major: " << s.major << endl;
            cout << "Contact: " << s.contact << endl;
            return;
        }
    }
    cout << "Student not found. \n";
}

void searchByName(const vector<Student>& students) {
    string name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter student name to search: ";
    getline(cin, name);

    for (const Student& s : students) {
        if (s.name == name) {
            cout << "\n Student found:\n";
            cout << "Name: " << s.name << endl;
            cout << "ID: " << s.id << endl;
            cout << "Major: " << s.major << endl;
            cout << "Contact: " << s.contact << endl;
            return;
        }
    }
    cout << "Student not found. \n";
}
void saveStudents(const vector<Student>& students) {
    ofstream outFile("students.txt");
    for (const Student& s : students) {
        outFile << s.id << endl;
        outFile << s.name << endl;
        outFile << s.major << endl;
        outFile << s.contact << endl;
    }
}


void sortByID(vector<Student>& students) {
    sort(students.begin(), students.end(), [](Student a, Student b) {
        return a.id < b.id;
        });
    saveStudents(students);
    cout << "Students sorted by ID.\n";
}

void sortByName(vector<Student>& students) {
    sort(students.begin(), students.end(), [](Student a, Student b) {
        return a.name < b.name;
        });
    saveStudents(students);
    cout << "Students sorted by Name.\n";
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n --- Student Directory Menu ---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Remove Student" << endl;
        cout << "3. Search Student by ID" << endl;
        cout << "4. Search Students by Name" << endl;
        cout << "5. Sort Students by ID" << endl;
        cout << "6. Sort Students by Name" << endl;
        cout << "7. Display All Students" << endl;
        cout << "8. Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent(students);
            break;
        case 2:
            removeStudent(students);
            break;
        case 3:
            searchByID(students);
            break;
        case 4:
            searchByName(students);
            break;

        case 5:
            sortByID(students);
            break;
        case 6:
            sortByName(students);
            break;
        case 7:
            displayStudents(students);
            break;
        case 8:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 8);

    return 0;
}