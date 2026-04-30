// Topic 1 Task: Modify the program to append data instead of overwriting using ios::app

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string name;
    int age;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your age: ";
    cin >> age;

    // ios::app ensures data is appended, not overwritten
    ofstream outFile("user_info_append.txt", ios::app);

    if (!outFile) {
        cout << "Error: File could not be opened!" << endl;
        return 1;
    }

    outFile << "Name: " << name << "  |  Age: " << age << endl;

    outFile.close();
    cout << "Data appended successfully to user_info_append.txt" << endl;

    return 0;
}
