// Topic 5 Exercise: Handle file opening error using exception handling

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename;
    cout << "Enter filename to open: ";
    cin >> filename;

    try {
        ifstream file(filename);

        if (!file) {
            throw runtime_error("Error: File '" + filename + "' does not exist or cannot be opened!");
        }

        cout << "File opened successfully! Contents:" << endl;
        cout << "-------------------------------------" << endl;

        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
        cout << "-------------------------------------" << endl;
        cout << "File read and closed successfully." << endl;

    } catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
        cout << "Please make sure the file exists and try again." << endl;
    }

    return 0;
}
