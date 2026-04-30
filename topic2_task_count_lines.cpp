// Topic 2 Task: Count number of lines in a file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Step 1: Create a sample file to count lines in
    ofstream writeFile("sample_lines.txt");
    if (!writeFile) {
        cout << "Error: Could not create sample file!" << endl;
        return 1;
    }
    writeFile << "This is line one." << endl;
    writeFile << "This is line two." << endl;
    writeFile << "This is line three." << endl;
    writeFile << "This is line four." << endl;
    writeFile << "This is line five." << endl;
    writeFile.close();
    cout << "sample_lines.txt created." << endl;

    // Step 2: Open file and count lines
    ifstream inFile("sample_lines.txt");
    if (!inFile) {
        cout << "Error: File not found!" << endl;
        return 1;
    }

    string line;
    int lineCount = 0;

    while (getline(inFile, line)) {
        lineCount++;
    }

    inFile.close();
    cout << "Total number of lines in the file: " << lineCount << endl;

    return 0;
}
