// Topic 3 Task: Add a function to display all students from file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    float gpa;

public:
    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter GPA: ";
        cin >> gpa;
    }

    void display() {
        cout << "ID: " << id << "  Name: " << name << "  GPA: " << gpa << endl;
    }

    void writeToFile() {
        ofstream file("students_display.txt", ios::app);
        if (!file) {
            cout << "Error: Could not open file for writing!" << endl;
            return;
        }
        file << id << " " << name << " " << gpa << endl;
        file.close();
    }

    // Function to display all students stored in the file
    static void displayAllFromFile() {
        ifstream file("students_display.txt");
        if (!file) {
            cout << "Error: File not found or no records saved yet!" << endl;
            return;
        }

        int fId;
        string fName;
        float fGpa;
        int count = 0;

        cout << "\n===== All Student Records =====" << endl;
        while (file >> fId >> fName >> fGpa) {
            count++;
            cout << "Record " << count << ": "
                 << "ID=" << fId
                 << "  Name=" << fName
                 << "  GPA=" << fGpa << endl;
        }

        if (count == 0) {
            cout << "No records found." << endl;
        } else {
            cout << "Total records: " << count << endl;
        }

        file.close();
    }
};

int main() {
    int choice;

    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            s.input();
            s.writeToFile();
            cout << "Student saved!" << endl;
        } else if (choice == 2) {
            Student::displayAllFromFile();
        }

    } while (choice != 3);

    return 0;
}
