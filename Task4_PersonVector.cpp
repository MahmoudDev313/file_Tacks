#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    int count;
    cout << "How many persons do you want to add? ";
    cin >> count;

    if (count <= 0) {
        cerr << "Please enter a positive number.\n";
        return 1;
    }

    vector<Person> persons;
    ofstream outFile("persons.txt");
    if (!outFile) {
        cerr << "Error: Could not create persons.txt\n";
        return 1;
    }

    for (int i = 0; i < count; ++i) {
        Person p;
        cout << "Enter person " << i + 1 << " name: ";
        getline(cin >> ws, p.name);
        cout << "Enter person " << i + 1 << " age: ";
        cin >> p.age;

        persons.push_back(p);
        outFile << p.name << '\n' << p.age << '\n';
    }
    outFile.close();

    // Load all persons from the file into a vector.
    vector<Person> loadedPersons;
    ifstream inFile("persons.txt");
    if (!inFile) {
        cerr << "Error: Could not read persons.txt\n";
        return 1;
    }

    Person p;
    while (getline(inFile, p.name)) {
        if (!(inFile >> p.age)) break;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
        loadedPersons.push_back(p);
    }
    inFile.close();

    if (loadedPersons.empty()) {
        cerr << "No person records were loaded.\n";
        return 1;
    }

    int youngestAge = loadedPersons[0].age;
    int oldestAge = loadedPersons[0].age;

    for (const Person& person : loadedPersons) {
        if (person.age < youngestAge) youngestAge = person.age;
        if (person.age > oldestAge) oldestAge = person.age;
    }

    ofstream results("results.txt");
    if (!results) {
        cerr << "Error: Could not create results.txt\n";
        return 1;
    }

    results << "Youngest person(s):\n";
    for (const Person& person : loadedPersons) {
        if (person.age == youngestAge)
            results << person.name << ", Age: " << person.age << '\n';
    }

    results << "\nOldest person(s):\n";
    for (const Person& person : loadedPersons) {
        if (person.age == oldestAge)
            results << person.name << ", Age: " << person.age << '\n';
    }
    results.close();

    cout << "Persons saved in persons.txt\n";
    cout << "Youngest and oldest persons saved in results.txt\n";
    return 0;
}
