// Topic 3 Exercise: Store 5 student records in a file using OOP

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
        ofstream file("students.txt", ios::app);
        if (!file) {
            cout << "Error: Could not open file!" << endl;
            return;
        }
        file << id << " " << name << " " << gpa << endl;
        file.close();
    }
};

int main() {
    const int TOTAL = 5;
    Student students[TOTAL];

    cout << "=== Enter details for 5 students ===" << endl;
    for (int i = 0; i < TOTAL; i++) {
        cout << "\n--- Student " << (i + 1) << " ---" << endl;
        students[i].input();
        students[i].writeToFile();
        cout << "Record saved." << endl;
    }

    cout << "\nAll 5 student records saved to students.txt successfully!" << endl;
    return 0;
}
