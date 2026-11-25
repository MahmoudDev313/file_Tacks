#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("fruit.txt");
    if (!inFile) {
        cerr << "Error: Could not open fruit.txt\n";
        return 1;
    }

    string line;
    cout << "Contents of fruit.txt:\n";
    while (getline(inFile, line)) {
        cout << line << '\n';
    }
    inFile.close();

    ofstream outFile("fruit.txt", ios::app);
    if (!outFile) {
        cerr << "Error: Could not open fruit.txt for writing\n";
        return 1;
    }

    outFile << "Fresh Fruits\n";
    outFile.close();

    cout << "Fresh Fruits has been added to fruit.txt\n";
    return 0;
}
