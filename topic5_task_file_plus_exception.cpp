// Topic 5 Task: Combine file handling + exception handling (read & write with full error coverage)

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

void writeToFile(const string& filename, const string& data) {
    try {
        ofstream file(filename, ios::app);
        if (!file) {
            throw runtime_error("Error: Cannot open '" + filename + "' for writing!");
        }
        file << data << endl;
        file.close();
        cout << "Data written successfully to " << filename << endl;
    } catch (const runtime_error& e) {
        cout << "Write Exception: " << e.what() << endl;
    }
}

void readFromFile(const string& filename) {
    try {
        ifstream file(filename);
        if (!file) {
            throw runtime_error("Error: File '" + filename + "' not found!");
        }

        string line;
        int lineNum = 1;
        cout << "\n--- Contents of " << filename << " ---" << endl;
        while (getline(file, line)) {
            cout << lineNum++ << ": " << line << endl;
        }
        file.close();

        if (lineNum == 1) {
            throw runtime_error("Warning: File exists but is empty!");
        }

    } catch (const runtime_error& e) {
        cout << "Read Exception: " << e.what() << endl;
    }
}

int main() {
    string filename = "combined_data.txt";
    int choice;

    do {
        cout << "\n--- File Handling + Exception Handling Menu ---" << endl;
        cout << "1. Write data to file" << endl;
        cout << "2. Read data from file" << endl;
        cout << "3. Try reading a non-existent file" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string data;
            cout << "Enter data to write: ";
            getline(cin, data);
            writeToFile(filename, data);
        } else if (choice == 2) {
            readFromFile(filename);
        } else if (choice == 3) {
            readFromFile("this_file_does_not_exist.txt");
        }

    } while (choice != 4);

    return 0;
}
