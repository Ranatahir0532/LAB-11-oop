// Topic 2 Exercise: Read a file containing 10 numbers, display only even numbers
// NOTE: First run this program — it creates the numbers file, then reads and filters it.

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Step 1: Create a sample file with 10 numbers
    ofstream writeFile("numbers.txt");
    if (!writeFile) {
        cout << "Error: Could not create numbers.txt!" << endl;
        return 1;
    }
    int sampleNumbers[10] = {3, 8, 15, 22, 7, 44, 19, 36, 11, 50};
    for (int i = 0; i < 10; i++) {
        writeFile << sampleNumbers[i] << endl;
    }
    writeFile.close();
    cout << "numbers.txt created with 10 sample numbers." << endl;

    // Step 2: Read the file and display only even numbers
    ifstream inFile("numbers.txt");
    if (!inFile) {
        cout << "Error: File not found!" << endl;
        return 1;
    }

    int num;
    cout << "\nEven numbers from the file:" << endl;
    while (inFile >> num) {
        if (num % 2 == 0) {
            cout << num << endl;
        }
    }

    inFile.close();
    return 0;
}
