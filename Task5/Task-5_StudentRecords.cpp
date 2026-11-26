// Section 5 - Task 5 (Lab 2)
// Append student records until the user enters 'n'.
// Record format: Name, ID, Grade, $
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    ofstream file("students.txt", ios::app);
    if (!file) {
        cerr << "Error: cannot open students.txt\n";
        return 1;
    }

    char again = 'y';

    while (again == 'y' || again == 'Y') {
        char name[20];
        int id;
        float grade;

        cout << "Enter student name (up to 19 characters): ";
        cin >> ws;
        cin.getline(name, 20);

        cout << "Enter student ID: ";
        cin >> id;

        cout << "Enter student grade: ";
        cin >> grade;

        file << name << ", " << id << ", "
             << fixed << setprecision(2) << grade << ", $\n";

        cout << "Add another record? (y/n): ";
        cin >> again;
    }

    file.close();
    cout << "Student records saved in students.txt\n";
    return 0;
}
