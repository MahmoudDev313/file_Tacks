// Section 2 - Task 2
// Read fruit.txt, display its contents, then append "Fresh Fruits".
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream input("fruit.txt");
    if (!input) {
        cerr << "Error: fruit.txt was not found.\n";
        return 1;
    }

    string line;
    cout << "Fruit list:\n";
    while (getline(input, line)) {
        cout << line << '\n';
    }
    input.close();

    ofstream output("fruit.txt", ios::app);
    if (!output) {
        cerr << "Error: cannot open fruit.txt for appending.\n";
        return 1;
    }

    output << "Fresh Fruits\n";
    output.close();

    cout << "Fresh Fruits was added to fruit.txt\n";
    return 0;
}
