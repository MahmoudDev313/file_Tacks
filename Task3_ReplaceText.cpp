#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    // First create the file with the required original sentence.
    {
        ofstream outFile("welcome.txt");
        if (!outFile) {
            cerr << "Error: Could not create welcome.txt\n";
            return 1;
        }
        outFile << "Hello Everybody";
    }

    // Read the complete file.
    ifstream inFile("welcome.txt");
    if (!inFile) {
        cerr << "Error: Could not open welcome.txt\n";
        return 1;
    }

    stringstream buffer;
    buffer << inFile.rdbuf();
    string content = buffer.str();
    inFile.close();

    // Replace "body" with "one".
    const string target = "body";
    const string replacement = "one";
    size_t position = content.find(target);

    if (position != string::npos) {
        content.replace(position, target.length(), replacement);
    }

    // Write the final result to the same file.
    ofstream outFile("welcome.txt");
    if (!outFile) {
        cerr << "Error: Could not write to welcome.txt\n";
        return 1;
    }
    outFile << content;
    outFile.close();

    cout << "Final content: " << content << '\n';
    return 0;
}
