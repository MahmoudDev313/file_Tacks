// Section 4 - Task 4 (Lab 1)
// Save people (name and age), load them into a vector, and write
// the youngest and oldest people to results.txt.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

    ofstream peopleFile("persons.txt");
    if (!peopleFile) {
        cerr << "Error: cannot create persons.txt\n";
        return 1;
    }

    for (int i = 0; i < count; ++i) {
        Person person;
        cout << "\nPerson " << i + 1 << " name: ";
        getline(cin >> ws, person.name);
        cout << "Person " << i + 1 << " age: ";
        cin >> person.age;

        peopleFile << person.name << '|' << person.age << '\n';
    }
    peopleFile.close();

    ifstream input("persons.txt");
    if (!input) {
        cerr << "Error: cannot read persons.txt\n";
        return 1;
    }

    vector<Person> people;
    string line;
    while (getline(input, line)) {
        size_t separator = line.rfind('|');
        if (separator == string::npos) continue;

        Person person;
        person.name = line.substr(0, separator);
        try {
            person.age = stoi(line.substr(separator + 1));
            people.push_back(person);
        } catch (...) {
            cerr << "Warning: skipped an invalid record.\n";
        }
    }
    input.close();

    if (people.empty()) {
        cerr << "No valid people records were found.\n";
        return 1;
    }

    Person youngest = people[0];
    Person oldest = people[0];

    for (const Person& person : people) {
        if (person.age < youngest.age) youngest = person;
        if (person.age > oldest.age) oldest = person;
    }

    ofstream results("results.txt");
    if (!results) {
        cerr << "Error: cannot create results.txt\n";
        return 1;
    }

    results << "Youngest person: " << youngest.name
            << ", Age: " << youngest.age << '\n';
    results << "Oldest person: " << oldest.name
            << ", Age: " << oldest.age << '\n';
    results.close();

    cout << "Youngest: " << youngest.name << " (" << youngest.age << ")\n";
    cout << "Oldest: " << oldest.name << " (" << oldest.age << ")\n";
    cout << "Results saved in results.txt\n";
    return 0;
}
