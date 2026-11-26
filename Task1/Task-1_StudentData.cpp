// Section 1 - Task 1
// Accept full name, ID, and grade; save them in Student.txt.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string name, id;
    double grade;

    cout << "Enter student's full name: ";
    getline(cin, name);

    cout << "Enter student ID: ";
    getline(cin, id);

    cout << "Enter student's grade: ";
    cin >> grade;

    ofstream file("Student.txt");
    if (!file) {
        cerr << "Error: cannot create Student.txt\n";
        return 1;
    }

    file << name << '\n' << id << '\n' << grade << '\n';
    file.close();

    cout << "Student data saved in Student.txt\n";
    return 0;
}
