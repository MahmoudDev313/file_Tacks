// Section 3 - Task 3
// Write "Hello Everybody" to welcome.txt, replace "body" with "one",
// then save "Hello Everyone" in the same file.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    {
        ofstream createFile("welcome.txt");
        if (!createFile) {
            cerr << "Error: cannot create welcome.txt\n";
            return 1;
        }
        createFile << "Hello Everybody";
    }

    fstream file("welcome.txt", ios::in | ios::out);
    if (!file) {
        cerr << "Error: cannot open welcome.txt\n";
        return 1;
    }

    string content;
    getline(file, content);

    size_t position = content.find("body");
    if (position == string::npos) {
        cerr << "Error: the word 'body' was not found.\n";
        return 1;
    }

    content.replace(position, 4, "one");

    // Rewind and rewrite the file so the shorter result removes old trailing bytes.
    file.clear();
    file.seekp(0, ios::beg);
    file.close();

    ofstream rewriteFile("welcome.txt", ios::trunc);
    if (!rewriteFile) {
        cerr << "Error: cannot rewrite welcome.txt\n";
        return 1;
    }
    rewriteFile << content;
    rewriteFile.close();

    cout << "Final text: " << content << '\n';
    return 0;
}
