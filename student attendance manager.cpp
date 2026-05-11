#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float attendance;

    void input() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Attendance Percentage: ";
        cin >> attendance;
    }

    void display() const {
        cout << left << setw(10) << rollNo
             << setw(25) << name
             << setw(15) << attendance << "%" << endl;
    }
};

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n===== Student Attendance Manager =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            Student s;
            s.input();
            students.push_back(s);
            cout << "Student added successfully!\n";
            break;
        }

        case 2: {
            if (students.empty()) {
                cout << "No student records found.\n";
            } else {
                cout << "\n---------------------------------------------\n";
                cout << left << setw(10) << "Roll No"
                     << setw(25) << "Name"
                     << setw(15) << "Attendance" << endl;
                cout << "---------------------------------------------\n";

                for (const auto &s : students) {
                    s.display();
                }
            }
            break;
        }

        case 3: {
            int roll;
            bool found = false;

            cout << "Enter Roll Number to Search: ";
            cin >> roll;

            for (const auto &s : students) {
                if (s.rollNo == roll) {
                    cout << "\nStudent Found:\n";
                    cout << left << setw(10) << "Roll No"
                         << setw(25) << "Name"
                         << setw(15) << "Attendance" << endl;

                    s.display();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found.\n";
            }
            break;
        }

        case 4:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}