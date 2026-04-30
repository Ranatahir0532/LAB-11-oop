// Topic 4 Task: Read and display all objects from binary file
// NOTE: Run topic4_exercise_binary_write_multiple.cpp first to generate students_binary.dat

#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int id;
    char name[50];
    float gpa;
};

int main() {
    ifstream file("students_binary.dat", ios::binary);
    if (!file) {
        cout << "Error: Binary file not found!" << endl;
        cout << "Please run topic4_exercise_binary_write_multiple first." << endl;
        return 1;
    }

    Student s;
    int count = 0;

    cout << "===== Reading All Records from Binary File =====" << endl;
    while (file.read((char*)&s, sizeof(Student))) {
        count++;
        cout << "\nRecord " << count << ":" << endl;
        cout << "  ID   : " << s.id << endl;
        cout << "  Name : " << s.name << endl;
        cout << "  GPA  : " << s.gpa << endl;
    }

    file.close();

    if (count == 0) {
        cout << "No records found in the file." << endl;
    } else {
        cout << "\nTotal records read: " << count << endl;
    }

    return 0;
}
