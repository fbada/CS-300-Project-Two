

# 🎓 Course Planner

## Overview
The **Course Planner** application is a command-line interface (CLI) tool designed to assist academic advisors in managing and viewing course data for a Computer Science program. It allows users to:
- 📂 Load course data from a CSV file.
- 📑 Display an alphanumerically ordered list of all courses.
- 🔍 Print detailed information about specific courses, including their prerequisites.

## Features
- **Load Course Data**: Easily load course information from a CSV file.
- **View All Courses**: Display a neatly formatted, alphanumerically ordered list of all courses.
- **Course Details**: Retrieve and display detailed information about individual courses and their prerequisites.
- **User-Friendly Interface**: Enjoy a visually appealing, color-coded command-line interface.

## Prerequisites
- **C++14 or later**
- **A C++ compiler** (e.g., g++)

## How to Use

### 📥 Load Data Structure
1. Enter `1` to load course data from a CSV file.
2. Provide the filename when prompted (e.g., `ABCU_Advising_Program_Input.csv`).

### 📜 Print Course List
1. Enter `2` to display an alphanumerically ordered list of courses.

### 🔎 Print Course
1. Enter `3` and provide a course number to see detailed information about the course and its prerequisites.

### 🚪 Exit
 Enter `9` to exit the application.

## Sample Output
```sh
Welcome to the course planner.

======================================
              Main Menu               
======================================
1. Load Data Structure.
2. Print Course List.
3. Print Course.
9. Exit
======================================
What would you like to do? 1
Enter the filename: ABCU_Advising_Program_Input.csv
Course Data has been loaded.

======================================
              Main Menu               
======================================
1. Load Data Structure.
2. Print Course List.
3. Print Course.
9. Exit
======================================
What would you like to do? 2

======================================
      Sample Course Schedule          
======================================
CSCI100, Introduction to Computer Science
Prerequisites: , 
CSCI101, Introduction to Programming in C++
Prerequisites: CSCI100, 
CSCI200, Data Structures
Prerequisites: CSCI101, 
CSCI300, Introduction to Algorithms
Prerequisites: CSCI200, MATH201
CSCI301, Advanced Programming in C++
Prerequisites: CSCI101, 
CSCI350, Operating Systems
Prerequisites: CSCI300, 
CSCI400, Large Software Development
Prerequisites: CSCI301, CSCI350
MATH201, Discrete Mathematics
Prerequisites: , 
======================================

======================================
              Main Menu               
======================================
1. Load Data Structure.
2. Print Course List.
3. Print Course.
9. Exit
======================================
What would you like to do? 3
What course do you want to know about? CSCI400

======================================
          Course Details              
======================================
CSCI400, Large Software Development
Prerequisites: CSCI301, CSCI350
======================================
```

## Compilation and Execution

### Compile the Main Program
To compile the main application, use the following command:
```sh
g++ -std=c++14 -o course_planner ProjectTwo.cpp
```

### Run the Main Program
To run the compiled application, use the following command:
```sh
./course_planner
```
## Project Structure
- `ProjectTwo.cpp`: Main application code.
- `ABCU_Advising_Program_Input.csv`: Sample input file containing course data.

## Additional Information
- **Color Coding**: The CLI uses color coding to enhance readability:
  - **Green**: Course numbers.
  - **Yellow**: Course titles.
  - **Magenta**: Prerequisites.
  - **Cyan**: Section headers and dividers.
  - **Orange**: Error messages and warnings.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


