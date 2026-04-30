// Topic 1 Exercise: Take user name and age, store it in a file

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

    ofstream outFile;
    outFile.open("user_info.txt");

    if (!outFile) {
        cout << "Error: File could not be opened!" << endl;
        return 1;
    }

    outFile << "Name: " << name << endl;
    outFile << "Age: " << age << endl;

    outFile.close();
    cout << "Data successfully written to user_info.txt" << endl;

    return 0;
}
