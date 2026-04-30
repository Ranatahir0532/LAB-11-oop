// Topic 4 Exercise: Store multiple objects in a binary file

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Student {
public:
    int id;
    char name[50];
    float gpa;
};

int main() {
    const int TOTAL = 3;
    Student students[TOTAL];

    cout << "=== Enter details for " << TOTAL << " students ===" << endl;
    for (int i = 0; i < TOTAL; i++) {
        cout << "\n--- Student " << (i + 1) << " ---" << endl;
        cout << "Enter ID: ";
        cin >> students[i].id;
        cout << "Enter Name: ";
        cin >> students[i].name;
        cout << "Enter GPA: ";
        cin >> students[i].gpa;
    }

    // Write all objects to binary file
    ofstream file("students_binary.dat", ios::binary);
    if (!file) {
        cout << "Error: Could not open binary file for writing!" << endl;
        return 1;
    }

    for (int i = 0; i < TOTAL; i++) {
        file.write((char*)&students[i], sizeof(Student));
    }

    file.close();
    cout << "\n" << TOTAL << " student records written to students_binary.dat successfully!" << endl;

    return 0;
}
