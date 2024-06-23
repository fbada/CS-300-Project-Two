//============================================================================
// Name        : ProjectTwo.cpp
// Version     : 1.0
// Copyright   : Copyright © 2024 SNHU COCE
// Description : Project Two: Course Planner using Hash Table
//============================================================================

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <algorithm>
#include <limits>

// Define ANSI color codes
const std::string RESET = "\033[0m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string ORANGE = "\033[38;5;214m"; // ANSI code for orange

// Define Course Structure
struct Course {
    std::string courseNumber;
    std::string title;
    std::vector<std::string> prerequisites;
};

// Function to validate each line in the file
bool ValidateLine(const std::string& line) {
    std::stringstream ss(line);
    std::string item;
    int count = 0;
    while (std::getline(ss, item, ',')) {
        count++;
    }
    return count >= 2; // Ensure there are at least two elements (course number and title)
}

// Function to parse each line and create a Course object
Course ParseLine(const std::string& line) {
    std::stringstream ss(line);
    std::string item;
    Course course;
    std::getline(ss, course.courseNumber, ',');// Extract course number
    std::getline(ss, course.title, ','); // Extract course title
    while (std::getline(ss, item, ',')) {// Extract all prerequisites
        course.prerequisites.push_back(item);
    }
    return course;
}

// Function to load courses from a file into a hash table
std::unordered_map<std::string, Course> LoadCoursesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << ORANGE << "Error: File not found" << RESET << std::endl;
        return std::unordered_map<std::string, Course>();
    }

    std::unordered_map<std::string, Course> courses;
    std::string line;
    while (std::getline(file, line)) {
        if (ValidateLine(line)) {
            Course course = ParseLine(line);
            courses[course.courseNumber] = course; // Store course in map with course number as key
        } else {
            std::cerr << ORANGE << "Invalid line format: " << line << RESET << std::endl;
        }
    }
    file.close();
    return courses;
}

// Function to check if prerequisites are empty or contain only empty strings
bool PrerequisitesAreEmpty(const std::vector<std::string>& prerequisites) {
    return prerequisites.empty() || (prerequisites.size() == 1 && prerequisites[0].empty());
}

// Function to print all courses alphanumerically
void PrintAllCourses(const std::unordered_map<std::string, Course>& courses) {
    std::vector<std::string> keys;
    for (const auto& pair : courses) {
        keys.push_back(pair.first);
    }
    std::sort(keys.begin(), keys.end()); // Sort course numbers 
    std::cout << "\n" << CYAN << "======================================" << RESET << "\n";
    std::cout << BLUE << "      Sample Course Schedule          " << RESET << "\n";
    std::cout << CYAN << "======================================" << RESET << "\n";
    for (const std::string& key : keys) {
        const Course& course = courses.at(key);
        std::cout << GREEN << course.courseNumber << RESET << ", " << YELLOW << course.title << RESET << std::endl; // Print course number and title in green and yellow
        if (!PrerequisitesAreEmpty(course.prerequisites)) {
            std::cout << MAGENTA << "Prerequisites: " << RESET;
            for (const std::string& prerequisite : course.prerequisites) {
                std::cout << prerequisite;
                if (&prerequisite != &course.prerequisites.back()) {
                    std::cout << ", ";
                }
            }
            std::cout << std::endl;
        } else {
            std::cout << MAGENTA << "Prerequisites: NONE" << RESET << std::endl;
        }
    }
    std::cout << CYAN << "======================================" << RESET << "\n";
}

// Function to search and display a specific course
void SearchCourse(const std::unordered_map<std::string, Course>& courses, const std::string& courseNumber) {
    auto it = courses.find(courseNumber);
    if (it != courses.end()) {
        const Course& course = it->second;
        std::cout << "\n" << CYAN << "======================================" << RESET << "\n";
        std::cout << BLUE << "          Course Details              " << RESET << "\n";
        std::cout << CYAN << "======================================" << RESET << "\n";
        std::cout << GREEN << course.courseNumber << RESET << ", " << YELLOW << course.title << RESET << std::endl;
        if (!PrerequisitesAreEmpty(course.prerequisites)) {
            std::cout << MAGENTA << "Prerequisites: " << RESET;
            for (const std::string& prerequisite : course.prerequisites) {
                std::cout << prerequisite;
                if (&prerequisite != &course.prerequisites.back()) {
                    std::cout << ", ";
                }
            }
            std::cout << std::endl;
        } else {
            std::cout << MAGENTA << "Prerequisites: NONE" << RESET << std::endl;
        }
        std::cout << CYAN << "======================================" << RESET << "\n";
    } else {
        std::cout << ORANGE << "Course not found" << RESET << std::endl;
    }
}

// Function to load file data
void LoadFileData(std::unordered_map<std::string, Course>& courses) {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;
    courses = LoadCoursesFromFile(filename);
    if (courses.empty()) {
        std::cout << ORANGE << "Failed to load data. Please check the filename and try again." << RESET << std::endl;
    } else {
        std::cout << GREEN << "Course Data has been loaded." << RESET << std::endl;
    }
}

// Main menu function to provide user options in the course planner ranging from loading data to searching for a specific course, and exiting the program
void MainMenu() {
    std::unordered_map<std::string, Course> dataStructure;
    bool coursesLoaded = false;

    while (true) {
        std::cout << "\n" << CYAN << "======================================" << RESET << "\n";
        std::cout << BLUE << "              Main Menu               " << RESET << "\n";
        std::cout << CYAN << "======================================" << RESET << "\n";
        std::cout << CYAN << "1. Load Data Structure." << RESET << "\n";
        std::cout << CYAN << "2. Print Course List." << RESET << "\n";
        std::cout << CYAN << "3. Print Course." << RESET << "\n";
        std::cout << CYAN << "9. Exit" << RESET << "\n";
        std::cout << CYAN << "======================================" << RESET << "\n";
        std::cout << "What would you like to do? ";
        
        int choice;
        std::cin >> choice;

        // Flush the input buffer to avoid any leftover input issues
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (std::cin.fail() || choice < 1 || (choice > 3 && choice != 9)) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << ORANGE << "Invalid input. Please enter a valid option." << RESET << std::endl;
            continue;
        }

        switch (choice) {
            case 1:
            // Load data structure
                LoadFileData(dataStructure);
                coursesLoaded = true;
                break;
            case 2:
            // Print all courses
                if (coursesLoaded) {
                    PrintAllCourses(dataStructure);
                } else {
                    // If data is not loaded, prompt user to load data first
                    std::cout << ORANGE << "Please load the data first using option 1." << RESET << std::endl;
                }
                break;
            case 3:
            // Search for a specific course
                if (coursesLoaded) {
                    std::cout << "What course do you want to know about? (Enter the course code e.g. CSCI300) ";
                    std::string courseNumber;
                    std::cin >> courseNumber;
                    SearchCourse(dataStructure, courseNumber);
                } else {
                    // If data is not loaded, prompt user to load data first
                    std::cout << ORANGE << "Please load the data first using option 1." << RESET << std::endl;
                }
                break;
            case 9:
            // Exit the program
                std::cout << GREEN << "Thank you for using the course planner!" << RESET << std::endl;
                return;
            default:
            // Invalid option selected by the user 
                std::cout << ORANGE << choice << " is not a valid option." << RESET << std::endl;
        }
    }
}

// Main function
int main() {
    // Display welcome message and call the main menu function
    std::cout << BLUE << "Welcome to the course planner." << RESET << std::endl;
    MainMenu();
    return 0;
}