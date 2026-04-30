## Topic 1 — Writing to a File

### Exercise · Store user name and age

**File:** `topic1_exercise_name_age.cpp`  
Uses `ofstream` to create a file and write user-provided name & age.

```
$ ./topic1_exercise_name_age
Enter your name: Alice
Enter your age: 25
Data successfully written to user_info.txt

$ cat user_info.txt
Name: Alice
Age: 25
```

---

### Task · Append data using `ios::app`

**File:** `topic1_task_append.cpp`  
Opens the file with `ios::app` so each run adds a new entry instead of erasing previous data.

```
$ ./topic1_task_append
Enter your name: Bob
Enter your age: 30
Data appended successfully to user_info_append.txt

$ ./topic1_task_append
Enter your name: Carol
Enter your age: 22
Data appended successfully to user_info_append.txt

$ cat user_info_append.txt
Name: Bob  |  Age: 30
Name: Carol  |  Age: 22
```

---

## Topic 2 — Reading from a File

### Exercise · Read 10 numbers, display only even ones

**File:** `topic2_exercise_even_numbers.cpp`  
Creates `numbers.txt` with 10 values, reads it back and filters even numbers using the modulus operator.

```
$ ./topic2_exercise_even_numbers
numbers.txt created with 10 sample numbers.

Even numbers from the file:
8
22
44
36
50
```

---

### Task · Count number of lines in a file

**File:** `topic2_task_count_lines.cpp`  
Uses `getline()` in a loop, incrementing a counter on each iteration.

```
$ ./topic2_task_count_lines
sample_lines.txt created.
Total number of lines in the file: 5
```

---

## Topic 3 — File Handling with OOP

### Exercise · Store 5 student records using a class

**File:** `topic3_exercise_5_students.cpp`  
`Student` class with a `writeToFile()` method — each object serialises itself to `students.txt`.

```
$ ./topic3_exercise_5_students
=== Enter details for 5 students ===

--- Student 1 ---
Enter ID: 101  Enter Name: Alice  Enter GPA: 3.8
Record saved.
--- Student 2 ---
Enter ID: 102  Enter Name: Bob  Enter GPA: 3.5
Record saved.
--- Student 3 ---
Enter ID: 103  Enter Name: Carol  Enter GPA: 3.9
Record saved.
--- Student 4 ---
Enter ID: 104  Enter Name: David  Enter GPA: 2.8
Record saved.
--- Student 5 ---
Enter ID: 105  Enter Name: Eve  Enter GPA: 3.1
Record saved.

All 5 student records saved to students.txt successfully!
```

---

### Task · Add `displayAllFromFile()` — menu-driven program

**File:** `topic3_task_display_all_students.cpp`  
Static method reads every record from file and prints it; interactive menu loops until exit.

```
$ ./topic3_task_display_all_students
--- Menu ---
1. Add Student
2. Display All Students
3. Exit
Enter choice: 1
Enter ID: 201  Enter Name: Zara  Enter GPA: 3.7
Student saved!

Enter choice: 1
Enter ID: 202  Enter Name: Ahmed  Enter GPA: 3.2
Student saved!

Enter choice: 2
===== All Student Records =====
Record 1: ID=201  Name=Zara  GPA=3.7
Record 2: ID=202  Name=Ahmed  GPA=3.2
Total records: 2

Enter choice: 3
```

---

## Topic 4 — Binary File Handling

### Exercise · Store multiple Student objects in binary file

**File:** `topic4_exercise_binary_write_multiple.cpp`  
Uses `file.write((char*)&s, sizeof(Student))` to store the raw memory of each object.

```
$ ./topic4_exercise_binary_write_multiple
=== Enter details for 3 students ===

--- Student 1 ---
Enter ID: 1  Enter Name: Ali  Enter GPA: 3.5
--- Student 2 ---
Enter ID: 2  Enter Name: Sara  Enter GPA: 3.8
--- Student 3 ---
Enter ID: 3  Enter Name: Umar  Enter GPA: 2.9

3 student records written to students_binary.dat successfully!
```

---

### Task · Read and display all objects from binary file

**File:** `topic4_task_binary_read_all.cpp`  
Uses `file.read((char*)&s, sizeof(Student))` in a loop to reconstruct objects from the `.dat` file.

```
$ ./topic4_task_binary_read_all
===== Reading All Records from Binary File =====

Record 1:
  ID   : 1
  Name : Ali
  GPA  : 3.5

Record 2:
  ID   : 2
  Name : Sara
  GPA  : 3.8

Record 3:
  ID   : 3
  Name : Umar
  GPA  : 2.9

Total records read: 3
```

---

## Topic 5 — Exception Handling in File Operations

### Exercise · Handle file opening errors with `try/catch`

**File:** `topic5_exercise_file_error_handling.cpp`  
Throws `runtime_error` when a file can't be opened — demonstrates both the success and error paths.

**✅ File exists:**
```
$ ./topic5_exercise_file_error_handling
Enter filename to open: testfile.txt
File opened successfully! Contents:
-------------------------------------
Welcome to File Handling
This is line two.
-------------------------------------
File read and closed successfully.
```

**❌ File missing:**
```
$ ./topic5_exercise_file_error_handling
Enter filename to open: ghost.txt
Exception caught: Error: File 'ghost.txt' does not exist or cannot be opened!
Please make sure the file exists and try again.
```

---

### Task · Combine file handling + exception handling

**File:** `topic5_task_file_plus_exception.cpp`  
Full menu: write, read, and trigger a missing-file exception — all wrapped in `try/catch` blocks.

```
$ ./topic5_task_file_plus_exception
--- File Handling + Exception Handling Menu ---
1. Write data to file
2. Read data from file
3. Try reading a non-existent file
4. Exit
Enter choice: 1
Enter data to write: Hello from file handling!
Data written successfully to combined_data.txt

Enter choice: 2
--- Contents of combined_data.txt ---
1: Hello from file handling!

Enter choice: 3
Read Exception: Error: File 'this_file_does_not_exist.txt' not found!

Enter choice: 4
```

---

## 🏁 Final Task — Student Management System

**File:** `final_task_student_management_system.cpp`  
Full CRUD-style system: add records to file, view all, search by ID. Exception-safe throughout.

```
$ ./final_task_student_management_system
========================================
   Student Management System (C++)
========================================

--- Main Menu ---
1. Add Student
2. View All Students
3. Search Student by ID
4. Exit
Enter choice: 1
Enter Student ID   : 301
Enter Student Name : Aisha
Enter Student GPA  : 3.9
Student record added successfully!

Enter choice: 1
Enter Student ID   : 302
Enter Student Name : Hamza
Enter Student GPA  : 3.4
Student record added successfully!

Enter choice: 1
Enter Student ID   : 303
Enter Student Name : Sana
Enter Student GPA  : 2.7
Student record added successfully!

Enter choice: 2
========== All Student Records ==========

Record #1:
  ID   : 301
  Name : Aisha
  GPA  : 3.9

Record #2:
  ID   : 302
  Name : Hamza
  GPA  : 3.4

Record #3:
  ID   : 303
  Name : Sana
  GPA  : 2.7

Total students: 3

Enter choice: 3
Enter Student ID to search: 302
Student found!
  ID   : 302
  Name : Hamza
  GPA  : 3.4

Enter choice: 4
Exiting program. Goodbye!
```

---
*Compiled and tested with `g++` (C++17) on Ubuntu.*
