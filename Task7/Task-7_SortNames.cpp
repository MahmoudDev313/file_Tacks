// Section 7 - Task 7
// Sort the given student names in ascending (alphabetical) order.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> names = {
        "Hadeer Mahmoud",
        "Youssef Ali",
        "Ahmed Mostafa",
        "Esraa Ebrahim"
    };

    sort(names.begin(), names.end());

    cout << "Student names in ascending order:\n";
    for (const string& name : names) {
        cout << name << '\n';
    }

    return 0;
}
