// Final Task: Student Management System
// Features: Add student | View all students | Search student | File storage

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

const string FILENAME = "final_students.txt";

class Student {
public:
    int id;
    string name;
    float gpa;

    // Save one student record to file
    void saveToFile() const {
        ofstream file(FILENAME, ios::app);
        if (!file) {
            throw runtime_error("Error: Cannot open file for writing!");
        }
        file << id << "|" << name << "|" << gpa << endl;
        file.close();
    }

    // Display a single student record
    void display() const {
        cout << "  ID   : " << id << endl;
        cout << "  Name : " << name << endl;
        cout << "  GPA  : " << gpa << endl;
    }
};

// Parse a line from file into a Student object
bool parseLine(const string& line, Student& s) {
    stringstream ss(line);
    string idStr, gpaStr;

    if (!getline(ss, idStr, '|'))   return false;
    if (!getline(ss, s.name, '|'))  return false;
    if (!getline(ss, gpaStr))       return false;

    try {
        s.id  = stoi(idStr);
        s.gpa = stof(gpaStr);
    } catch (...) {
        return false;
    }
    return true;
}

// Add a new student
void addStudent() {
    try {
        Student s;
        cout << "Enter Student ID   : ";
        cin >> s.id;
        cout << "Enter Student Name : ";
        cin >> s.name;
        cout << "Enter Student GPA  : ";
        cin >> s.gpa;

        s.saveToFile();
        cout << "Student record added successfully!" << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

// View all students
void viewAllStudents() {
    try {
        ifstream file(FILENAME);
        if (!file) {
            throw runtime_error("Error: No records found. File does not exist yet.");
        }

        string line;
        int count = 0;
        cout << "\n========== All Student Records ==========" << endl;

        while (getline(file, line)) {
            Student s;
            if (parseLine(line, s)) {
                count++;
                cout << "\nRecord #" << count << ":" << endl;
                s.display();
            }
        }

        file.close();
        if (count == 0) {
            cout << "No valid records found." << endl;
        } else {
            cout << "\nTotal students: " << count << endl;
        }

    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

// Search student by ID
void searchStudent() {
    try {
        int searchId;
        cout << "Enter Student ID to search: ";
        cin >> searchId;

        ifstream file(FILENAME);
        if (!file) {
            throw runtime_error("Error: Records file not found. Add students first.");
        }

        string line;
        bool found = false;

        while (getline(file, line)) {
            Student s;
            if (parseLine(line, s) && s.id == searchId) {
                cout << "\nStudent found!" << endl;
                s.display();
                found = true;
                break;
            }
        }

        file.close();
        if (!found) {
            cout << "No student found with ID: " << searchId << endl;
        }

    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

int main() {
    int choice;

    cout << "========================================" << endl;
    cout << "   Student Management System (C++)      " << endl;
    cout << "========================================" << endl;

    do {
        cout << "\n--- Main Menu ---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. View All Students" << endl;
        cout << "3. Search Student by ID" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent();     break;
            case 2: viewAllStudents(); break;
            case 3: searchStudent();  break;
            case 4: cout << "Exiting program. Goodbye!" << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
