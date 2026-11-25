#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ofstream outFile("students.txt", ios::app);
    if (!outFile) {
        cerr << "Error: Could not open students.txt\n";
        return 1;
    }

    char name[20];
    int id;
    float grade;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        cout << "Enter student name (maximum 19 characters): ";
        cin >> ws;
        cin.getline(name, 20);

        cout << "Enter student ID: ";
        cin >> id;

        cout << "Enter student grade: ";
        cin >> grade;

        // Record format: Name, ID, Grade, $
        outFile << name << ", " << id << ", "
                << fixed << setprecision(2) << grade << "$\n";

        cout << "Do you want to add another record? (y/n): ";
        cin >> choice;
    }

    outFile.close();
    cout << "Student records saved in students.txt\n";
    return 0;
}
