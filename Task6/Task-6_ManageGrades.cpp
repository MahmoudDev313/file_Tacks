// Section 6 - Student Task
// 1) Create grades.txt and write five integer grades.
// 2) Read and print the grades.
// 3) Ask for a grade to delete and write all other grades to a temp file.
// 4) Replace the original file and report success or error.
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main() {
    // Step 1: create the file and write five grades.
    ofstream createFile("grades.txt");
    if (!createFile) {
        cerr << "Error: could not create grades.txt\n";
        return 1;
    }

    cout << "Enter five integer grades:\n";
    for (int i = 0; i < 5; ++i) {
        int grade;
        cout << "Grade " << i + 1 << ": ";
        if (!(cin >> grade)) {
            cerr << "Error: please enter integers only.\n";
            return 1;
        }
        createFile << grade << '\n';
    }
    createFile.close();

    // Step 2: read and display the grades.
    ifstream readFile("grades.txt");
    if (!readFile) {
        cerr << "Error: could not read grades.txt\n";
        return 1;
    }

    cout << "\nGrades before deletion:\n";
    int grade;
    while (readFile >> grade) {
        cout << grade << '\n';
    }
    if (!readFile.eof()) {
        cerr << "Error: invalid data in grades.txt\n";
        return 1;
    }
    readFile.close();

    // Step 3: copy every grade except the first matching value.
    int gradeToDelete;
    cout << "\nEnter the grade to delete: ";
    cin >> gradeToDelete;

    ifstream original("grades.txt");
    if (!original) {
        cerr << "Error: could not reopen grades.txt\n";
        return 1;
    }

    ofstream temp("grades_temp.txt");
    if (!temp) {
        cerr << "Error: could not create temporary file\n";
        return 1;
    }

    bool found = false;
    while (original >> grade) {
        if (grade == gradeToDelete && !found) {
            found = true; // Delete one occurrence only.
        } else {
            temp << grade << '\n';
        }
    }

    if (!original.eof()) {
        cerr << "Error: failed while reading grades.txt\n";
        original.close();
        temp.close();
        std::remove("grades_temp.txt");
        return 1;
    }

    original.close();
    temp.close();

    // Step 4: replace the original file.
    if (std::remove("grades.txt") != 0) {
        cerr << "Error: could not remove the original grades.txt\n";
        return 1;
    }

    if (std::rename("grades_temp.txt", "grades.txt") != 0) {
        cerr << "Error: could not rename the temporary file\n";
        return 1;
    }

    if (found) cout << "Success: grade deleted.\n";
    else cout << "The grade was not found; no grade was deleted.\n";

    cout << "\nGrades after deletion:\n";
    ifstream updated("grades.txt");
    if (!updated) {
        cerr << "Error: could not open updated grades.txt\n";
        return 1;
    }
    while (updated >> grade) cout << grade << '\n';
    updated.close();

    return 0;
}
