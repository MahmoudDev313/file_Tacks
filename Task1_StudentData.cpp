#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string fullName;
    int id;
    float grade;

    cout << "Enter student's full name: ";
    getline(cin, fullName);

    cout << "Enter student ID: ";
    cin >> id;

    cout << "Enter student grade: ";
    cin >> grade;

    ofstream outFile("Student.txt");
    if (!outFile) {
        cerr << "Error: Could not create Student.txt\n";
        return 1;
    }

    outFile << "Full Name: " << fullName << '\n';
    outFile << "ID: " << id << '\n';
    outFile << "Grade: " << grade << '\n';
    outFile.close();

    cout << "Student data saved successfully in Student.txt\n";
    return 0;
}
