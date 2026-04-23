// CSCI-40 Final Project
// Author: Lizette Iriarte

/* 
 Description: This code will be a system that stores information of different students. It will allow the user to add students using their name, ID, major, and contact info.
 The user will also be able to add and remove students. Users will be able to search up the students using their name or ID. 
 As well as sorting the students by ID/name.* 
 *
*/

#include <iostream>

using namespace std;

struct Student {
    string name;
    int id;
    string major;
    string contact;
};

int main()
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
