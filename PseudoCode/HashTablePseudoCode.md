## MILESTONE TWO: HASH TABLE DATA STRUCTURE
---
The following pseudo code demonstrates the implementation of a hash table data structure to store and manage course information. The hash table is used to store Course objects, which contain information such as course number, title, and prerequisites. The pseudo code includes functions to load courses from a file, validate the format of each line, parse the line into a Course object, validate prerequisites, print all courses, and search for a specific course.

```
// Define Course Structure
STRUCTURE Course
   courseNumber: String
   title: String
   prerequisites: List of Strings
END STRUCTURE

// Function to load courses from a file into a hash table
FUNCTION LoadCoursesFromFile(filename)
   OPEN file named filename
   IF file does not exist THEN
       DISPLAY "Error: File not found"
       RETURN null
   END IF

   courses = new HashTable of Course
   WHILE not end of file DO
       line = READ line from file
       IF ValidateLine(line) THEN
           course = ParseLine(line)
           courses[course.courseNumber] = course
       ELSE
           DISPLAY "Invalid line format"
       END IF
   END WHILE
   CLOSE file
   ValidatePrerequisites(courses)
   RETURN courses
END FUNCTION

// Function to validate each line in the file
FUNCTION ValidateLine(line)
   parts = SPLIT line by commas
   IF size of parts < 2 THEN
       RETURN false
   ELSE
       RETURN true
   END IF
END FUNCTION

// Function to parse each line and create a Course object
FUNCTION ParseLine(line)
   parts = SPLIT line by commas
   course = new Course(parts[0], parts[1], new List of Strings)
   IF size of parts > 2 THEN
       FOR i FROM 2 TO size of parts
           course.prerequisites.add(parts[i])
       END FOR
   END IF
   RETURN course
END FUNCTION

// Function to validate prerequisites
FUNCTION ValidatePrerequisites(courses)
   courseNumbers = new Set of String
   FOR each key IN courses.keys() DO
       courseNumbers.add(key)
   END FOR

   FOR each key IN courses.keys() DO
       course = courses[key]
       FOR each prerequisite IN course.prerequisites DO
           IF NOT courseNumbers.contains(prerequisite) THEN
               DISPLAY "Prerequisite error for " + course.courseNumber + ": " + prerequisite
           END IF
       END FOR
   END FOR
END FUNCTION

// Function to print all courses alphanumerically
FUNCTION PrintAllCourses(courses)
   keys = SORT(courses.keys())
   FOR each key IN keys DO
       course = courses[key]
       DISPLAY course.courseNumber + ": " + course.title
   END FOR
END FUNCTION

// Function to search and display a specific course
FUNCTION SearchCourse(courses, courseNumber)
   IF courses.containsKey(courseNumber) THEN
       course = courses[courseNumber]
       DISPLAY "Course Number: " + course.courseNumber
       DISPLAY "Title: " + course.title
       IF NOT course.prerequisites.isEmpty() THEN
           DISPLAY "Prerequisites:"
           FOR each prerequisite IN course.prerequisites DO
               DISPLAY prerequisite
           END FOR
       ELSE
           DISPLAY "No prerequisites"
       END IF
   ELSE
       DISPLAY "Course not found"
   END IF
END FUNCTION

```