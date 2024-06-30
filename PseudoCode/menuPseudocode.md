##	PSEUDOCODE FOR THE MENU

This is the pseudocode for the menu that will be displayed to the user. The menu will allow the user to load the data from a file into a data structure, print an alphanumerically ordered list of all the courses in the Computer Science department, print the course title and prerequisites for any individual course, and exit the program.


---
```
FUNCTION mainMenu()
    dataStructure = null
    coursesLoaded = false

    WHILE true DO
        DISPLAY "Menu:"
        DISPLAY "1. Load the file data into the data structure"
        DISPLAY "2. Print an alphanumerically ordered list of all the courses in the Computer Science department"
        DISPLAY "3. Print the course title and the prerequisites for any individual course"
        DISPLAY "9. Exit the program"
        INPUT choice

        SWITCH choice DO
            CASE 1:
                CALL loadFileData()
                coursesLoaded = true
                DISPLAY "Data loaded successfully."
                BREAK

            CASE 2:
                IF coursesLoaded THEN
                    CALL printAllCourses(dataStructure)
                ELSE
                    DISPLAY "Please load the data first using option 1."
                END IF
                BREAK

            CASE 3:
                IF coursesLoaded THEN
                    DISPLAY "Enter the course number:"
                    INPUT courseNumber
                    CALL searchCourse(dataStructure, courseNumber)
                ELSE
                    DISPLAY "Please load the data first using option 1."
                END IF
                BREAK

            CASE 9:
                DISPLAY "Exiting the program."
                EXIT WHILE

            DEFAULT:
                DISPLAY "Invalid option. Please choose a valid option."
        END SWITCH
    END WHILE
END FUNCTION

FUNCTION loadFileData()
    DISPLAY "Enter the filename:"
    INPUT filename
    dataStructure = LoadCoursesFromFile(filename)
    IF dataStructure IS null THEN
        DISPLAY "Failed to load data. Please check the filename and try again."
    END IF
END FUNCTION

FUNCTION printAllCourses(dataStructure)
    IF dataStructure IS Vector THEN
        CALL PrintAllCourses(dataStructure)
    ELSEIF dataStructure IS HashTable THEN
        CALL PrintAllCourses(dataStructure)
    ELSEIF dataStructure IS BinarySearchTree THEN
        CALL PrintAllCourses(dataStructure)
    END IF
END FUNCTION

FUNCTION searchCourse(dataStructure, courseNumber)
    IF dataStructure IS Vector THEN
        CALL SearchCourse(dataStructure, courseNumber)
    ELSEIF dataStructure IS HashTable THEN
        CALL SearchCourse(dataStructure, courseNumber)
    ELSEIF dataStructure IS BinarySearchTree THEN
        CALL SearchCourse(dataStructure, courseNumber)
    END IF
END FUNCTION
```











