# C++ File Handling Tasks

This repository contains the six tasks shown in the assignment slides: Tasks 1, 2, 3, 4, 5, and 7. There was no Task 6 in the supplied material.

## Requirements
- C++ compiler supporting C++11 or later.
- Compile each `.cpp` file separately because each file has its own `main()` function.

## Compile and run
Example using g++:

```bash
g++ -std=c++17 Task1_StudentData.cpp -o task1
./task1
```

Repeat with the required source file for each task.

## Tasks
1. Read a student's full name, ID, and grade, then save them in `Student.txt`.
2. Read and display the contents of `fruit.txt`, then append `Fresh Fruits` to the same file.
3. Create `welcome.txt` containing `Hello Everybody`, replace `body` with `one`, and save `Hello Everyone` in the same file.
4. Save people (name and age) to `persons.txt`, load them into a vector, and write the youngest and oldest person(s) to `results.txt`.
5. Append student records to `students.txt` in the format `Name, ID, Grade$`, continuing while the user enters `y`.
7. Sort the four names from the assignment slide in ascending alphabetical order.

## Notes
- Run Task 2 from the repository folder so it can find `fruit.txt`.
- Task 4 writes `persons.txt` and `results.txt` in the program's working directory.
- Task 5 appends records to `students.txt`; delete the file if you want to start with an empty records file.
